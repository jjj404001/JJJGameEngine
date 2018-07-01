#include "ShaderMap.h"
#include <fstream>
#include <cassert>
#include <iostream>
#include <filesystem>
#include "OpenGL_functions.h"

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

std::string ShaderMap::PathToName(std::string input_path)
{
	auto result = input_path;


	// Erase file path.
	auto end = 0;
	for(auto i : result)
	{
		if (i == '/')
		{
			++end;
			break;
		}

		++end;
	}
	result.erase(0, end);



	// Erase file extension.
	auto start = 0;
	for (auto i : result)
	{
		if (i == '.')
			break;


		++start;
	}
	result.erase(start, result.back());

	return  result;
}

Shader* ShaderMap::begin()
{
	return &shader_map_[0];
}

void ShaderMap::LoadShader(std::string input_name, std::string vertex_file_path, std::string fragment_file_path)
{
	// Open shaderfile.
	std::ifstream vertex_infile;
	std::ifstream fragment_infile;
	vertex_infile.open(vertex_file_path);
	fragment_infile.open(fragment_file_path);



	if(!vertex_infile.good())
		assert(!"Error occerred during opening vertex shader file.");

	if (!fragment_infile.good())
		assert(!"Error occerred during opening fragment shader file.");

	// Go to end of file.
	vertex_infile.seekg(0, std::ifstream::end);
	// Get length
	const auto vertex_length = vertex_infile.tellg();
	// And return to beginning of the file.
	vertex_infile.seekg(0, std::ifstream::beg);


	// Go to end of file.
	fragment_infile.seekg(0, std::ifstream::end);
	// Get length
	const auto fragment_length = fragment_infile.tellg();
	// And return to beginning of the file.
	fragment_infile.seekg(0, std::ifstream::beg);



	// Extract name from file path.
	std::string shader_name = input_name;



	std::cout << "Reading " << vertex_length << " characters" << std::endl;
	std::cout << "For " << vertex_file_path << " shader file." << std::endl;
	// read data as a block:
	auto* vertex_shader_buffer = new char[vertex_length];
	vertex_infile.read(vertex_shader_buffer, vertex_length);
	CleanInput(vertex_shader_buffer, vertex_length);

	std::cout << "Reading " << fragment_length << " characters" << std::endl;
	std::cout << "For " << fragment_file_path << " shader file." << std::endl;
	// read data as a block:
	auto* fragment_shader_buffer = new char[fragment_length];
	fragment_infile.read(fragment_shader_buffer, fragment_length);
	CleanInput(fragment_shader_buffer, fragment_length);

	const Shader new_shader(shader_name, vertex_shader_buffer, fragment_shader_buffer);
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

Shader* ShaderMap::find(const std::string input_shader_name)
{
	for (auto i = 0; i < size_; ++i)
	{
		if (shader_map_[i].name == input_shader_name)
			return &shader_map_[i];
	}

	return nullptr;
}
