#include "Graphics.h"
#include <iostream>

void Graphics::Initialize()
{
	
	opengl_functions_.wglSwapIntervalEXT(true);


	const auto version = reinterpret_cast<const char*>(glGetString(GL_VERSION));
	std::cout << version << std::endl;

	shader_map_.LoadShader("First shader","Shader/FirstVertex.glsl", "Shader/FirstFragment.glsl");
	CompileShader(shader_map_.find("First shader"));

	shader_map_.LoadShader("Triangle shader", "Shader/Triangle_Vertex.glsl", "Shader/Triangle_Fragment.glsl");
	CompileShader(shader_map_.find("Triangle shader"));

	shader_map_.LoadShader("Tesselation triangle", "Shader/Triangle_Vertex.glsl", "Shader/Tesselation_control.glsl", "Shader/Tesselation_evalution.glsl", "Shader/Triangle_Fragment.glsl");
	CompileShader(shader_map_.find("Tesselation triangle"));

	GLuint VAO;
	opengl_functions_.glGenVertexArrays(1, &VAO);
	opengl_functions_.glBindVertexArray(VAO);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// Pixel size
	glPointSize(5.0f);
}

void Graphics::Update()
{
	opengl_functions_.glUseProgram(shader_map_.find("Tesselation triangle")->program_);

	//for tesselation
	glDrawArrays(GL_PATCHES, 0, 3);
	//for triangle
	//glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Graphics::Free()
{
	opengl_functions_.glDeleteShader(shader_map_.find("First shader")->program_);
	opengl_functions_.glDeleteShader(shader_map_.find("Triangle shader")->program_);
}

void Graphics::CompileShader(Shader* input_shader)
{
	const GLchar* vertex_shader_source[] = {input_shader->vertex_shader_source_};
	const GLchar* tessellation_control_shader_source[] = {input_shader->tesselation_control_shader_source_};
	const GLchar* tessellation_evaluation_shader_source[] = {input_shader->tesselation_evaluation_shader_source_};
	const GLchar* fragment_shader_source[] = {input_shader->fragment_shader_source_};

	// Create program.
	input_shader->program_ = opengl_functions_.glCreateProgram();



	// Compile vertex shader
	if (input_shader->vertex_shader_source_ != nullptr)
	{
		input_shader->vertex_shader_ = opengl_functions_.glCreateShader(GL_VERTEX_SHADER);
		opengl_functions_.glShaderSource(input_shader->vertex_shader_, 1, vertex_shader_source, nullptr);
		opengl_functions_.glCompileShader(input_shader->vertex_shader_);

		int  success;
		char infoLog[512];
		opengl_functions_.glGetShaderiv(input_shader->vertex_shader_, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			opengl_functions_.glGetShaderInfoLog(input_shader->vertex_shader_, 512, nullptr, infoLog);
			std::cout << "Error!! Vertex shader compile failed. : \n" << infoLog << std::endl;
		}

		// Attach shaders
		opengl_functions_.glAttachShader(input_shader->program_, input_shader->vertex_shader_);
	}

	// Compile tessellation control shader
	if (input_shader->tesselation_control_shader_source_ != nullptr)
	{
		input_shader->tesselation_control_shader_ = opengl_functions_.glCreateShader(GL_TESS_CONTROL_SHADER);
		opengl_functions_.glShaderSource(input_shader->tesselation_control_shader_, 1, tessellation_control_shader_source, nullptr);
		opengl_functions_.glCompileShader(input_shader->tesselation_control_shader_);

		int  success;
		char infoLog[512];
		opengl_functions_.glGetShaderiv(input_shader->tesselation_control_shader_, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			opengl_functions_.glGetShaderInfoLog(input_shader->tesselation_control_shader_, 512, nullptr, infoLog);
			std::cout << "Error!! Tesselation control shader compile failed. : \n" << infoLog << std::endl;
		}

		// Attach shaders
		opengl_functions_.glAttachShader(input_shader->program_, input_shader->tesselation_control_shader_);
	}

	// Compile tessellation evaluation shader
	if (input_shader->tesselation_evaluation_shader_source_ != nullptr)
	{
		input_shader->tesselation_evaluation_shader_ = opengl_functions_.glCreateShader(GL_TESS_EVALUATION_SHADER);
		opengl_functions_.glShaderSource(input_shader->tesselation_evaluation_shader_, 1, tessellation_evaluation_shader_source, nullptr);
		opengl_functions_.glCompileShader(input_shader->tesselation_evaluation_shader_);

		int  success;
		char infoLog[512];
		opengl_functions_.glGetShaderiv(input_shader->tesselation_evaluation_shader_, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			opengl_functions_.glGetShaderInfoLog(input_shader->tesselation_evaluation_shader_, 512, nullptr, infoLog);
			std::cout << "Error!! Tesselation evaluation shader compile failed. : \n" << infoLog << std::endl;
		}

		// Attach shaders
		opengl_functions_.glAttachShader(input_shader->program_, input_shader->tesselation_evaluation_shader_);
	}


	// Compile fragment shader
	if (input_shader->fragment_shader_source_ != nullptr)
	{
		input_shader->fragment_shader_ = opengl_functions_.glCreateShader(GL_FRAGMENT_SHADER);
		opengl_functions_.glShaderSource(input_shader->fragment_shader_, 1, fragment_shader_source, nullptr);
		opengl_functions_.glCompileShader(input_shader->fragment_shader_);

		int  success;
		char infoLog[512];
		opengl_functions_.glGetShaderiv(input_shader->fragment_shader_, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			opengl_functions_.glGetShaderInfoLog(input_shader->fragment_shader_, 512, nullptr, infoLog);
			std::cout << "Error!! Fragment shader shader compile failed. : \n" << infoLog << std::endl;
		}

		// Attach shaders
		opengl_functions_.glAttachShader(input_shader->program_, input_shader->fragment_shader_);
	}



	// Link program
	opengl_functions_.glLinkProgram(input_shader->program_);

	// Delete shaders after compile and link.
	if (input_shader->vertex_shader_ != NULL)
		opengl_functions_.glDeleteShader(input_shader->vertex_shader_);

	if (input_shader->tesselation_control_shader_ != NULL)
		opengl_functions_.glDeleteShader(input_shader->tesselation_control_shader_);

	if (input_shader->tesselation_evaluation_shader_ != NULL)
		opengl_functions_.glDeleteShader(input_shader->tesselation_evaluation_shader_);

	if (input_shader->fragment_shader_ != NULL)
		opengl_functions_.glDeleteShader(input_shader->fragment_shader_);
}
