#include "Mesh.h"

unsigned __int64 Mesh::Buffer_Size()
{
	return sizeof(float) * vertices.size() * NUMBER_OF_ELEMENT;
}

void Mesh::Initialize_VAO_VBO()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);



	// VAO
	glBindVertexArray(VAO);



	// VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, Buffer_Size(), &vertices[0], GL_STATIC_DRAW);



	// EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), &indices[0], GL_STATIC_DRAW);
	
	// VAO
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, static_cast<void*>(0));
}


void Mesh::Update_VAO_VBO()
{
	glBindVertexArray(VAO);


	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, Buffer_Size(), &vertices[0], GL_STATIC_DRAW);


	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, static_cast<void*>(0));
}

void Mesh::debug_triangle()
{
	vertices.push_back(Stride(0.25f, -0.25f, 0.5f));
	vertices.push_back(Stride(-0.25f, -0.25f, 0.5f));
	vertices.push_back(Stride(0.25f, 0.25f, 0.5f));

	indices.push_back(1);
	indices.push_back(0);
	indices.push_back(2);

	primitive_ = GL_TRIANGLES;
	number_of_vertex_ = 3;
}




GLenum Mesh::Get_Primitive()
{
	return primitive_;
}
GLsizei Mesh::Get_NumOfVertices()
{
	return number_of_vertex_;
}