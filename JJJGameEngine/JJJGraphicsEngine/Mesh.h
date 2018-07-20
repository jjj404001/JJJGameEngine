#pragma once
#include <vector>
#include <OpenGL_functions.h>
#include "Stride.h"

#define NUMBER_OF_COMP 2 // position, color
#define NUMBER_OF_ELEMENT 7 // 3 for position, 4 for color


class ShaderCollection;
class Mesh
{
	friend class Object;
	friend class Graphics;

	std::vector<Stride> vertices; // Collection of vertices position and color.
	std::vector<unsigned int> indices; // Collection of vertices position and color.



	

	unsigned int tessellation_factor_ = 3; // default tesselation is 3.

	GLenum primitive_ = GL_TRIANGLES;
	GLsizei number_of_vertex_ = 0;// number of vertecies.


	GLuint VAO; // Vertex Attribute Object
	GLuint VBO; // Vertex Buffer Object
	GLuint EBO; // Element Buffer Object

	ShaderCollection* shader_ = nullptr;

	unsigned __int64 Buffer_Size();

public:
	void Initialize_VAO_VBO();
	void Update_VAO_VBO();

	void debug_triangle();

	GLenum Get_Primitive();
	GLsizei Get_NumOfVertices();

	void SetShader(ShaderCollection* input_shader);
	ShaderCollection& GetShader(void);
	GLuint& GetShaderProgram(void);
};