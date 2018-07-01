#include "GLWindow.h"




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

	main_opengl.Close();


	return 0;
}
