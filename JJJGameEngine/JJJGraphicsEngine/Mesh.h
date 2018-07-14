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
	std::vector<unsigned int> indices; // Collection of vertices position and color.



	

	unsigned int tessellation_factor_ = 3; // default tesselation is 3.

	GLenum primitive_ = GL_TRIANGLES;
	GLsizei number_of_vertex_ = 0;// number of vertecies.


	GLuint VAO; // Vertex Attribute Object
	GLuint VBO; // Vertex Buffer Object
	GLuint EBO; // Element Buffer Object

	unsigned __int64 Buffer_Size();

public:
	void Initialize_VAO_VBO();
	void Update_VAO_VBO();

	void debug_triangle();

	GLenum Get_Primitive();
	GLsizei Get_NumOfVertices();
};