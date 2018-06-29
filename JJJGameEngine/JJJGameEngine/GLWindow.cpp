#include "GLWindow.h"
#include "resource.h"
#include "Attributes.h"
#include "OpenGL_functions.h"
#include <iostream>


// Prototype
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void GLWindow::Register_OpenGL_Class(bool is_fake)
{
	hInstance = GetModuleHandle(nullptr);


	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	WndClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	WndClass.hInstance = hInstance;
	WndClass.hCursor = LoadCursor(hInstance, IDC_ARROW);
	if (is_fake)
		WndClass.lpfnWndProc = DefWindowProc;
	else
		WndClass.lpfnWndProc = static_cast<WNDPROC>(WndProc);
	WndClass.lpszClassName = CLASS_NAME;
	WndClass.lpszMenuName = nullptr;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;



	RegisterClass(&WndClass);
}

bool GLWindow::Create_Old_Context()
{
	hWnd = CreateWindowEx(WS_EX_APPWINDOW, CLASS_NAME, CLASS_NAME, WS_OVERLAPPEDWINDOW,
	                      CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
	                      nullptr, static_cast<HMENU>(nullptr), hInstance, nullptr);

	device_context = GetDC(hWnd);        // Device Context



	ZeroMemory(&PFD, sizeof(PFD));
	PFD.nSize = sizeof(PFD);
	PFD.nVersion = 1;
	PFD.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	PFD.iPixelType = PFD_TYPE_RGBA;
	PFD.cColorBits = 32;
	PFD.cAlphaBits = 8;
	PFD.cDepthBits = 24;
	PFD.iLayerType = PFD_MAIN_PLANE;



	PixelFormat = ChoosePixelFormat(device_context, &PFD);
	if (!PixelFormat)
		return false;

	if (!SetPixelFormat(device_context, PixelFormat, &PFD))
		return false;



	rendering_context = wglCreateContext(device_context);
	wglMakeCurrent(device_context, rendering_context);

	return true;
}


bool GLWindow::Create_Context(const Attributes input_attrib, GLWindow& fake)
{
	hWnd = CreateWindowEx(WS_EX_APPWINDOW, CLASS_NAME, CLASS_NAME, WS_OVERLAPPEDWINDOW,
	                      CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
	                      nullptr, static_cast<HMENU>(nullptr), hInstance, nullptr);

	device_context = GetDC(hWnd);

	PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = nullptr;
	wglChoosePixelFormatARB = reinterpret_cast<PFNWGLCHOOSEPIXELFORMATARBPROC>(wglGetProcAddress("wglChoosePixelFormatARB"));
	if (wglChoosePixelFormatARB == nullptr) {
		//Check.
	}


	PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = nullptr;
	wglCreateContextAttribsARB = reinterpret_cast<PFNWGLCREATECONTEXTATTRIBSARBPROC>(wglGetProcAddress("wglCreateContextAttribsARB"));
	if (wglCreateContextAttribsARB == nullptr) {
		//Check.
	}


	const bool status = wglChoosePixelFormatARB(device_context, input_attrib.pixelAttribs, nullptr, 1, &fake.pixelFormatID, &fake.numFormats);

	if (!status || fake.numFormats == 0)
		return true;



	DescribePixelFormat(device_context, fake.pixelFormatID, sizeof(PFD), &PFD);
	SetPixelFormat(device_context, fake.pixelFormatID, &PFD);




	rendering_context = wglCreateContextAttribsARB(device_context, 0, input_attrib.contextAttribs);
	if (rendering_context == nullptr)
		return true;


	fake.Destroy_Old_Context();

	if (!wglMakeCurrent(device_context, rendering_context))
		return false;


	ShowWindow(hWnd, nCmdShow);



	return true;
}

bool GLWindow::Destroy_Old_Context()
{
	wglMakeCurrent(nullptr, nullptr);
	wglDeleteContext(rendering_context);
	ReleaseDC(hWnd, device_context);
	DestroyWindow(hWnd);



	return true;
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
