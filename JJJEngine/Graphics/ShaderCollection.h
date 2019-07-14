#pragma once
#include "Shader.h"
#include <string>

class ShaderCollection
{
	friend class Renderer;

	using GLuint = unsigned int;

	GLuint program_ = 0;
	Shader* shader_map_ = nullptr;
	size_t size_ = 0;

	
	

	static std::string PathToName(std::string input_path);

	Shader* begin() const;
	Shader* end() const;
public:

	size_t Size() const;
	void push_back(Shader input_shader);

	GLuint const& GetProgram() const;
};