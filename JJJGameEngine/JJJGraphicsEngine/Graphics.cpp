#include "Graphics.h"
#include <iostream>
#include <cassert>

void Graphics::Initialize()
{
	
	opengl_functions_.wglSwapIntervalEXT(true);


	const auto version = reinterpret_cast<const char*>(glGetString(GL_VERSION));
	std::cout << version << std::endl;


	Tesselation_geometry_white_shader_.push_back(Shader::LoadShader(Shader::VertexShader, "Shader/Triangle_Vertex.glsl"));
	Tesselation_geometry_white_shader_.push_back(Shader::LoadShader(Shader::TessellationControl, "Shader/tessellation_control.glsl"));
	Tesselation_geometry_white_shader_.push_back(Shader::LoadShader(Shader::TessellationEvaluation, "Shader/tessellation_evalution.glsl"));
	Tesselation_geometry_white_shader_.push_back(Shader::LoadShader(Shader::Geometry, "Shader/Geometry_Tri_to_point.glsl"));
	Tesselation_geometry_white_shader_.push_back(Shader::LoadShader(Shader::FragmentShader, "Shader/Triangle_Fragment.glsl"));
	CompileShaders(Tesselation_geometry_white_shader_);

	GLuint VAO;
	opengl_functions_.glGenVertexArrays(1, &VAO);
	opengl_functions_.glBindVertexArray(VAO);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// Pixel size
	glPointSize(5.0f);
}

void Graphics::Update()
{
	opengl_functions_.glUseProgram(Tesselation_geometry_white_shader_.GetProgram());

	//for tessellation
	glDrawArrays(GL_PATCHES, 0, 3);
	//for triangle
	//glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Graphics::Free() const
{
	opengl_functions_.glDeleteShader(Tesselation_geometry_white_shader_.GetProgram());
}

void Graphics::CompileShaders(ShaderCollection& input_shader_collection) const
{
	// Create program.
	input_shader_collection.program_ = opengl_functions_.glCreateProgram();

	for(auto current_shader : input_shader_collection)
	{
		switch (current_shader.type)
		{
			case Shader::VertexShader:
				current_shader.shader_ = opengl_functions_.glCreateShader(GL_VERTEX_SHADER);
				break;
			case Shader::TessellationControl:
				current_shader.shader_ = opengl_functions_.glCreateShader(GL_TESS_CONTROL_SHADER);
				break;
			case Shader::TessellationEvaluation:
				current_shader.shader_ = opengl_functions_.glCreateShader(GL_TESS_EVALUATION_SHADER);
				break;
			case Shader::Geometry:
				current_shader.shader_ = opengl_functions_.glCreateShader(GL_GEOMETRY_SHADER);
				break;
			case Shader::FragmentShader:
				current_shader.shader_ = opengl_functions_.glCreateShader(GL_FRAGMENT_SHADER);
				break;
			default:
				assert(!"Undefined shader type");
		}

		const GLchar* shader_source[] = { current_shader.shader_source_ };

		opengl_functions_.glShaderSource(current_shader.shader_, 1, shader_source, nullptr);
		opengl_functions_.glCompileShader(current_shader.shader_);


		int  success;
		char infoLog[512];
		opengl_functions_.glGetShaderiv(current_shader.shader_, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			opengl_functions_.glGetShaderInfoLog(current_shader.shader_, 512, nullptr, infoLog);
			std::cout << "Error!! shader compile failed. : \n" << infoLog << std::endl;
		}


		// Attach shaders
		opengl_functions_.glAttachShader(input_shader_collection.program_, current_shader.shader_);
	}




	// Link program
	opengl_functions_.glLinkProgram(input_shader_collection.program_);

	for (const auto current_shader : input_shader_collection)
		opengl_functions_.glDeleteShader(current_shader.shader_);
}
