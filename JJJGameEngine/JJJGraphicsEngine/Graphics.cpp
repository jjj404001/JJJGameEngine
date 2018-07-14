#include "Graphics.h"
#include <iostream>
#include <cassert>
#include "OpenGL_functions.h"
#include "Mesh.h"
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


	SimpeVF.push_back(Shader::LoadShader(Shader::VertexShader, "Shader/Triangle_Vertex.glsl"));
	SimpeVF.push_back(Shader::LoadShader(Shader::FragmentShader, "Shader/Triangle_Fragment.glsl"));
	CompileShaders(SimpeVF);


	Mesh mesh;
	mesh.debug_triangle();
	

	mesh.Initialize_VAO_VBO();
	
	// Pixel size
	glPointSize(5.0f);
}

void Graphics::Update()
{
	glUseProgram(Tesselation_white_shader_.GetProgram());

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//for tessellation
	glDrawArrays(GL_PATCHES, 0, 3);
	//for triangle
	//glDrawArrays(GL_TRIANGLES, 0, 3);
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
