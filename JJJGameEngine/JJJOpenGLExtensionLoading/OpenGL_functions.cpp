#include "OpenGL_functions.h"
#include <cassert>


void OpenGLFunctions::InitOpenGLFunctions()
{
	// https://www.khronos.org/opengl/wiki/Load_OpenGL_Functions#Windows_2

	wglChoosePixelFormatARB = reinterpret_cast<PFNWGLCHOOSEPIXELFORMATARBPROC>(wglGetProcAddress("wglChoosePixelFormatARB"));
	if (wglChoosePixelFormatARB == nullptr)
		assert(!"wglChoosePixelFormatARB not initialized.");

	wglCreateContextAttribsARB = reinterpret_cast<PFNWGLCREATECONTEXTATTRIBSARBPROC>(wglGetProcAddress("wglCreateContextAttribsARB"));
	if (wglCreateContextAttribsARB == nullptr)
		assert(!"wglCreateContextAttribsARB not initialized.");

	wglSwapIntervalEXT = reinterpret_cast<PFNWGLSWAPINTERVALEXTPROC>(wglGetProcAddress("wglSwapIntervalEXT"));
	if (wglSwapIntervalEXT == nullptr)
		assert(!"wglSwapIntervalEXT not initialized.");

	wglGetSwapIntervalEXT = reinterpret_cast<PFNWGLGETSWAPINTERVALEXTPROC>(wglGetProcAddress("wglGetSwapIntervalEXT"));
	if (wglGetSwapIntervalEXT == nullptr)
		assert(!"wglGetSwapIntervalEXT not initialized.");
}
