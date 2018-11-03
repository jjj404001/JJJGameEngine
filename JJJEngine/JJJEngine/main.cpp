#include "GLWindow.h"


#define MS_PER_UPDATE 0.02

GLWindow main_opengl;
int main()
{
	
	main_opengl.Initialize();


	double lag = 0.0;
	while (!main_opengl.quit)
	{
		main_opengl.StartClock();
		lag += main_opengl.delta_time;


		while (lag >= MS_PER_UPDATE)
		{
			main_opengl.Update();
			lag -= MS_PER_UPDATE;
		}

		// I guess render does not needs any delta time...?
		main_opengl.Render();



		main_opengl.EndClockAndPrintFPS();
	}

	main_opengl.Close();


	return 0;
}
