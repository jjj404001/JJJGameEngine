#pragma once
#include <string>

class Shader
{
	friend class Graphics;

	using GLuint = unsigned int;
	
	const char* vertex_shader_source_ = nullptr;
	const char* tesselation_control_shader_source_ = nullptr;
	const char* tesselation_evaluation_shader_source_ = nullptr;
	const char* fragment_shader_source_ = nullptr;

	GLuint vertex_shader_ = 0;
	GLuint tesselation_control_shader_ = 0;
	GLuint tesselation_evaluation_shader_ = 0;
	GLuint fragment_shader_ = 0;

	GLuint program_ = 0;

public:
	std::string name = "default shader";
	Shader();
	Shader(std::string input_name, const char* input_vertex_shader_source, const char* input_fragment_shader_source);
	Shader(std::string input_name, const char* input_vertex_shader_source, const char* tesselation_control_shader_source, const char* tesselation_evaluation_shader_source, const char* input_fragment_shader_source);
};
