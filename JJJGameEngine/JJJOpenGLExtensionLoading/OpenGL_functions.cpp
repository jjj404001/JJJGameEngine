#include "OpenGL_functions.h"
#include <cassert>


void OpenGLFunctions::InitOpenGLFunctions()
{
	// https://www.khronos.org/opengl/wiki/Load_OpenGL_Functions#Windows_2

	// Windows
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


	// GL buffers
	glClearBufferfv = reinterpret_cast<PFNGLCLEARBUFFERFVPROC>(wglGetProcAddress("glClearBufferfv"));
	if (glClearBufferfv == nullptr)
		assert(!"glClearBufferfv not initialized.");

	glClearBufferiv = reinterpret_cast<PFNGLCLEARBUFFERIVPROC>(wglGetProcAddress("glClearBufferiv"));
	if (glClearBufferiv == nullptr)
		assert(!"glClearBufferiv not initialized.");

	glClearBufferuiv = reinterpret_cast<PFNGLCLEARBUFFERUIVPROC>(wglGetProcAddress("glClearBufferuiv"));
	if (glClearBufferuiv == nullptr)
		assert(!"glClearBufferuiv not initialized.");

	glClearBufferfi = reinterpret_cast<PFNGLCLEARBUFFERFIPROC>(wglGetProcAddress("glClearBufferfi"));
	if (glClearBufferfi == nullptr)
		assert(!"glClearBufferfi not initialized.");


	// GL shaders
	glCreateShader = reinterpret_cast<PFNGLCREATESHADERPROC>(wglGetProcAddress("glCreateShader"));
	if (glCreateShader == nullptr)
		assert(!"glCreateShader not initialized.");

	glShaderSource = reinterpret_cast<PFNGLSHADERSOURCEPROC>(wglGetProcAddress("glShaderSource"));
	if (glShaderSource == nullptr)
		assert(!"glShaderSource not initialized.");

	glCompileShader = reinterpret_cast<PFNGLCOMPILESHADERPROC>(wglGetProcAddress("glCompileShader"));
	if (glCompileShader == nullptr)
		assert(!"glCompileShader not initialized.");

	glCreateProgram = reinterpret_cast<PFNGLCREATEPROGRAMPROC>(wglGetProcAddress("glCreateProgram"));
	if (glCreateProgram == nullptr)
		assert(!"glCreateProgram not initialized.");

	glAttachShader = reinterpret_cast<PFNGLATTACHSHADERPROC>(wglGetProcAddress("glAttachShader"));
	if (glAttachShader == nullptr)
		assert(!"glAttachShader not initialized.");

	glLinkProgram = reinterpret_cast<PFNGLLINKPROGRAMPROC>(wglGetProcAddress("glLinkProgram"));
	if (glLinkProgram == nullptr)
		assert(!"glLinkProgram not initialized.");

	glDeleteShader = reinterpret_cast<PFNGLDELETESHADERPROC>(wglGetProcAddress("glDeleteShader"));
	if (glDeleteShader == nullptr)
		assert(!"glDeleteShader not initialized.");

	 glUseProgram = reinterpret_cast<PFNGLUSEPROGRAMPROC>(wglGetProcAddress("glUseProgram"));
	if (glUseProgram == nullptr)
		assert(!"glUseProgram not initialized.");


	// Vertex arrays
	glGenVertexArrays = reinterpret_cast<PFNGLGENVERTEXARRAYSPROC>(wglGetProcAddress("glGenVertexArrays"));
	if (glGenVertexArrays == nullptr)
		assert(!"glGenVertexArrays not initialized.");

	glBindVertexArray = reinterpret_cast<PFNGLBINDVERTEXARRAYPROC>(wglGetProcAddress("glBindVertexArray"));
	if (glBindVertexArray == nullptr)
		assert(!"glBindVertexArray not initialized.");


	// GL drawing
	glDrawArrays = reinterpret_cast<PFNGLDRAWARRAYSEXTPROC>(wglGetProcAddress("glDrawArrays"));
	if (glDrawArrays == nullptr)
		assert(!"glDrawArrays not initialized.");


	// GL point size
	glPointSize = reinterpret_cast<PFNGLPOINTSIZEXOESPROC>(wglGetProcAddress("glPointSize"));
	if (glPointSize == nullptr)
		assert(!"glPointSize not initialized.");
}
