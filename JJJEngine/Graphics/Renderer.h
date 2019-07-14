#pragma once
#include <vector>
#include <OpenGL/OpenGL_functions.h>
#include "ShaderCollection.h"
#include "Color.h"
#include "Mesh.h"

class Renderer
{
	friend class GLWindow;

	ShaderCollection Tesselation_geometry_white_shader_;
	ShaderCollection Simple_triangle;

	Color clear_color_;

	void Initialize();
	void Update();
	void Free() const;

	void CompileShaders(ShaderCollection& input_shader_collection) const;
};
