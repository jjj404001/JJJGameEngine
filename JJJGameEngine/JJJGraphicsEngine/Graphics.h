#pragma once
#include "OpenGL_functions.h"
#include "ShaderCollection.h"
#include "Color.h"


class Graphics
{
	friend class GLWindow;

	OpenGLFunctions opengl_functions_;
	ShaderCollection Tesselation_geometry_white_shader_;

	Color clear_color_;

	void Initialize();
	void Update();
	void Free() const;


	void CompileShaders(ShaderCollection& input_shader_collection) const;
};
