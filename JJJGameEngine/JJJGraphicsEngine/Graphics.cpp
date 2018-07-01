#include "Graphics.h"
#include <iostream>

void Graphics::Initialize()
{
	
	opengl_functions_.wglSwapIntervalEXT(true);


	const auto version = reinterpret_cast<const char*>(glGetString(GL_VERSION));
	std::cout << version << std::endl;

	shader_map_.LoadShader("First shader","Shader/FirstVertex.glsl", "Shader/FirstFragment.glsl");
	CompileShader(shader_map_.find("First shader"));

	GLuint VAO;
	opengl_functions_.glGenVertexArrays(1, &VAO);
	opengl_functions_.glBindVertexArray(VAO);
}

void Graphics::Update()
{
	opengl_functions_.glUseProgram(shader_map_.find("First shader")->program_);

	glDrawArrays(GL_POINTS, 0, 1);
}

void Graphics::Free()
{
	opengl_functions_.glDeleteShader(shader_map_.find("First shader")->program_);
}

void Graphics::CompileShader(Shader* input_shader)
{
	const GLchar* vertex_shader_source[] = {input_shader->vertex_shader_source_};
	const GLchar* fragment_shader_source[] = {input_shader->fragment_shader_source_};

	// Compile vertex shader
	input_shader->vertex_shader_ = opengl_functions_.glCreateShader(GL_VERTEX_SHADER);
	opengl_functions_.glShaderSource(input_shader->vertex_shader_, 1, vertex_shader_source, nullptr);
	opengl_functions_.glCompileShader(input_shader->vertex_shader_);

	// Compile fragment shader
	input_shader->fragment_shader_ = opengl_functions_.glCreateShader(GL_FRAGMENT_SHADER);
	opengl_functions_.glShaderSource(input_shader->fragment_shader_, 1, fragment_shader_source, nullptr);
	opengl_functions_.glCompileShader(input_shader->fragment_shader_);


	// Create program and attach shaders
	input_shader->program_ = opengl_functions_.glCreateProgram();
	opengl_functions_.glAttachShader(input_shader->program_, input_shader->vertex_shader_);
	opengl_functions_.glAttachShader(input_shader->program_, input_shader->fragment_shader_);
	// Link program
	opengl_functions_.glLinkProgram(input_shader->program_);

	// Delete shaders after compile and link.
	opengl_functions_.glDeleteShader(input_shader->vertex_shader_);
	opengl_functions_.glDeleteShader(input_shader->fragment_shader_);
}
