#include "SpriteBatch.h"
#include <Extension/SDL_ttf.h>
#include <sstream>

SpriteBatch::SpriteBatch(GraphicsDevice* graphicsDevice)
{
	this->graphicsDevice = graphicsDevice;
}

void SpriteBatch::Draw(Surface& surface, Rectangle& destinationRectangle)
{
	SDL_BlitSurface(surface.GetSurface(), NULL, graphicsDevice->Window(), &(SDL_Rect)destinationRectangle);
}

void SpriteBatch::Draw(Surface& surface, Rectangle& destinationRectangle, Color& color)
{
	SDL_BlitSurface (surface.GetSurface(), NULL, graphicsDevice->Window(), &(SDL_Rect)destinationRectangle);
}

void SpriteBatch::Draw(Surface& surface, Point& position)
{
	SDL_BlitSurface (surface.GetSurface(), NULL, graphicsDevice->Window(), &(SDL_Rect)Rectangle(position,surface.GetSurface()->w,surface.GetSurface()->h));
}

void SpriteBatch::Draw(Surface& surface, Point& position, Color& color)
{
	SDL_BlitSurface (surface.GetSurface(), NULL, graphicsDevice->Window(), &(SDL_Rect)Rectangle(position,surface.GetSurface()->w,surface.GetSurface()->h));
}

void SpriteBatch::Draw(Surface& surface, Rectangle& destinationRectangle, Rectangle& sourceRectangle)
{
	SDL_BlitSurface (surface.GetSurface(), &(SDL_Rect)sourceRectangle, graphicsDevice->Window(), &(SDL_Rect)destinationRectangle);
}

void SpriteBatch::Draw(Surface& surface, Rectangle& destinationRectangle, Rectangle& sourceRectangle, Color& color)
{
	SDL_BlitSurface (surface.GetSurface(), &(SDL_Rect)sourceRectangle, graphicsDevice->Window(), &(SDL_Rect)destinationRectangle);
}

void SpriteBatch::Draw(Surface& surface, Point& position, Rectangle& sourceRectangle)
{
	SDL_BlitSurface (surface.GetSurface(), &((SDL_Rect)sourceRectangle), graphicsDevice->Window(), &(SDL_Rect)Rectangle(position, sourceRectangle.Width, sourceRectangle.Height));
}

void SpriteBatch::Draw(Surface& surface, Point& position, Rectangle& sourceRectangle, Color& color)
{
	Rectangle drect(position, sourceRectangle.Width, sourceRectangle.Height);
	SDL_BlitSurface (surface.GetSurface(), &((SDL_Rect)sourceRectangle), graphicsDevice->Window(), &((SDL_Rect)drect));
}

void SpriteBatch::DrawString(TTF_Font* font, std::string& text, Point& position, Color& color,TextRenderMode mode)
{
	if (text == "")
		return;
	if (mode == TextRenderMode::SOLID)
		Draw(Surface ( TTF_RenderText_Solid(font, text.c_str(), color)) ,position,color );
	else
		Draw(Surface ( TTF_RenderText_Blended(font, text.c_str(), color)) ,position,color );
}

void SpriteBatch::DrawString(TTF_Font* font, std::stringstream& text, Point& position, Color& color,TextRenderMode mode)
{
	if (text == "")
		return;
	if(mode == TextRenderMode::SOLID)
		Draw(Surface (TTF_RenderText_Solid(font, text.str().c_str(), color)) ,position);
	else
		Draw(Surface (TTF_RenderText_Blended(font, text.str().c_str(), color)) ,position);
}

void SpriteBatch::DrawString(TTF_Font* font, char* text, Point& position, Color& color,TextRenderMode mode)
{
	if (text == "")
		return;
	if(mode == TextRenderMode::SOLID)
		Draw(Surface (TTF_RenderText_Solid(font, text, color)) ,position);
	else
		Draw(Surface (TTF_RenderText_Blended(font, text, color)) ,position);
}

SpriteBatch::~SpriteBatch(void)
{

}