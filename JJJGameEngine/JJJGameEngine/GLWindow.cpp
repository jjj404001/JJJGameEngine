#include <OpenGL_functions.h>
#include <iostream>
#include <string>

#include "GLWindow.h"
#include "resource.h"
#include "Attributes.h"

#define GREEN 0.0f, 0.586f, 0.0f, 1.0f
// Prototype
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void GLWindow::Register_OpenGL_Class(bool is_fake)
{
	hInstance_ = GetModuleHandle(nullptr);


	WndClass_.cbClsExtra = 0;
	WndClass_.cbWndExtra = 0;
	WndClass_.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	WndClass_.hIcon = LoadIcon(hInstance_, MAKEINTRESOURCE(IDI_ICON1));
	WndClass_.hInstance = hInstance_;
	WndClass_.hCursor = LoadCursor(hInstance_, IDC_ARROW);
	if (is_fake)
		WndClass_.lpfnWndProc = DefWindowProc;
	else
		WndClass_.lpfnWndProc = static_cast<WNDPROC>(WndProc);
	WndClass_.lpszClassName = CLASS_NAME;
	WndClass_.lpszMenuName = nullptr;
	WndClass_.style = CS_HREDRAW | CS_VREDRAW;



	RegisterClass(&WndClass_);
}

bool GLWindow::Create_Old_Context()
{
	hWnd_ = CreateWindowEx(WS_EX_APPWINDOW, CLASS_NAME, CLASS_NAME, WS_OVERLAPPEDWINDOW,
	                      CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
	                      nullptr, static_cast<HMENU>(nullptr), hInstance_, nullptr);

	device_context_ = GetDC(hWnd_);        // Device Context



	ZeroMemory(&PFD_, sizeof(PFD_));
	PFD_.nSize = sizeof(PFD_);
	PFD_.nVersion = 1;
	PFD_.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	PFD_.iPixelType = PFD_TYPE_RGBA;
	PFD_.cColorBits = 32;
	PFD_.cAlphaBits = 8;
	PFD_.cDepthBits = 24;
	PFD_.iLayerType = PFD_MAIN_PLANE;



	PixelFormat_ = ChoosePixelFormat(device_context_, &PFD_);
	if (!PixelFormat_)
		return false;

	if (!SetPixelFormat(device_context_, PixelFormat_, &PFD_))
		return false;



	rendering_context_ = wglCreateContext(device_context_);
	wglMakeCurrent(device_context_, rendering_context_);

	return true;
}


bool GLWindow::Create_Context(const Attributes input_attrib, GLWindow& fake)
{
	hWnd_ = CreateWindowEx(WS_EX_APPWINDOW, CLASS_NAME, CLASS_NAME, WS_OVERLAPPEDWINDOW,
	                      CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
	                      nullptr, static_cast<HMENU>(nullptr), hInstance_, nullptr);

	device_context_ = GetDC(hWnd_);

	// Initialize opengl functions.
	InitOpenGL();


	// If faile to choose pixelformat or number of pixelformat is 0.
	if (!opengl_functions_.wglChoosePixelFormatARB(device_context_, input_attrib.pixelAttribs, nullptr, 1, &fake.pixelFormatID_, &fake.numFormats_) || fake.numFormats_ == 0)
		return true;



	DescribePixelFormat(device_context_, fake.pixelFormatID_, sizeof(PFD_), &PFD_);
	SetPixelFormat(device_context_, fake.pixelFormatID_, &PFD_);




	rendering_context_ = opengl_functions_.wglCreateContextAttribsARB(device_context_, 0, input_attrib.contextAttribs);
	if (rendering_context_ == nullptr)
		return true;

	// Destroy fake window after get rendering context.
	fake.Destroy_Old_Context();

	if (!wglMakeCurrent(device_context_, rendering_context_))
		return false;


	ShowWindow(hWnd_, nCmdShow_);



	return true;
}

bool GLWindow::Destroy_Old_Context()
{
	wglMakeCurrent(nullptr, nullptr);
	wglDeleteContext(rendering_context_);
	ReleaseDC(hWnd_, device_context_);
	DestroyWindow(hWnd_);



	return true;
}

bool GLWindow::InitOpenGL()
{
	opengl_functions_.InitOpenGLFunctions();

	return true;
}

void GLWindow::Update()
{
	timer.Clock_Start();

	if (vsync_on)
		opengl_functions_.wglSwapIntervalEXT(1);
	else
		opengl_functions_.wglSwapIntervalEXT(0);






	if (PeekMessage(&Message_, nullptr, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&Message_);
		DispatchMessage(&Message_);
	}



	//graphic.SetPolyMode(GL_LINE);
	//glPolygonMode(GL_FRONT_AND_BACK, graphic.GetPolyMode());
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glClearColor(GREEN);
	glClear(GL_COLOR_BUFFER_BIT);
	SwapBuffers(device_context_);


	const auto duration = timer.Clock_End();

	ellapsed_time += duration;
	fps++;

	const auto name = CLASS_NAME + (" FPS : " + std::to_string(previous_fps));
	const auto name_additional = " Ellapsed time between frame : " + std::to_string(previous_ellapsed_time);


	SetWindowText(hWnd_, (name + name_additional).c_str());

	if (ellapsed_time > 1.0)
	{
		std::cout << "FPS  : " << fps << std::endl;
		std::cout << "TIME : " << ellapsed_time << std::endl;

		previous_fps = fps;
		previous_ellapsed_time = ellapsed_time;

		fps = 0;
		ellapsed_time = 0.0;
	}
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	switch (msg)
	{
		case WM_PAINT:
			BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			break;
		case WM_CLOSE:
			PostQuitMessage(0);
			return 0;
		case WM_SIZE:
			break;
		case WM_DESTROY: //if mouse is moved.
			break;
		default:
			return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}
