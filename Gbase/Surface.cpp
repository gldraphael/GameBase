#include "Surface.h"
#include "GameBaseException.h"
#include <Extension/SDL_image.h>

//namespace GameBase
//{
Surface::Surface()
{
	this->_surface = NULL;
}

Surface::Surface(SDL_Surface* surface)
{
	_surface = SDL_ConvertSurface(surface,surface->format,surface->flags);
}

Surface::Surface(const Surface& source)
{
	if(source._surface)
	{
		_surface = source._surface;
		source._surface->refcount++;
	}
	//else source._surface = NULL;
}

Surface& Surface::operator= (const Surface& source)
{
	if (this == &source)
		return *this;

	if(_surface)
		SDL_FreeSurface(_surface);

	if(source._surface)
	{
		_surface = source._surface;
		source._surface->refcount++;
		// _surface = SDL_ConvertSurface(source._surface,
		//	SDL_GetVideoSurface()->format,
		//	source._surface->flags
		//	);
	//if(_surface == NULL)
			//throw GameBaseException();
	}
	return *this;
}

SDL_Surface* Surface::GetSurface()
{
	return this->_surface;
}

Surface Surface::GetCopy()
{
	Surface s;
	if (this->_surface)
		s._surface = SDL_ConvertSurface(_surface,
			SDL_GetVideoSurface()->format,
			_surface->flags
			);
	return s;
}

int Surface::Width()
{
	return _surface->w;
}

int Surface::Height()
{
	return _surface->h;
}

Surface::~Surface(void)
{
	if(_surface)
		SDL_FreeSurface(_surface);
}

Surface Surface::Load( std::string filename , ImageFormat imageFormat)
{
	Surface loadedImage, optimizedImage;
	switch (imageFormat)
	{
		// Load BMPs using SDL
	case ImageFormat::BMP:
		loadedImage._surface = SDL_LoadBMP( filename.c_str() );
		if( loadedImage._surface != NULL )
		{
			optimizedImage._surface = SDL_DisplayFormat( loadedImage._surface );
		}
		else throw GameBaseException(SDL_GetError());
		break;

		// Load PNG using SDL_Image and give support to alpha
	case ImageFormat::PNG:
		loadedImage._surface = IMG_Load( filename.c_str() );
		if( loadedImage._surface != NULL )
		{
			optimizedImage._surface = SDL_DisplayFormatAlpha (loadedImage._surface);
		}
		else throw GameBaseException(SDL_GetError());
		break;

	case ImageFormat::JPG:
	case ImageFormat::TIF:
	case ImageFormat::WEPG:
	case ImageFormat::CUR:
	case ImageFormat::GIF:
	case ImageFormat::ICO:
	case ImageFormat::LBM:
	case ImageFormat::PCX:
	case ImageFormat::PNM:
	case ImageFormat::XCF:
	case ImageFormat::XPM:
	case ImageFormat::XV:
	case ImageFormat::OTHER:
		loadedImage._surface = IMG_Load( filename.c_str() );
		if( loadedImage._surface != NULL )
		{
			optimizedImage._surface = SDL_DisplayFormat( loadedImage._surface );
		}
		else throw GameBaseException(SDL_GetError());
		break;

	default:
		throw GameBaseException("Image Format Not Implemented");
		break;
	} // End of switch

	return optimizedImage;
}

