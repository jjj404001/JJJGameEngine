#include "Graphics.h"
#include <iostream>
#include <cassert>


void Graphics::Initialize()
{
	
	wglSwapIntervalEXT(true);


	const auto version = reinterpret_cast<const char*>(glGetString(GL_VERSION));
	std::cout << version << std::endl;


	Tesselation_geometry_white_shader_.push_back(Shader::LoadShader(Shader::VertexShader, "Shader/Triangle_Vertex.glsl"));
	Tesselation_geometry_white_shader_.push_back(Shader::LoadShader(Shader::TessellationControl, "Shader/tessellation_control.glsl"));
	Tesselation_geometry_white_shader_.push_back(Shader::LoadShader(Shader::TessellationEvaluation, "Shader/tessellation_evalution.glsl"));
	Tesselation_geometry_white_shader_.push_back(Shader::LoadShader(Shader::Geometry, "Shader/Geometry_Tri_to_point.glsl"));
	Tesselation_geometry_white_shader_.push_back(Shader::LoadShader(Shader::FragmentShader, "Shader/Triangle_Fragment.glsl"));
	CompileShaders(Tesselation_geometry_white_shader_);


	Tesselation_white_shader_.push_back(Shader::LoadShader(Shader::VertexShader, "Shader/Triangle_Vertex.glsl"));
	Tesselation_white_shader_.push_back(Shader::LoadShader(Shader::TessellationControl, "Shader/tessellation_control.glsl"));
	Tesselation_white_shader_.push_back(Shader::LoadShader(Shader::TessellationEvaluation, "Shader/tessellation_evalution.glsl"));
	Tesselation_white_shader_.push_back(Shader::LoadShader(Shader::FragmentShader, "Shader/Triangle_Fragment.glsl"));
	CompileShaders(Tesselation_white_shader_);


	vertex_fragment_.push_back(Shader::LoadShader(Shader::VertexShader, "Shader/Triangle_Vertex.glsl"));
	vertex_fragment_.push_back(Shader::LoadShader(Shader::FragmentShader, "Shader/Triangle_Fragment.glsl"));
	CompileShaders(vertex_fragment_);


	
	testMesh.debug_triangle();
	

	testMesh.Initialize_VAO_VBO();
	
	// Pixel size
	glPointSize(5.0f);


	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// Set shader program
	glUseProgram(vertex_fragment_.GetProgram());


	

}

void Graphics::Update()
{
	//glDrawArrays(primitive_, 0, number_of_vert_);
	glDrawElements(testMesh.Get_Primitive(), testMesh.Get_NumOfVertices(), GL_UNSIGNED_INT, 0);
}

void Graphics::Free() const
{
	glDeleteShader(Tesselation_geometry_white_shader_.GetProgram());
}

void Graphics::CompileShaders(ShaderCollection& input_shader_collection) const
{
	// Create program.
	input_shader_collection.program_ = glCreateProgram();

	for(auto current_shader : input_shader_collection)
	{
		switch (current_shader.type)
		{
			case Shader::VertexShader:
				current_shader.shader_ = glCreateShader(GL_VERTEX_SHADER);
				break;
			case Shader::TessellationControl:
				current_shader.shader_ = glCreateShader(GL_TESS_CONTROL_SHADER);
				break;
			case Shader::TessellationEvaluation:
				current_shader.shader_ = glCreateShader(GL_TESS_EVALUATION_SHADER);
				break;
			case Shader::Geometry:
				current_shader.shader_ = glCreateShader(GL_GEOMETRY_SHADER);
				break;
			case Shader::FragmentShader:
				current_shader.shader_ = glCreateShader(GL_FRAGMENT_SHADER);
				break;
			default:
				assert(!"Undefined shader type");
		}

		const GLchar* shader_source[] = { current_shader.shader_source_ };

		glShaderSource(current_shader.shader_, 1, shader_source, nullptr);
		glCompileShader(current_shader.shader_);


		int  success;
		char infoLog[512];
		glGetShaderiv(current_shader.shader_, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(current_shader.shader_, 512, nullptr, infoLog);
			std::cout << "Error!! shader compile failed. : \n" << infoLog << std::endl;
		}


		// Attach shaders
		glAttachShader(input_shader_collection.program_, current_shader.shader_);
	}




	// Link program
	glLinkProgram(input_shader_collection.program_);

	for (const auto current_shader : input_shader_collection)
		glDeleteShader(current_shader.shader_);
}
