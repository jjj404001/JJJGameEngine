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
	extern PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
	extern PFNGLACTIVETEXTUREPROC glActiveTexture;
	extern PFNGLDELETEBUFFERSARBPROC glDeleteBuffers;
	extern PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
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
	extern PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
	extern PFNGLUNIFORM4IVPROC glUniform4iv;
	extern PFNGLUNIFORM4FVPROC glUniform4fv;
	extern PFNGLUNIFORM3FVPROC glUniform3fv;
	extern PFNGLUNIFORM2FVPROC glUniform2fv;
	extern PFNGLUNIFORM2IVPROC glUniform2iv;
	extern PFNGLUNIFORM4IPROC glUniform4i;
	extern PFNGLUNIFORM4FPROC glUniform4f;
	extern PFNGLUNIFORM1IPROC glUniform1i;
	extern PFNGLGETUNIFORMIVPROC glGetUniformiv;
	extern PFNGLGETUNIFORMFVPROC glGetUniformfv;
	extern PFNGLDELETEPROGRAMPROC glDeleteProgram;
	extern PFNGLDETACHSHADERPROC glDetachShader;

	// GL vertex arrays
	extern PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
	extern PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
	extern PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
	extern PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
	extern PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;

	// GL drawing
	extern PFNGLDRAWARRAYSEXTPROC glDrawArraysEXT;
	extern PFNGLBLENDEQUATIONPROC glBlendEquation;
	extern PFNGLBINDSAMPLERPROC glBindSampler;
	extern PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate;
	extern PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate;
	extern PFNGLGETPROGRAMIVPROC glGetProgramiv;
	extern PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;


	void InitOpenGLFunctions();
