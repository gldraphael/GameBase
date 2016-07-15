#include "GraphicsDevice.h"

//namespace GameBase
//{
	GraphicsDevice::GraphicsDevice(int width, int height, unsigned int bitsPerPixel, bool isFullscreen, bool HardwareBuffering, bool useOpenGL)
	{
		 window = new Surface;
		windowInitialized = false;
		int fs = 0x0, hw = 0x0,gl=0x0 ;		//0x0 code for SWSURFACE
		if (isFullscreen)
			fs = 0x80000000;			//Code for Full Screen
		if (HardwareBuffering)
			hw = 0x00000001;			//Code for HWSURFACE
		if(useOpenGL)
			gl = 0x00000002;
		window->_surface = SDL_SetVideoMode (width, height, bitsPerPixel, fs|hw|gl);
		if(!window)
			throw GameBaseException(SDL_GetError());

		windowInitialized = true;

		viewport.Height = height;
		viewport.Width = width;
		viewport.X = viewport.Y = 0;

		usesGL = useOpenGL;

		if(useOpenGL)
			throw GameBaseException("OpenGL Not Implemented");
	}

	GraphicsDevice::GraphicsDevice(const GraphicsDevice& source)
	{
		viewport = source.viewport;
		usesGL = source.usesGL;
		*window = *source.window;
	}

	GraphicsDevice& GraphicsDevice::operator=(const GraphicsDevice& source)
	{
		if (this == &source)
			return *this;
		viewport = source.viewport;
		usesGL = source.usesGL;
		*window = *source.window;
		return *this;
	}

	Viewport GraphicsDevice::Viewport()
	{
		return viewport;
	}

	SDL_Surface* GraphicsDevice::Window()
	{
		return window->GetSurface();
	}

	void GraphicsDevice::ToggleFullScreen()
	{
		SDL_WM_ToggleFullScreen(window->_surface);
	}

	void GraphicsDevice::Clear (Color& color)
	{
		SDL_FillRect(window->_surface,
			&(SDL_Rect) Rectangle(0, 0, static_cast<float>(viewport.Width), static_cast<float>(viewport.Height) ),
			SDL_MapRGB(window->_surface->format,
			color.R(),color.G(),color.B())
			);
	}

	void GraphicsDevice::Draw()
	{
		if(usesGL)
			SDL_GL_SwapBuffers();
		else if(SDL_Flip(window->_surface) == -1)
			throw GameBaseException(SDL_GetError());
	}

	GraphicsDevice::~GraphicsDevice(void)
	{
		delete window;
	}
//}