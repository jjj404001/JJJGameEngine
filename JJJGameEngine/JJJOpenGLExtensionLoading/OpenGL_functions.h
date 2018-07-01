#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include "glext.h"
#include "wglext.h"



struct OpenGLFunctions
{
	// Windows
	PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = nullptr;
	PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = nullptr;
	PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = nullptr;
	PFNWGLGETSWAPINTERVALEXTPROC wglGetSwapIntervalEXT = nullptr;
	// GL buffers
	PFNGLCLEARBUFFERFVPROC glClearBufferfv = nullptr;
	PFNGLCLEARBUFFERIVPROC glClearBufferiv = nullptr;
	PFNGLCLEARBUFFERUIVPROC glClearBufferuiv = nullptr;
	PFNGLCLEARBUFFERFIPROC glClearBufferfi = nullptr;
	// GL shaders
	PFNGLCREATESHADERPROC glCreateShader = nullptr;
	PFNGLSHADERSOURCEPROC glShaderSource = nullptr;
	PFNGLCOMPILESHADERPROC glCompileShader = nullptr;
	PFNGLCREATEPROGRAMPROC glCreateProgram = nullptr;
	PFNGLATTACHSHADERPROC glAttachShader = nullptr;
	PFNGLLINKPROGRAMPROC glLinkProgram = nullptr;
	PFNGLDELETESHADERPROC glDeleteShader = nullptr;
	PFNGLUSEPROGRAMPROC glUseProgram = nullptr;

	// GL vertex arrays
	PFNGLGENVERTEXARRAYSPROC glGenVertexArrays = nullptr;
	PFNGLBINDVERTEXARRAYPROC glBindVertexArray = nullptr;



	// GL drawing extension
	//PFNGLDRAWARRAYSEXTPROC glDrawArraysEXT = nullptr;


	void InitOpenGLFunctions();
};