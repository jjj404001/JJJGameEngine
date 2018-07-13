#pragma once
#include <vector>

#include <OpenGL_functions.h>

struct Stride
{

};

class Mesh
{
	std::vector<Stride> vertices; // Collection of vertices position and color.


	unsigned int number_of_vertex_ = 0;// number of vertecies.
	unsigned int index_ = 0;           // Index in vao.

	unsigned int primitive_ = GL_TRIANGLES;

	GLuint VBO; // Vertex Buffer Object
	GLuint VAO; // Vertex Attribute Object
	GLuint EBO; // Element Buffer Object

public:
	void Initialize_VAO_VBO();
	void Update_VAO_VBO();
};