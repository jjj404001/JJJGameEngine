#pragma once
#include "Shader.h"
#include <string>

class ShaderMap
{
	Shader* shader_map_ = nullptr;
	size_t size_ = 0;

	void CleanInput(char* input_buffer, size_t length);
	bool CheckValidate(char input_char);

	static std::string PathToName(std::string input_path);

	Shader* begin();
public:
	void LoadShader(std::string file_path);
	size_t Size() const;
	void push_back(Shader input_shader);
	Shader* find(std::string input_shader_name);
};