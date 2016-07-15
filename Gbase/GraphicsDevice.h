// 23 September, 2012
#pragma once

#include <string>
#include "structs.h"
#include "Surface.h"
#include "GameBaseException.h"

//#include <SDL_opengl.h>

//namespace GameBase
//{
	//The Graphics Decice
	class  GraphicsDevice
	{
	private:
		bool usesGL;
		Viewport viewport;
		Surface* window;
		// SDL_Surface* window;
		bool windowInitialized;
	public:
		GraphicsDevice(int width, int height, unsigned int bitsPerPixel,  bool isFullscreen = false, bool HardwareBuffering = true, bool useOpenGL = false);
		GraphicsDevice(const GraphicsDevice& source);
		GraphicsDevice& operator=(const GraphicsDevice& cSource);

		void ToggleFullScreen();

		//The viewport of the Window
		Viewport Viewport();
		SDL_Surface* Window();

		//Clears the screen with color
		void Clear (Color& color);

		//Draws the Surface.
		void Draw();
		~GraphicsDevice();
	};
//}