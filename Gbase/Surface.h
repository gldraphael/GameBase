// 23 September, 2012
#pragma once

#include <SDL.h>
#include <string>
//class GraphicsDevice;

	// The 14 formats supported by the SDL_Image Library
	// The appropriate dlls will be required
	enum class ImageFormat
	{
		BMP = 0,
		PNG,
		JPG,
		TIF,
		WEPG,
		CUR,
		GIF,
		ICO,
		LBM,
		PCX,
		PNM,
		XCF,
		XPM,
		XV,
		OTHER	// Use this if a file format is supported by SDL_Image but not included in ImageFormat
	};

	// This class encapsulates an SDL_Surface
	// No need to call SDL_FreeSurface()
	// You could manipulate the SDL_Surface* of the object manually using Surface::GetSurface()
	class Surface
	{
	private:
		SDL_Surface* _surface;
		friend class GraphicsDevice;
	public:
		Surface();
		Surface(SDL_Surface* surface);
		Surface(const Surface& source);
		Surface& operator= (const Surface& source);

		// Returns the SDL_Surface* associated with the Surface object
		SDL_Surface* GetSurface();
		// Returns a copy of the current surface
		Surface GetCopy();
		// Returns the Width of the Surface
		int Width();
		// Returns the Height of the Surface
		int Height();

		// Scales an SDL Surface to the required width x height.
		// Executes slowly. Consider calling this during Splash Screens.
		Surface ScaleSurface(Surface& surface, uint16_t Width, uint16_t Height);

		// Reads the pixel from the (x,y) of surface
		static uint32_t ReadPixel(Surface& surface, int x, int y);

		// Draws pixel to (x,y) of surface
		static void DrawPixel(Surface& surface, int x, int y, uint32_t pixel);

		// Loads the Surface from the image file of the format imageFormat
		static Surface Load( std::string filename, ImageFormat imageFormat = ImageFormat::BMP);
		// Loads the Surface from the image file of the format imageFormat and sets colorKey to transparent
		static Surface Load( std::string filename, ImageFormat imageFormat, SDL_Color colorKey);

		// Frees the surface
		void Free();

		~Surface();
	};
//}