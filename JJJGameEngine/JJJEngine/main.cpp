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
		main_opengl.quit = true;
		return 0;
	case WM_SIZE:
		break;
	case WM_DESTROY: //if mouse is moved.
		break;
	case WM_KEYDOWN:
	{
		main_opengl.Input_KeyDown(wParam, lParam);
	}
	break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	return 0;
}