#include "Graphics.h"
#include <iostream>
#include <cassert>
#include "Camera.h"
#define SET_INITIAL_NAME(Variable) (#Variable)

void Graphics::Initialize(long res_x, long res_y)
{
	wglSwapIntervalEXT(true);


	const auto version = reinterpret_cast<const char*>(glGetString(GL_VERSION));
	std::cout << version << std::endl;


	main_camera_.Initialize(res_x, res_y);


	Tesselation_geometry_white_shader_.push_back(Shader::LoadShader(Shader::VertexShader, "Shader/Triangle_Vertex.glsl"));
	Tesselation_geometry_white_shader_.push_back(Shader::LoadShader(Shader::TessellationControl, "Shader/tessellation_control.glsl"));
	Tesselation_geometry_white_shader_.push_back(Shader::LoadShader(Shader::TessellationEvaluation, "Shader/tessellation_evalution.glsl"));
	Tesselation_geometry_white_shader_.push_back(Shader::LoadShader(Shader::Geometry, "Shader/Geometry_Tri_to_point.glsl"));
	Tesselation_geometry_white_shader_.push_back(Shader::LoadShader(Shader::FragmentShader, "Shader/Triangle_Fragment.glsl"));
	CompileShaders(Tesselation_geometry_white_shader_);

	
	Tesselation_white_shader_.push_back(Shader::LoadShader(Shader::VertexShader, "Shader/Triangle_Vertex.glsl"));
	Tesselation_white_shader_.push_back(Shader::LoadShader(Shader::TessellationControl, "Shader/tessellation_control.glsl"));
	Tesselation_white_shader_.push_back(Shader::LoadShader(Shader::TessellationEvaluation, "Shader/tessellation_evalution.glsl"));
	Tesselation_white_shader_.push_back(Shader::LoadShader(Shader::FragmentShader, "Shader/Triangle_Fragment.glsl"));
	CompileShaders(Tesselation_white_shader_);


	vertex_fragment_.push_back(Shader::LoadShader(Shader::VertexShader, "Shader/Triangle_Vertex.glsl"));
	vertex_fragment_.push_back(Shader::LoadShader(Shader::FragmentShader, "Shader/Triangle_Fragment.glsl"));
	CompileShaders(vertex_fragment_);

	Object testOBJ;
	testOBJ.GetMesh().debug_triangle();
	testOBJ.GetMesh().Initialize_VAO_VBO();
	testOBJ.GetMesh().SetShader(&Tesselation_white_shader_);

	testOBJ.name = SET_INITIAL_NAME(testOBJ);
	testOBJ.transform_.translation_ = Vector2(0.0f, 0.0f);



	object_list_.push_back(testOBJ);

	// Pixel size
	glPointSize(5.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// Set shader program
	glUseProgram(testOBJ.GetMesh().GetShader().GetProgram());
}

void Graphics::Update()
{
	for (auto current_OBJ : object_list_)
	{
		std::cout << current_OBJ.name << std::endl;



		auto T = Affine2d::build_translation(current_OBJ.transform_.translation_.value[0], current_OBJ.transform_.translation_.value[1]);
		auto R = Affine2d::build_rotation(-current_OBJ.transform_.rotation_);
		auto S = Affine2d::build_scale(current_OBJ.transform_.scale_.value[0], current_OBJ.transform_.scale_.value[1]);


		// Use this order because we transpose.
		main_camera_.SetWorld(T, R, S);





		const auto uniCombined = glGetUniformLocation(current_OBJ.mesh_.GetShader().GetProgram(), "combined");
		const auto combined = main_camera_.CombindMatrix();


		glUniformMatrix3fv(uniCombined, 1, GL_TRUE, &combined.value[0][0]);




		glDrawElements(GL_PATCHES, current_OBJ.GetMesh().Get_NumOfVertices(), GL_UNSIGNED_INT, nullptr);
	}
	//glDrawElements(testMesh.Get_Primitive(), testMesh.Get_NumOfVertices(), GL_UNSIGNED_INT, nullptr);
}

void Graphics::Free() const
{
	glDeleteShader(Tesselation_geometry_white_shader_.GetProgram());
}

void Graphics::CompileShaders(ShaderCollection& input_shader_collection) const
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

		const GLchar* shader_source[] = { current_shader.shader_source_ };

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
