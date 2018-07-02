#pragma once
#include <string>

class Shader
{
	enum ShaderType
	{
		VertexShader = 1,
		TessellationControl,
		TessellationEvaluation,
		FragmentShader,
	};

	friend class Graphics;
	using GLuint = unsigned int;
	const char* shader_source_ = nullptr;


	GLuint shader_ = 0;
	static void CleanInput(char* input_buffer, size_t length);
	static bool CheckValidate(char input_char);
public:
	ShaderType type = VertexShader;

	Shader();
	Shader(ShaderType input_type, const char* input_shader_source);
	static Shader LoadShader(ShaderType input_type, std::string file_path);
};
