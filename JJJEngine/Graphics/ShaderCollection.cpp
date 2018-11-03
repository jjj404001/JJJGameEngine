#include "ShaderCollection.h"

#include <cassert>
#include <iostream>





std::string ShaderCollection::PathToName(const std::string input_path)
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

Shader* ShaderCollection::begin() const
{
	return &shader_map_[0];
}

Shader* ShaderCollection::end() const
{
	return& shader_map_[size_];
}

size_t ShaderCollection::Size() const
{
	return size_;
}

void ShaderCollection::push_back(Shader input_shader)
{
	const auto previous_length = size_;

	const auto temp = new Shader[size_];

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

ShaderCollection::GLuint ShaderCollection::GetProgram() const
{
	return program_;
}
