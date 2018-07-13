#include "Mesh.h"


void Mesh::Initialize_VAO_VBO()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);



	glGenBuffers(1, &VBO);


	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, bytes_of_data, &vertices[0], GL_STATIC_DRAW);


	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * Mesh::number_of_element_per_stride, static_cast<void*>(0));


	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * Mesh::number_of_element_per_stride, reinterpret_cast<void*>(sizeof(float) * 3));// Works?


	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(float) * Mesh::number_of_element_per_stride, reinterpret_cast<void*>(sizeof(float) * 7));// Works?
}


void Mesh::Update_VAO_VBO()
{
	glBindVertexArray(VAO);


	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, bytes_of_data, &vertices[0], GL_STATIC_DRAW);


	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * Mesh::number_of_element_per_stride, static_cast<void*>(0));


	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * Mesh::number_of_element_per_stride, reinterpret_cast<void*>(sizeof(float) * 3));// Works?


	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(float) * Mesh::number_of_element_per_stride, reinterpret_cast<void*>(sizeof(float) * 7));// Works?
}