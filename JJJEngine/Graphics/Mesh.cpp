#include "Mesh.h"

unsigned __int64 Mesh::Buffer_Size() const { return (vertices.size() * sizeof(Stride)); }

Mesh::Mesh(const Vector2 & size)
{
	Square(size.x, size.y);
	Initialize_VAO_VBO();
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Mesh::ObjectsSetting()
{
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_BLEND);
	
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
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), &indices[0],
		GL_STATIC_DRAW);

	// VAO
	// Position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Stride), reinterpret_cast<void *>(0));

	// Color
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_FALSE, sizeof(Stride),
		reinterpret_cast<void *>(sizeof(Position)));

	// Texture coordinate
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Stride),
		reinterpret_cast<void *>(sizeof(Position) + sizeof(Color)));

}

void Mesh::Initialize_VAO_VBO()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	// VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, Buffer_Size(), &vertices[0], GL_STATIC_DRAW);

	// EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), &indices[0],
		GL_STATIC_DRAW);

	// VAO
	// Position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Stride), reinterpret_cast<void *>(0));

	// Color
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_FALSE, sizeof(Stride),
		reinterpret_cast<void *>(sizeof(Position)));

	// Texture coordinate
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Stride),
		reinterpret_cast<void *>(sizeof(Position) + sizeof(Color)));
}


void Mesh::Update_Buffers()
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);


	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);


	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);


	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, Buffer_Size(), &vertices[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), &indices[0], GL_STATIC_DRAW);


	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Stride), reinterpret_cast<void *>(0));

	// Color
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_FALSE, sizeof(Stride),
		reinterpret_cast<void *>(sizeof(Position)));

	// Texture coordinate
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Stride),
		reinterpret_cast<void *>(sizeof(Position) + sizeof(Color)));
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

void Mesh::Square(float x, float y, int vertice_num)
{
	vertices.clear();
	indices.clear();

	float width = x / 2.f;
	float height = y / 2.f;


	auto bottom_right = Stride(width, -height, 1.0f);
	auto bottom_left = Stride(-width, -height, 1.0f);
	auto top_right = Stride(width, height, 1.0f);
	auto top_left = Stride(-width, height, 1.0f);

	bottom_right.color = Color(255, 0, 0, 255);
	bottom_left.color = Color(0, 255, 0, 255);
	top_right.color = Color(0, 0, 255, 255);
	top_left.color = Color(255, 0, 0, 255);

	bottom_right.textureCoordinates[0] = 1.f;
	bottom_right.textureCoordinates[1] = 0.0f;

	bottom_left.textureCoordinates[0] = 0.0f;
	bottom_left.textureCoordinates[1] = 0.0f;

	top_right.textureCoordinates[0] = 1.f;
	top_right.textureCoordinates[1] = 1.f;

	top_left.textureCoordinates[0] = 0.0f;
	top_left.textureCoordinates[1] = 1.f;

	vertices.push_back(bottom_left);
	vertices.push_back(bottom_right);
	vertices.push_back(top_right);
	vertices.push_back(top_left);

	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(3);
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(3);

	primitive_ = GL_TRIANGLES;
	number_of_vertex_ = 6;
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