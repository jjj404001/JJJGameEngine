#include "Affine2d.hpp"
#include <iostream>
#include "Vector2.hpp"
#include  "Quaternion.h"
#include <OpenGL_functions.h>
#include "GLWindow.h"
#include "Attributes.h"

#define NOT_FAKE false
#define FAKE true

GLWindow main_opengl;
int main()
{
	GLWindow fake_window;

	
	main_opengl.Register_OpenGL_Class(NOT_FAKE);
	fake_window.Register_OpenGL_Class(FAKE);
	fake_window.Create_Old_Context();

	// Set attrib
	Attributes attributes(main_opengl.major_version, main_opengl.minor_version);

	main_opengl.Create_Context(attributes, fake_window);



	SetActiveWindow(main_opengl.GetHWND());


	return 0;
}
