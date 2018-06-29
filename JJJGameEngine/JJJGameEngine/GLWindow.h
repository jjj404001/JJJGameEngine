#pragma once
#include <Windows.h>
#include "OpenGL_functions.h"
#include "Timer.h"
#include "Color.h"

#define CLASS_NAME "JJJsEngine"

struct Attributes;

class GLWindow
{
	HINSTANCE hInstance_ = nullptr;
	int nCmdShow_ = SW_SHOWNORMAL;

	HWND hWnd_ = nullptr;
	HDC device_context_ = nullptr;
	HGLRC rendering_context_ = nullptr;
	MSG Message_ = {};
	WNDCLASS WndClass_ = {};
	POINTS MousePos_ = {};
	Color clear_color_;

	PIXELFORMATDESCRIPTOR PFD_ = {};
	int PFDID_ = NULL;
	int PixelFormat_ = NULL;
	int pixelFormatID_ = 0;
	UINT numFormats_ = 0;

	Timer timer;
	OpenGLFunctions opengl_functions_;


	// Timing numbers.
	unsigned int fps = 0;
	double ellapsed_time = 0.0;

	unsigned int previous_fps = 0;
	double previous_ellapsed_time = 0.0;
public:
	int major_version = 4;
	int minor_version = 0;
	bool is_fullscreen = false;
	bool quit = false;
	bool vsync_on = true;


	void Register_OpenGL_Class(bool is_fake);
	bool Create_Old_Context();
	bool Create_Context(const Attributes input_attrib, GLWindow& fake);
	bool Destroy_Old_Context();
	void PrintFPS(double input_duration);

	bool InitOpenGL();

	void Update();

	HWND& GetHWND() { return hWnd_; }
	OpenGLFunctions& GetFunctions() { return opengl_functions_; }
};