Surface Surface::Load( std::string filename, ImageFormat imageFormat, SDL_Color colorKey)
{
	Surface loadedImage, optimizedImage;
	switch (imageFormat)
	{
		// Load BMPs using SDL
	case ImageFormat::BMP:
		loadedImage._surface = SDL_LoadBMP( filename.c_str() );
		if( loadedImage._surface != NULL )
		{
			// Performing Color keying
			SDL_SetColorKey( loadedImage._surface, SDL_SRCCOLORKEY, SDL_MapRGB (loadedImage._surface->format,colorKey.r,colorKey.g,colorKey.b) );
			optimizedImage._surface = SDL_DisplayFormat( loadedImage._surface );
			//SDL_FreeSurface( loadedImage._surface );
		}
		else throw GameBaseException(SDL_GetError());
		break;

		// Ignore color key to PNGs
	case ImageFormat::PNG:
		loadedImage._surface = IMG_Load( filename.c_str() );
		if( loadedImage._surface != NULL )
		{
			optimizedImage._surface = SDL_DisplayFormatAlpha (loadedImage._surface);
			//SDL_FreeSurface( loadedImage._surface );
		}
		else throw GameBaseException(SDL_GetError());
		break;

		// Apply Color Keys to the rest
	case ImageFormat::JPG:
	case ImageFormat::TIF:
	case ImageFormat::WEPG:
	case ImageFormat::CUR:
	case ImageFormat::GIF:
	case ImageFormat::ICO:
	case ImageFormat::LBM:
	case ImageFormat::PCX:
	case ImageFormat::PNM:
	case ImageFormat::XCF:
	case ImageFormat::XPM:
	case ImageFormat::XV:
		loadedImage._surface = IMG_Load( filename.c_str() );
		if( loadedImage._surface != NULL )
		{
			// Performing Color keying
			SDL_SetColorKey( loadedImage._surface, SDL_SRCCOLORKEY, SDL_MapRGB (loadedImage._surface->format,colorKey.r,colorKey.g,colorKey.b) );
			optimizedImage._surface = SDL_DisplayFormat( loadedImage._surface );
			//SDL_FreeSurface( loadedImage._surface );
		}
		else throw GameBaseException(SDL_GetError());
		break;

	default:
		throw GameBaseException("Image Format Not Implemented");
		break;
	} // End of switch

	return optimizedImage;
}

uint32_t Surface::ReadPixel(Surface& surface, int x, int y)
{
	int bpp = surface._surface->format->BytesPerPixel;
	// Here p is the address to the pixel we want to retrieve
	uint8_t *p = (uint8_t *)surface._surface->pixels + y * surface._surface->pitch + x * bpp;

	switch(bpp) 
	{
	case 1:
		return *p;

	case 2:
		return *(uint16_t *)p;

	case 3:
		if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return p[0] << 16 | p[1] << 8 | p[2];
		else
			return p[0] | p[1] << 8 | p[2] << 16;

	case 4:
		return *(uint32_t *)p;

	}
	return 0;       // shouldn't happen, but avoids warnings
}

void Surface::DrawPixel(Surface& surface, int x, int y, uint32_t pixel)
{
	int bpp = surface._surface->format->BytesPerPixel;
	// Here p is the address to the pixel we want to set
	uint8_t *p = (uint8_t *)surface._surface->pixels + y * surface._surface->pitch + x * bpp;

	switch(bpp) 
	{
	case 1:
		*p = pixel;
		break;
	case 2:
		*(Uint16 *)p = pixel;
		break;
	case 3:
		if(SDL_BYTEORDER == SDL_BIG_ENDIAN) 
		{
			p[0] = (pixel >> 16) & 0xff;
			p[1] = (pixel >> 8) & 0xff;
			p[2] = pixel & 0xff;
		} 
		else 
		{
			p[0] = pixel & 0xff;
			p[1] = (pixel >> 8) & 0xff;
			p[2] = (pixel >> 16) & 0xff;
		}
		break;
	case 4:
		*(Uint32 *)p = pixel;
		break;
	}
}

Surface Surface::ScaleSurface(Surface& surface, uint16_t Width, uint16_t Height)
{
	// If the arguments are invalid
	if(!surface._surface || !Width || !Height)
		return Surface();

	Surface _ret;
	_ret._surface = SDL_CreateRGBSurface(surface._surface->flags, Width, Height, surface._surface->format->BitsPerPixel, surface._surface->format->Rmask, surface._surface->format->Gmask, surface._surface->format->Bmask, surface._surface->format->Amask);
	double _stretch_factor_x = (static_cast<double>(Width)  / static_cast<double>(surface._surface->w)),	_stretch_factor_y = (static_cast<double>(Height) / static_cast<double>(surface._surface->h));

	for(int32_t y = 0; y < surface._surface->h; y++)
		for(int32_t x = 0; x < surface._surface->w; x++)
			for(int32_t o_y = 0; o_y < _stretch_factor_y; ++o_y)
				for(int32_t o_x = 0; o_x < _stretch_factor_x; ++o_x)
					DrawPixel(_ret, static_cast<int32_t>(_stretch_factor_x * x) + o_x, static_cast<int32_t>(_stretch_factor_y * y) + o_y, ReadPixel(surface, x, y));
	return _ret;
}

void Surface::Free()
{
	SDL_FreeSurface(_surface);
	_surface = 0x0;
}
//}