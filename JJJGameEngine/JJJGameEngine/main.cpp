#include "Affine2d.hpp"
#include <iostream>
#include <OpenGL_functions.h>
#include "GLWindow.h"
#include "Attributes.h"



GLWindow main_opengl;
int main()
{
	
	main_opengl.Initialize();

	while (!main_opengl.quit)
	{
		main_opengl.StartClock();
		main_opengl.Update();
		main_opengl.EndClockAndPrintFPS();
	}


	return 0;
}
