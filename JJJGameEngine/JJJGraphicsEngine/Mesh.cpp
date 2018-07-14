#include "Mesh.h"

unsigned __int64 Mesh::Buffer_Size()
{
	return sizeof(float) * vertices.size() * NUMBER_OF_ELEMENT;
}

void Mesh::Initialize_VAO_VBO()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);



	glGenBuffers(1, &VBO);
	
	GL_PATCH_VERTICES;

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, Buffer_Size(), &vertices[0], GL_STATIC_DRAW);


	

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
}