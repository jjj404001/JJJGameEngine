#pragma once
#include <Windows.h>
#include <gl/GL.h> // For glext.h
#include "glext.h"
#include "wglext.h"




	// Windows
	extern PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB;
	extern PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB;
	extern PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT;
	extern PFNWGLGETSWAPINTERVALEXTPROC wglGetSwapIntervalEXT;
	// GL buffers
	extern PFNGLGENBUFFERSPROC glGenBuffers;
	extern PFNGLBINDBUFFERPROC glBindBuffer;
	extern PFNGLBUFFERDATAPROC	glBufferData;
	extern PFNGLCLEARBUFFERFVPROC glClearBufferfv;
	extern PFNGLCLEARBUFFERIVPROC glClearBufferiv;
	extern PFNGLCLEARBUFFERUIVPROC glClearBufferuiv;
	extern PFNGLCLEARBUFFERFIPROC glClearBufferfi;
	// GL shaders
	extern PFNGLCREATESHADERPROC glCreateShader;
	extern PFNGLSHADERSOURCEPROC glShaderSource;
	extern PFNGLCOMPILESHADERPROC glCompileShader;
	extern PFNGLCREATEPROGRAMPROC glCreateProgram;
	extern PFNGLATTACHSHADERPROC glAttachShader;
	extern PFNGLLINKPROGRAMPROC glLinkProgram;
	extern PFNGLDELETESHADERPROC glDeleteShader;
	extern PFNGLUSEPROGRAMPROC glUseProgram;
	extern PFNGLGETSHADERIVPROC glGetShaderiv;
	extern PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
	extern PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
	extern PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv;
	// GL vertex arrays
	extern PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
	extern PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
	extern PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
	extern PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;

	// GL drawing
	extern PFNGLDRAWARRAYSEXTPROC glDrawArraysEXT;

	

	void InitOpenGLFunctions();
