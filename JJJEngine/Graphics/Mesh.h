#pragma once
#define GLM_FORCE_CXX03
#include <vector>
#include <OpenGL/OpenGL_functions.h>
#include "Stride.h"
#include "Vector2.hpp"


#define NUMBER_OF_COMP 2    // position, color
#define NUMBER_OF_ELEMENT 7 // 3 for position, 4 for color

class ShaderCollection;
class Mesh
{
	friend class Object;
	friend class Graphics;

	std::vector<Stride> vertices;      // Collection of vertices position and color.
	std::vector<unsigned int> indices; // Collection of vertices position and color.

	unsigned int tessellation_factor_ = 3; // default tesselation is 3.

	GLenum primitive_ = GL_TRIANGLES;
	GLsizei number_of_vertex_ = 0; // number of vertecies.
	GLsizei number_of_poly_vertex = 0; // for collision check

	GLuint VAO; // Vertex Attribute Object
	GLuint VBO; // Vertex Buffer Object
	GLuint EBO; // Element Buffer Object
	GLuint texture;


#ifdef _DEBUG
	GLuint polyVAO; // Vertex Attribute Object
	GLuint polyVBO; // Vertex Buffer Object
	//GLuint debugEBO; // Element Buffer Object
	//ShaderCollection * debug = nullptr;
#endif

	ShaderCollection * shader_ = nullptr;


	unsigned __int64 Buffer_Size() const;

public:
	Mesh(const Vector2 & size = Vector2(7.f, 27.f));
	~Mesh();

	void Initialize_VAO_VBO();
	void Update_Buffers();
	void ObjectsSetting();

	void debug_triangle();
	void Debug_Cube();
	void Square(float x, float y, int vertice_num = 4);
	//vertice num is for the shape of collision detection

	GLenum Get_Primitive() { return primitive_; }
	GLsizei Get_NumOfVertices();

	GLsizei Get_NumOfVertices() const { return number_of_vertex_; }
	GLsizei Get_NumOf_PolyVertices() const { return number_of_poly_vertex; }

	GLuint GetEBO() { return EBO; }
	GLuint GetVAO() { return VAO; }
	GLuint GetVAO() const { return VAO; }
	GLuint * GetTexturePtr() { return &texture; }


	void SetShader(ShaderCollection * input_shader) { shader_ = input_shader; }
	ShaderCollection & GetShader(void) { return *shader_; }
};