#pragma once
#include <Windows.h>

#define CLASS_NAME "JJJsEngine"

struct Attributes;

class GLWindow
{
	HINSTANCE hInstance = nullptr;
	int nCmdShow = 0;

	HWND hWnd = nullptr;
	HDC device_context = nullptr;
	HGLRC rendering_context = nullptr;
	MSG Message = {};
	WNDCLASS WndClass = {};
	POINTS MousePos = {};


	PIXELFORMATDESCRIPTOR PFD = {};
	int PFDID = NULL;
	int PixelFormat = NULL;
	int pixelFormatID = 0;
	UINT numFormats = 0;

public:
	int major_version = 4;
	int minor_version = 0;
	bool is_fullscreen = false;
	bool quit = false;

	void Register_OpenGL_Class(bool is_fake);
	bool Create_Old_Context();
	bool Create_Context(const Attributes input_attrib, GLWindow& fake);
	bool Destroy_Old_Context();
};
