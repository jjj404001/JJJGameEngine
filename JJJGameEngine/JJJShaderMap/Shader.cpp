#include "Shader.h"


Shader::Shader()
{
	name = "default shader";
	shader_source = nullptr;
}

Shader::Shader(std::string input_name, const char* input_shader_source)
{
	name = input_name;
	shader_source = input_shader_source;
}
