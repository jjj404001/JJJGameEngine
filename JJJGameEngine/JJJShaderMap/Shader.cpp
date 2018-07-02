#include "Shader.h"
#include "OpenGL_functions.h"
#include <cassert>
#include <iostream>
#include <fstream>



void Shader::CleanInput(char* input_buffer, size_t length)
{
	// Replace invalide character with NULL.
	for (size_t i = 0; i < length; ++i)
		if (CheckValidate(input_buffer[i]))
			input_buffer[i] = NULL;
}

bool Shader::CheckValidate(char input_char)
{
	bool invalid = 32 <= input_char && input_char <= 126;

	invalid = invalid || input_char == '\n';
	invalid = invalid || input_char == '\t';

	return !invalid;
}

Shader::Shader()
{
	type = VertexShader;
	shader_source_ = nullptr;
}

Shader::Shader(const ShaderType input_type, const char* input_shader_source)
{
	type = input_type;
	shader_source_ = input_shader_source;
}

Shader Shader::LoadShader(const ShaderType input_type, const std::string file_path)
{
	// Open shaderfile.
	std::ifstream infile;
	infile.open(file_path);



	if (!infile.good())
		assert(!"Error occerred during opening shader file.");


	// Go to end of file.
	infile.seekg(0, std::ifstream::end);
	// Get length
	const auto length = infile.tellg();
	// And return to beginning of the file.
	infile.seekg(0, std::ifstream::beg);




	std::cout << "Reading " << length << " characters" << std::endl;
	std::cout << "For " << file_path << " shader file." << std::endl;
	// read data as a block:
	auto* buffer = new char[length];
	infile.read(buffer, length);
	CleanInput(buffer, length);


	return  Shader(input_type,buffer);
}