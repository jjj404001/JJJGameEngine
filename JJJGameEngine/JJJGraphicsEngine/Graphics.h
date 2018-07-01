#pragma once
#include "OpenGL_functions.h"
#include "ShaderMap.h"
#include "Color.h"


class Graphics
{
	friend class GLWindow;

	OpenGLFunctions opengl_functions_;
	ShaderMap shader_map_;

	Color clear_color_{};

	void Initialize();
	void Update();
	void Free();


	void CompileShader(Shader* input_shader);
};
