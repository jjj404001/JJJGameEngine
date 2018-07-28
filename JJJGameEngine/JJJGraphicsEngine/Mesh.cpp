#include "Mesh.h"


unsigned __int64 Mesh::Buffer_Size()
{

	return (vertices.size() * sizeof(float) * 3) + (vertices.size() * sizeof(unsigned char) * 4);
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
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Stride), static_cast<void*>(0));

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_FALSE, sizeof(Stride), reinterpret_cast<void*>(sizeof(float) * 3));
}


void Mesh::Update_VAO_VBO()
{

}

void Mesh::debug_triangle()
{
	auto bottom_right = Stride(0.25f, -0.25f, 0.0f);
	auto bottom_left = Stride(-0.25f, -0.25f, 0.0f);
	auto top_right = Stride(0.25f, 0.25f, 0.0f);

	bottom_right.color = Color(255, 0, 0, 255);
	bottom_left.color = Color(0, 255, 0, 255);
	top_right.color = Color(0, 0, 255, 255);

	bottom_right.color = Color(255, 255, 255, 255);
	bottom_left.color = Color(255, 255, 255, 255);
	top_right.color = Color(255, 255, 255, 255);

	vertices.push_back(bottom_left);
	vertices.push_back(bottom_right);
	vertices.push_back(top_right);

	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);

	primitive_ = GL_TRIANGLES;
	number_of_vertex_ = 3;
}

void Mesh::Debug_Cube()
{
	auto bottom_left0 = Stride(-0.5f, -0.5f, -0.5f);
	auto bottom_right0 = Stride(0.5f, -0.5f, -0.5);
	auto top_right0 = Stride(0.5f, 0.5f, -0.5f);
	auto top_left0 = Stride(0.5f, 0.5f, -0.5f);

	bottom_left0.color = Color(255, 0, 0, 255);
	bottom_right0.color = Color(0, 255, 0, 255);
	top_right0.color = Color(0, 0, 255, 255);
	top_left0.color = Color(0, 0, 255, 255);


	vertices.push_back(bottom_left0);
	vertices.push_back(bottom_left0);
	vertices.push_back(bottom_left0);

	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(2);
	indices.push_back(3);
	indices.push_back(0);

	
	/*
		-0.5f, -0.5f, -0.5f
		0.5f, -0.5f, -0.5
		0.5f, 0.5f, -0.5f
		0.5f, 0.5f, -0.5f
		-0.5f, 0.5f, -0.5f
		-0.5f, -0.5f, -0.5f

		-0.5f, -0.5f, 0.5f
		0.5f, -0.5f, 0.5f,
		0.5f, 0.5f, 0.5f
		0.5f, 0.5f, 0.5f,
		-0.5f, 0.5f, 0.5f
		-0.5f, -0.5f, 0.5f,

		-0.5f, 0.5f, 0.5f,
		-0.5f, 0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, 0.5f,
		-0.5f, 0.5f, 0.5f,

		0.5f, 0.5f, 0.5f, 
		0.5f, 0.5f, -0.5f, 
		0.5f, -0.5f, -0.5f, 
		0.5f, -0.5f, -0.5f, 
		0.5f, -0.5f, 0.5f, 
		0.5f, 0.5f, 0.5f, 

		-0.5f, -0.5f, -0.5f, 
		0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, 0.5f, 
		0.5f, -0.5f, 0.5f, 
		-0.5f, -0.5f, 0.5f, 
		-0.5f, -0.5f, -0.5f, 

		-0.5f, 0.5f, -0.5f,
		0.5f, 0.5f, -0.5f,
		0.5f, 0.5f, 0.5f, 
		0.5f, 0.5f, 0.5f, 
		-0.5f, 0.5f, 0.5f, 
		-0.5f, 0.5f, -0.5f, 
	*/

	primitive_ = GL_TRIANGLES;
	number_of_vertex_ = 6;
}


GLenum Mesh::Get_Primitive()
{
	return primitive_;
}
GLsizei Mesh::Get_NumOfVertices()
{
	return number_of_vertex_;
}

void Mesh::SetShader(ShaderCollection* input_shader)
{
	shader_ = input_shader;
}

ShaderCollection& Mesh::GetShader()
{
	return *shader_;
}