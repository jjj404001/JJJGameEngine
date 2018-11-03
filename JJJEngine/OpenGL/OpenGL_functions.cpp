#include "OpenGL_functions.h"
#include <cassert>

// Windows
PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = nullptr;
PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = nullptr;
PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = nullptr;
PFNWGLGETSWAPINTERVALEXTPROC wglGetSwapIntervalEXT = nullptr;
// GL buffers
PFNGLACTIVETEXTUREPROC glActiveTexture = nullptr;
PFNGLGENBUFFERSPROC glGenBuffers = nullptr;
PFNGLBINDBUFFERPROC glBindBuffer = nullptr;
PFNGLBUFFERDATAPROC	glBufferData = nullptr;
PFNGLCLEARBUFFERFVPROC glClearBufferfv = nullptr;
PFNGLCLEARBUFFERIVPROC glClearBufferiv = nullptr;
PFNGLCLEARBUFFERUIVPROC glClearBufferuiv = nullptr;
PFNGLCLEARBUFFERFIPROC glClearBufferfi = nullptr;
PFNGLGENERATEMIPMAPPROC glGenerateMipmap = nullptr;
PFNGLDELETEBUFFERSARBPROC glDeleteBuffers = nullptr;
PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays = nullptr;

// GL shaders
PFNGLCREATESHADERPROC glCreateShader = nullptr;
PFNGLSHADERSOURCEPROC glShaderSource = nullptr;
PFNGLCOMPILESHADERPROC glCompileShader = nullptr;
PFNGLCREATEPROGRAMPROC glCreateProgram = nullptr;
PFNGLATTACHSHADERPROC glAttachShader = nullptr;
PFNGLLINKPROGRAMPROC glLinkProgram = nullptr;
PFNGLDELETESHADERPROC glDeleteShader = nullptr;
PFNGLUSEPROGRAMPROC glUseProgram = nullptr;
PFNGLGETSHADERIVPROC glGetShaderiv = nullptr;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog = nullptr;
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation = nullptr;
PFNGLDETACHSHADERPROC glDetachShader = nullptr;
// GL vertex arrays
PFNGLGENVERTEXARRAYSPROC glGenVertexArrays = nullptr;
PFNGLBINDVERTEXARRAYPROC glBindVertexArray = nullptr;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray = nullptr;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer = nullptr;
PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv = nullptr;
PFNGLUNIFORM4IVPROC glUniform4iv = nullptr;
PFNGLUNIFORM2IVPROC glUniform2iv = nullptr;
PFNGLUNIFORM4FVPROC glUniform4fv = nullptr;
PFNGLUNIFORM2FVPROC glUniform2fv = nullptr;
PFNGLUNIFORM3FVPROC glUniform3fv = nullptr;
PFNGLUNIFORM4IPROC glUniform4i = nullptr;
PFNGLUNIFORM4FPROC glUniform4f = nullptr;
PFNGLUNIFORM1IPROC glUniform1i = nullptr;
PFNGLGETUNIFORMIVPROC glGetUniformiv = nullptr;
PFNGLGETUNIFORMFVPROC glGetUniformfv = nullptr;
PFNGLDELETEPROGRAMPROC glDeleteProgram = nullptr;
PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation = nullptr;
// GL drawing
PFNGLDRAWARRAYSEXTPROC glDrawArraysEXT = nullptr;
PFNGLBLENDEQUATIONPROC glBlendEquation = nullptr;
PFNGLBINDSAMPLERPROC glBindSampler = nullptr;
PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate = nullptr;
PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate  = nullptr;
PFNGLGETPROGRAMIVPROC glGetProgramiv	    = nullptr;
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog = nullptr;
void InitOpenGLFunctions()
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
	glActiveTexture = reinterpret_cast<PFNGLACTIVETEXTUREPROC>(wglGetProcAddress("glActiveTexture"));
	if (glActiveTexture == nullptr)
		assert(!"glActiveTexture not initialized.");

	glGenBuffers = reinterpret_cast<PFNGLGENBUFFERSPROC>(wglGetProcAddress("glGenBuffers"));
	if (glGenBuffers == nullptr)
		assert(!"glGenBuffers not initialized.");

	glBindBuffer = reinterpret_cast<PFNGLBINDBUFFERPROC>(wglGetProcAddress("glBindBuffer"));
	if (glBindBuffer == nullptr)
		assert(!"glBindBuffer not initialized.");

	glBufferData = reinterpret_cast<PFNGLBUFFERDATAPROC>(wglGetProcAddress("glBufferData"));
	if (glBufferData == nullptr)
		assert(!"glBufferData not initialized.");

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

	glGenerateMipmap = reinterpret_cast<PFNGLGENERATEMIPMAPPROC>(wglGetProcAddress("glGenerateMipmap"));
	if (glGenerateMipmap == nullptr)
		assert(!"glGenerateMipmap not initialized.");

	glDeleteBuffers = reinterpret_cast<PFNGLDELETEBUFFERSARBPROC>(wglGetProcAddress("glDeleteBuffers"));
	if (glDeleteBuffers == nullptr)
		assert(!"glGenerateMipmap not initialized.");

	glDeleteVertexArrays = reinterpret_cast<PFNGLDELETEVERTEXARRAYSPROC>(wglGetProcAddress("glDeleteVertexArrays"));
	if (glDeleteVertexArrays == nullptr)
		assert(!"glGenerateMipmap not initialized.");

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

	glGetShaderiv = reinterpret_cast<PFNGLGETSHADERIVPROC>(wglGetProcAddress("glGetShaderiv"));
	if (glGetShaderiv == nullptr)
		assert(!"glGetShaderiv not initialized.");

	glGetShaderInfoLog = reinterpret_cast<PFNGLGETSHADERINFOLOGPROC>(wglGetProcAddress("glGetShaderInfoLog"));
	if (glGetShaderInfoLog == nullptr)
		assert(!"glGetShaderInfoLog not initialized.");

	glGetUniformLocation = reinterpret_cast<PFNGLGETUNIFORMLOCATIONPROC>(wglGetProcAddress("glGetUniformLocation"));
	if (glGetUniformLocation == nullptr)
		assert(!"glGetUniformLocation not initialized.");

	glUniformMatrix4fv = reinterpret_cast<PFNGLUNIFORMMATRIX4FVPROC>(wglGetProcAddress("glUniformMatrix4fv"));
	if (glUniformMatrix4fv == nullptr)
		assert(!"glUniformMatrix4fv not initialized.");
	glUniform4iv = reinterpret_cast<PFNGLUNIFORM4IVPROC>(wglGetProcAddress("glUniform4iv"));
	if (glUniform4iv == nullptr) assert(!"glUniform4iv not initialized.");

	glUniform4fv = reinterpret_cast<PFNGLUNIFORM4FVPROC>(wglGetProcAddress("glUniform4fv"));
	if (glUniform4fv == nullptr) assert(!"glUniform4fv not initialized.");

	glUniform3fv = reinterpret_cast<PFNGLUNIFORM3FVPROC>(wglGetProcAddress("glUniform3fv"));
	if (glUniform3fv == nullptr) assert(!"glUniform3fv not initialized.");

	glUniform2fv = reinterpret_cast<PFNGLUNIFORM2FVPROC>(wglGetProcAddress("glUniform2fv"));
	if (glUniform2fv == nullptr) assert(!"glUniform2fv not initialized.");

	glUniform2iv = reinterpret_cast<PFNGLUNIFORM2IVPROC>(wglGetProcAddress("glUniform2iv"));
	if (glUniform2iv == nullptr) assert(!"glUniform2iv not initialized.");

	glUniform4i = reinterpret_cast<PFNGLUNIFORM4IPROC>(wglGetProcAddress("glUniform4i"));
	if (glUniform4i == nullptr) assert(!"glUniform4i not initialized.");

	glUniform4f = reinterpret_cast<PFNGLUNIFORM4FPROC>(wglGetProcAddress("glUniform4f"));
	if (glUniform4f == nullptr) assert(!"glUniform4f not initialized.");

	glUniform1i = reinterpret_cast<PFNGLUNIFORM1IPROC>(wglGetProcAddress("glUniform1i"));
	if (glUniform1i == nullptr) assert(!"glUniform1i not initialized.");

	glGetUniformiv = reinterpret_cast<PFNGLGETUNIFORMIVPROC>(wglGetProcAddress("glGetUniformiv"));
	if (glGetUniformiv == nullptr) assert(!"glGetUniformiv not initialized.");

	glGetUniformfv = reinterpret_cast<PFNGLGETUNIFORMFVPROC>(wglGetProcAddress("glGetUniformfv"));
	if (glGetUniformfv == nullptr) assert(!"glGetUniformfv not initialized.");

	glDeleteProgram = reinterpret_cast<PFNGLDELETEPROGRAMPROC>(wglGetProcAddress("glDeleteProgram"));
	if (glDeleteProgram == nullptr) assert(!"glDeleteProgram not initialized.");

	glDetachShader = reinterpret_cast<PFNGLDETACHSHADERPROC>(wglGetProcAddress("glDetachShader"));
	if (glDetachShader == nullptr) assert(!"glDetachShader not initialized.");


	// Vertex arrays
	glGenVertexArrays = reinterpret_cast<PFNGLGENVERTEXARRAYSPROC>(wglGetProcAddress("glGenVertexArrays"));
	if (glGenVertexArrays == nullptr)
		assert(!"glGenVertexArrays not initialized.");

	glBindVertexArray = reinterpret_cast<PFNGLBINDVERTEXARRAYPROC>(wglGetProcAddress("glBindVertexArray"));
	if (glBindVertexArray == nullptr)
		assert(!"glBindVertexArray not initialized.");

	glEnableVertexAttribArray = reinterpret_cast<PFNGLENABLEVERTEXATTRIBARRAYPROC>(wglGetProcAddress("glEnableVertexAttribArray"));
	if (glEnableVertexAttribArray == nullptr)
		assert(!"glEnableVertexAttribArray not initialized.");

	glVertexAttribPointer = reinterpret_cast<PFNGLVERTEXATTRIBPOINTERPROC>(wglGetProcAddress("glVertexAttribPointer"));
	if (glVertexAttribPointer == nullptr)
		assert(!"glVertexAttribPointer not initialized.");

	glGetAttribLocation = reinterpret_cast<PFNGLGETATTRIBLOCATIONPROC>(wglGetProcAddress("glGetAttribLocation"));
	if (glGetAttribLocation == nullptr)
		assert(!"glGetAttribLocation not initialized.");

	// GL drawing
	glBlendEquation = reinterpret_cast<PFNGLBLENDEQUATIONPROC>(wglGetProcAddress("glBlendEquation"));
	if (glBlendEquation == nullptr) 
		assert(!"glBlendEquation not initialized.");

	glBindSampler = reinterpret_cast<PFNGLBINDSAMPLERPROC>(wglGetProcAddress("glBindSampler"));
	if (glBindSampler == nullptr) 
		assert(!"glBindSampler not initialized.");

	glBlendEquationSeparate = reinterpret_cast<PFNGLBLENDEQUATIONSEPARATEPROC>(wglGetProcAddress("glBlendEquationSeparate"));
	if (glBlendEquationSeparate == nullptr)
		assert(!"glBlendEquationSeparate not initialized.");

	glBlendFuncSeparate = reinterpret_cast<PFNGLBLENDFUNCSEPARATEPROC>(wglGetProcAddress("glBlendFuncSeparate"));
	if (glBlendFuncSeparate == nullptr) 
		assert(!"glBlendFuncSeparate not initialized.");

	glGetProgramiv = reinterpret_cast<PFNGLGETPROGRAMIVPROC>(wglGetProcAddress("glGetProgramiv"));
	if (glGetProgramiv == nullptr)
		assert(!"glGetProgramiv not initialized.");

	glGetProgramInfoLog = reinterpret_cast<PFNGLGETPROGRAMINFOLOGPROC>(wglGetProcAddress("glGetProgramInfoLog"));
	if (glGetProgramInfoLog == nullptr) 
		assert(!"glGetProgramInfoLog not initialized.");


	/*
	glDrawArraysEXT = reinterpret_cast<PFNGLDRAWARRAYSEXTPROC>(wglGetProcAddress("glDrawArraysEXT"));
	if (glDrawArraysEXT == nullptr)
		assert(!"glDrawArraysEXT not initialized.");
	*/
}
