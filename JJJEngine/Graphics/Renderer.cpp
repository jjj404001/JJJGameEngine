#include "Renderer.h"
#include <iostream>
#include <cassert>


void Renderer::Initialize()
{
	wglSwapIntervalEXT(true);


	const auto version = reinterpret_cast<const char*>(glGetString(GL_VERSION));
	std::cout << version << std::endl;


	Tesselation_geometry_white_shader_.push_back(Shader::LoadShader(Shader::VertexShader, "Shader/Triangle_Vertex.glsl"));
	Tesselation_geometry_white_shader_.push_back(Shader::LoadShader(Shader::TessellationControl, "Shader/tessellation_control.glsl"));
	Tesselation_geometry_white_shader_.push_back(Shader::LoadShader(Shader::TessellationEvaluation, "Shader/tessellation_evalution.glsl"));
	Tesselation_geometry_white_shader_.push_back(Shader::LoadShader(Shader::Geometry, "Shader/Geometry_Tri_to_point.glsl"));
	Tesselation_geometry_white_shader_.push_back(Shader::LoadShader(Shader::FragmentShader, "Shader/Triangle_Fragment.glsl"));
	CompileShaders(Tesselation_geometry_white_shader_);


	Simple_triangle.push_back(Shader::LoadShader(Shader::VertexShader, "Shader/Triangle_Vertex.glsl"));
	Simple_triangle.push_back(Shader::LoadShader(Shader::FragmentShader, "Shader/Triangle_Fragment.glsl"));


	


	/*
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO0);
	glGenBuffers(1, &VBO1);

	glGenBuffers(1, &EBO);


	glBindVertexArray(VAO);

	

	// VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO0);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 9, &tri_vert[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 9, &tri_vert1[0], GL_STATIC_DRAW);

	// EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 3, &tri_endices[0], GL_STATIC_DRAW);

	
	// VAO
	// Position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, reinterpret_cast<void *>(0));
	*/
}

void Renderer::Update()
{
	Mesh mesh = Mesh(Vector2(0.4f, 0.4f));

	glUseProgram(Simple_triangle.GetProgram());
	glBindVertexArray(mesh.GetVAO());
	
	glDrawElements(mesh.GetPrimitive(), mesh.GetNumOfVertices(), GL_UNSIGNED_INT, NULL);
}



void Renderer::Free() const
{
	glDeleteShader(Tesselation_geometry_white_shader_.GetProgram());
	glDeleteShader(Simple_triangle.GetProgram());
}

void Renderer::CompileShaders(ShaderCollection& input_shader_collection) const
{
	// Create program.
	input_shader_collection.program_ = glCreateProgram();

	for(auto current_shader : input_shader_collection)
	{
		switch (current_shader.type)
		{
			case Shader::VertexShader:
				current_shader.shader_ = glCreateShader(GL_VERTEX_SHADER);
				break;
			case Shader::TessellationControl:
				current_shader.shader_ = glCreateShader(GL_TESS_CONTROL_SHADER);
				break;
			case Shader::TessellationEvaluation:
				current_shader.shader_ = glCreateShader(GL_TESS_EVALUATION_SHADER);
				break;
			case Shader::Geometry:
				current_shader.shader_ = glCreateShader(GL_GEOMETRY_SHADER);
				break;
			case Shader::FragmentShader:
				current_shader.shader_ = glCreateShader(GL_FRAGMENT_SHADER);
				break;
			default:
				assert(!"Undefined shader type");
		}

		const GLchar* shader_source[] = { current_shader.shader_source_.c_str() };

		glShaderSource(current_shader.shader_, 1, shader_source, nullptr);
		glCompileShader(current_shader.shader_);


		int  success;
		char infoLog[512];
		glGetShaderiv(current_shader.shader_, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(current_shader.shader_, 512, nullptr, infoLog);
			std::cout << "Error!! shader compile failed. : \n" << infoLog << std::endl;
		}


		// Attach shaders
		glAttachShader(input_shader_collection.program_, current_shader.shader_);
	}




	// Link program
	glLinkProgram(input_shader_collection.program_);

	for (const auto current_shader : input_shader_collection)
		glDeleteShader(current_shader.shader_);
}
