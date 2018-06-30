#include "ShaderMap.h"
#include <fstream>
#include <cassert>
#include <iostream>

void ShaderMap::CleanInput(char* input_buffer, size_t length)
{
	// Replace invalide character with NULL.
	for (size_t i = 0; i < length; ++i)
		if (CheckValidate(input_buffer[i]))
			input_buffer[i] = NULL;
}

bool ShaderMap::CheckValidate(char input_char)
{
	bool invalid = 32 <= input_char && input_char <= 126;

	invalid = invalid || input_char == '\n';
	invalid = invalid || input_char == '\t';

	return !invalid;
}

Shader* ShaderMap::begin()
{
	return &shader_map_[0];
}

void ShaderMap::LoadShader(std::string file_path)
{
	// Open shaderfile in read only mode.
	std::ifstream infile;
	infile.open(file_path);



	if(!infile.good())
		assert(!"Error occerred during opening file.");

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


	const Shader new_shader(file_path, buffer);
	push_back(new_shader);
}

size_t ShaderMap::Size() const
{
	return size_;
}

void ShaderMap::push_back(Shader input_shader)
{
	const auto previous_length = size_;

	Shader* temp = nullptr;
	temp = new Shader[size_];

	// Copy current shadermap to temporary storage.
	for (auto i = 0; i < size_; ++i)
		temp[i] = shader_map_[i];

	// Reallocate with +1 size.
	shader_map_ = new Shader [++size_];


	// Get original data from temporary storage.
	for (auto i = 0; i < previous_length; ++i)
		shader_map_[i] = temp[i];

	// Delete after copy. 
	delete[] temp;

	// Push back.
	shader_map_[previous_length] = input_shader;
}
