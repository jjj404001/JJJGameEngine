#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include "glext.h"
#include "wglext.h"



// Program
#define glCreateProgram (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
#define glDeleteProgram = (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
#define glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
#define glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
#define glDetachShader = (PFNGLDETACHSHADERPROC)wglGetProcAddress("glDetachShader");
#define glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
#define glGetProgramiv = (PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
#define glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
#define glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
#define glUniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
#define glUniform1iv = (PFNGLUNIFORM1IVPROC)wglGetProcAddress("glUniform1iv");
#define glUniform2iv = (PFNGLUNIFORM2IVPROC)wglGetProcAddress("glUniform2iv");
#define glUniform3iv = (PFNGLUNIFORM3IVPROC)wglGetProcAddress("glUniform3iv");
#define glUniform4iv = (PFNGLUNIFORM4IVPROC)wglGetProcAddress("glUniform4iv");
#define glUniform1f = (PFNGLUNIFORM1FPROC)wglGetProcAddress("glUniform1f");
#define glUniform1fv = (PFNGLUNIFORM1FVPROC)wglGetProcAddress("glUniform1fv");
#define glUniform2fv = (PFNGLUNIFORM2FVPROC)wglGetProcAddress("glUniform2fv");
#define glUniform3fv = (PFNGLUNIFORM3FVPROC)wglGetProcAddress("glUniform3fv");
#define glUniform4fv = (PFNGLUNIFORM4FVPROC)wglGetProcAddress("glUniform4fv");
#define glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");
#define glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)wglGetProcAddress("glGetAttribLocation");
#define glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)wglGetProcAddress("glVertexAttrib1f");
#define glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)wglGetProcAddress("glVertexAttrib1fv");
#define glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)wglGetProcAddress("glVertexAttrib2fv");
#define glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)wglGetProcAddress("glVertexAttrib3fv");
#define glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)wglGetProcAddress("glVertexAttrib4fv");
#define glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
#define glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)wglGetProcAddress("glBindAttribLocation");

// Shader
#define glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
#define glDeleteShader = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
#define glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
#define glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
#define glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");

// VBO
#define glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
#define glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
#define glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
#define glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");