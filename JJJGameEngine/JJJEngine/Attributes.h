#pragma once
#include <gl/GL.h>
#include <wglext.h>



struct Attributes
{
	Attributes(int major_version, int minor_version)
	{
		pixelAttribs[0] = WGL_DRAW_TO_WINDOW_ARB;
		pixelAttribs[1] = GL_TRUE;
		pixelAttribs[2] = WGL_SUPPORT_OPENGL_ARB;
		pixelAttribs[3] = GL_TRUE;
		pixelAttribs[4] = WGL_DOUBLE_BUFFER_ARB;
		pixelAttribs[5] = GL_TRUE;
		pixelAttribs[6] = WGL_PIXEL_TYPE_ARB;
		pixelAttribs[7] = WGL_TYPE_RGBA_ARB;
		pixelAttribs[8] = WGL_COLOR_BITS_ARB;
		pixelAttribs[9] = 32;
		pixelAttribs[10] = WGL_DEPTH_BITS_ARB;
		pixelAttribs[11] = 24;
		pixelAttribs[12] = WGL_STENCIL_BITS_ARB;
		pixelAttribs[13] = 8;
		pixelAttribs[14] = 0;


		contextAttribs[0] = WGL_CONTEXT_MAJOR_VERSION_ARB;
		contextAttribs[1] = major_version;
		contextAttribs[2] = WGL_CONTEXT_MINOR_VERSION_ARB;
		contextAttribs[3] = minor_version;
		contextAttribs[4] = WGL_CONTEXT_PROFILE_MASK_ARB;
		contextAttribs[5] = WGL_CONTEXT_CORE_PROFILE_BIT_ARB;
		contextAttribs[6] = 0;
	}

	int pixelAttribs[255] = { 0, };
	int contextAttribs[255] = { 0, };

	//const int pixelAttribs[] = {
	//	WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
	//	WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
	//	WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
	//	WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
	//	WGL_COLOR_BITS_ARB, 32,
	//	WGL_DEPTH_BITS_ARB, 24,
	//	WGL_STENCIL_BITS_ARB, 8,
	//	0 // End
	//};

	//int  contextAttribs[] = {
	//	WGL_CONTEXT_MAJOR_VERSION_ARB, main_opengl.major_version,
	//	WGL_CONTEXT_MINOR_VERSION_ARB, main_opengl.minor_version,
	//	WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
	//	0
	//};
};
