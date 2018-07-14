#pragma once
#include <vector>
#include <OpenGL_functions.h>

#define NUMBER_OF_ELEMENT 3

struct Stride
{
	

	Stride(float x, float y, float z)
	{
		position[0] = x;
		position[1] = y;
		position[2] = z;
	}
	float position[3] = {0.0f, };
};

class Mesh
{
	std::vector<Stride> vertices; // Collection of vertices position and color.

	unsigned int number_of_vertex_ = 0;// number of vertecies.
	unsigned int index_ = 0;           // Index in vao.

	unsigned int tessellation_factor_ = 3; // default tesselation is 3.

	unsigned int primitive_ = GL_TRIANGLES;

	GLuint VAO; // Vertex Attribute Object
	GLuint VBO; // Vertex Buffer Object
	GLuint EBO; // Element Buffer Object

	unsigned __int64 Buffer_Size();

public:
	void Initialize_VAO_VBO();
	void Update_VAO_VBO();

	void debug_triangle();
};