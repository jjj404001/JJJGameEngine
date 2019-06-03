#pragma once
#include <string>

class Shader
{
	enum ShaderType
	{
		VertexShader = 1,
		TessellationControl,
		TessellationEvaluation,
		Geometry,
		FragmentShader,
	};

	friend class Graphics;
	using GLuint = unsigned int;
	std::string shader_source_;


	GLuint shader_ = 0;
	static void CleanInput(char* input_buffer, size_t length);
	static bool CheckValidate(char input_char);
public:
	ShaderType type = VertexShader;

	Shader();
	Shader(ShaderType input_type, std::string input_shader_source);
	static Shader LoadShader(ShaderType input_type, std::string file_path);
};
