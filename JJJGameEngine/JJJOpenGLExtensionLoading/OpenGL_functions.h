#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include "glext.h"
#include "wglext.h"


struct OpenGLFunctions
{
	PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = nullptr;
	PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = nullptr;
	PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = nullptr;
	PFNWGLGETSWAPINTERVALEXTPROC wglGetSwapIntervalEXT = nullptr;



	void InitOpenGLFunctions();
};