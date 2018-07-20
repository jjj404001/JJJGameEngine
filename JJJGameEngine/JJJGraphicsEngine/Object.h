#pragma once
#include "Mesh.h"
#include "Transform.h"

class Object
{
	friend class Graphics;
	Mesh mesh_;
	

public:
	std::string name = "default_OBJ_name";
	Transform transform_;

	Mesh & GetMesh();
	void Update();

	
};

