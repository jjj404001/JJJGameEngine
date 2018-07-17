#pragma once
#include "ShaderCollection.h"
#include "Color.h"
#include "Mesh.h"

class Graphics
{
	friend class GLWindow;

	ShaderCollection Tesselation_geometry_white_shader_;
	ShaderCollection Tesselation_white_shader_;
	ShaderCollection vertex_fragment_;

	Color clear_color_;

	Mesh testMesh;


	void Initialize();
	void Update();
	void Free() const;


	void CompileShaders(ShaderCollection& input_shader_collection) const;

public:
	bool Tessellation = false;
};
