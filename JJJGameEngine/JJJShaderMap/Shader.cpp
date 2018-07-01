#include "Shader.h"
#include "OpenGL_functions.h"

Shader::Shader()
{
	name = "default shader";
	vertex_shader_source_ = nullptr;
	fragment_shader_source_ = nullptr;
}

Shader::Shader(std::string input_name, const char* input_vertex_shader_source, const char* input_fragment_shader_source)
{
	name = input_name;
	vertex_shader_source_ = input_vertex_shader_source;
	fragment_shader_source_ = input_fragment_shader_source;
}

Shader::Shader(std::string input_name, const char* input_vertex_shader_source,
	const char* tesselation_control_shader_source, const char* tesselation_evaluation_shader_source,
	const char* input_fragment_shader_source)
{
	name = input_name;
	vertex_shader_source_ = input_vertex_shader_source;
	tesselation_control_shader_source_ = tesselation_control_shader_source;
	tesselation_evaluation_shader_source_ = tesselation_evaluation_shader_source;
	fragment_shader_source_ = input_fragment_shader_source;
}
