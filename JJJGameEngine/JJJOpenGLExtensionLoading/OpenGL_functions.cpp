#include "OpenGL_functions.h"
#include <cassert>

// Windows
PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = nullptr;
PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = nullptr;
PFNWGLSWAPINTERVALEXTPROC wglSwapIntervalEXT = nullptr;
PFNWGLGETSWAPINTERVALEXTPROC wglGetSwapIntervalEXT = nullptr;
// GL buffers
PFNGLGENBUFFERSPROC glGenBuffers = nullptr;
PFNGLBINDBUFFERPROC glBindBuffer = nullptr;
PFNGLBUFFERDATAPROC	glBufferData = nullptr;
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
PFNGLGETSHADERIVPROC glGetShaderiv = nullptr;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog = nullptr;
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation = nullptr;
PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv = nullptr;
PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv = nullptr;
// GL vertex arrays
PFNGLGENVERTEXARRAYSPROC glGenVertexArrays = nullptr;
PFNGLBINDVERTEXARRAYPROC glBindVertexArray = nullptr;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray = nullptr;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer = nullptr;

// GL drawing
PFNGLDRAWARRAYSEXTPROC glDrawArraysEXT = nullptr;
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

	glUniformMatrix3fv = reinterpret_cast<PFNGLUNIFORMMATRIX3FVPROC>(wglGetProcAddress("glUniformMatrix3fv"));
	if (glUniformMatrix3fv == nullptr)
		assert(!"glUniformMatrix3fv not initialized.");

	glUniformMatrix4fv = reinterpret_cast<PFNGLUNIFORMMATRIX4FVPROC>(wglGetProcAddress("glUniformMatrix4fv"));
	if (glUniformMatrix4fv == nullptr)
		assert(!"glUniformMatrix4fv not initialized.");



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

	glGetUniformLocation = reinterpret_cast<PFNGLGETUNIFORMLOCATIONPROC>(wglGetProcAddress("glGetUniformLocation"));
	if (glGetUniformLocation == nullptr)
		assert(!"glGetUniformLocation not initialized.");

	// GL drawing
	glDrawArraysEXT = reinterpret_cast<PFNGLDRAWARRAYSEXTPROC>(wglGetProcAddress("glDrawArraysEXT"));
	if (glDrawArraysEXT == nullptr)
		assert(!"glDrawArrays not initialized.");
}
