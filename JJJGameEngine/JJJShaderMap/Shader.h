#pragma once
#include <string>

struct Shader
{
	std::string name = "default shader";
	const char* shader_source = nullptr;


public:
	Shader();
	Shader(std::string input_name, const char* input_shader_source);
};
