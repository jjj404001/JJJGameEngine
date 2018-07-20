#pragma once
#include "ShaderCollection.h"
#include "Color.h"
#include "Object.h"

#include <list>
#include "2DCamera.h"

class Graphics
{
	friend class GLWindow;

	ShaderCollection Tesselation_geometry_white_shader_;
	ShaderCollection Tesselation_white_shader_;
	ShaderCollection vertex_fragment_;

	Color clear_color_;

	TwoDimensionalCamera main_camera_;



	std::list<Object> object_list_;

	void Initialize(long res_x, long res_y);
	void Update();
	void Free() const;


	void CompileShaders(ShaderCollection& input_shader_collection) const;

public:
	bool Tessellation = false;
};
