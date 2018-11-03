#pragma once
#include <OpenGL/OpenGL_functions.h>
#include "ShaderCollection.h"
#include "Color.h"


class Graphics
{
	friend class GLWindow;

	ShaderCollection Tesselation_geometry_white_shader_;

	Color clear_color_;

	void Initialize();
	void Update();
	void Free() const;


	void CompileShaders(ShaderCollection& input_shader_collection) const;
};