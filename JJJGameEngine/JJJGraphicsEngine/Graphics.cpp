#include "Graphics.h"
#include <iostream>

void Graphics::Initialize()
{
	
	opengl_functions_.wglSwapIntervalEXT(true);


	const auto version = reinterpret_cast<const char*>(glGetString(GL_VERSION));
	std::cout << version << std::endl;

	shader_map_.LoadShader("Shader/White_Blank.glsl");
}

void Graphics::Update()
{
}

void Graphics::Free()
{
}
