#include "GLWindow.h"
#include "resource.h"
#include <iostream>
#include <string>



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
	if (!wglChoosePixelFormatARB(device_context_, input_attrib.pixelAttribs, nullptr, 1, &fake.pixelFormatID_, &fake.numFormats_) || fake.numFormats_ == 0)
		return true;



	DescribePixelFormat(device_context_, fake.pixelFormatID_, sizeof(PFD_), &PFD_);
	SetPixelFormat(device_context_, fake.pixelFormatID_, &PFD_);




	rendering_context_ = wglCreateContextAttribsARB(device_context_, nullptr, input_attrib.contextAttribs);
	if (rendering_context_ == nullptr)
		return true;

	// Destroy fake window after get rendering context.
	fake.Destroy_Old_Context();

	if (!wglMakeCurrent(device_context_, rendering_context_))
		return false;


	ShowWindow(hWnd_, nCmdShow_);

	

	return true;
}

void GLWindow::Destroy_Old_Context() const
{
	wglMakeCurrent(nullptr, nullptr);
	wglDeleteContext(rendering_context_);
	ReleaseDC(hWnd_, device_context_);
	DestroyWindow(hWnd_);
}

void GLWindow::StartClock()
{
	timer.Clock_Start();
}

void GLWindow::EndClockAndPrintFPS()
{
	const auto duration = timer.Clock_End();

	delta_time = duration;
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

bool GLWindow::InitOpenGL()
{
	InitOpenGLFunctions();

	return true;
}

void GLWindow::Initialize()
{
	GLWindow fake_window;

#define NOT_FAKE false
#define FAKE true

	Register_OpenGL_Class(NOT_FAKE);
	fake_window.Register_OpenGL_Class(FAKE);
	fake_window.Create_Old_Context();

	// Set attrib
	const Attributes attributes(major_version, minor_version);


	Create_Context(attributes, fake_window);



	SetActiveWindow(GetHWND());
	graphics_.Initialize();
}

void GLWindow::Update()
{
	if (PeekMessage(&Message_, nullptr, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&Message_);
		DispatchMessage(&Message_);
	}
}

void GLWindow::Render()
{
	GLfloat red[] = { 0.0f, 0.7f, 0.0f, 1.0f};
	glClearBufferfv(GL_COLOR, 0, red);


	graphics_.Update();


	SwapBuffers(device_context_);
}

void GLWindow::Close()
{
	graphics_.Free();
}

void GLWindow::ResizeOpenGLViewport() const
{
	if (hWnd_ == nullptr)
		return;

	RECT rRect;

	// Extend
	GetClientRect(hWnd_, &rRect);

	glViewport(-1, -1, rRect.right, rRect.bottom); // Set viewport
	// deprecated in 4.0 : glOrtho(0, 0, rRect.right, rRect.top, 1, -1);
	// Use orthogonal matrix inside shader.
	// deprecated in 4.0 : glMatrixMode(GL_PROJECTION);
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
