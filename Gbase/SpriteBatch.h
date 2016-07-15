#pragma once
#include "GraphicsDevice.h"

// The text rendering modes
enum class TextRenderMode
{
	// Use SOLID for 8bit paletted quick surfaces
	SOLID,
	// Use BLENDED for 32bit pixel-alpha enabled surfaces
	BLENDED
};

// Forward declaration
typedef struct _TTF_Font TTF_Font;

// This class contains the video drawing functions
class SpriteBatch
{
private:
	GraphicsDevice* graphicsDevice;

public:
	// Pass the game's graphic device
	SpriteBatch(GraphicsDevice* graphicsDevice);
	// SpriteBatch(const SpriteBatch& source);
	// SpriteBatch &operator = (const SpriteBatch& source);

	// Draws surface to destinationRectangle
	void Draw(Surface& surface, Rectangle& destinationRectangle);
	void Draw(Surface& surface, Rectangle& destinationRectangle, Color& color);

	//     Adds a sprite to a batch of sprites for rendering using the specified surface,
	//     position and color
	void Draw(Surface& surface, Point& position);
	void Draw(Surface& surface, Point& position, Color& color);

	//     Adds a sprite to a batch of sprites for rendering using the specified texture,
	//     destination rectangle, source rectangle, and color.
	void Draw(Surface& surface, Rectangle& destinationRectangle, Rectangle& sourceRectangle);
	void Draw(Surface& surface, Rectangle& destinationRectangle, Rectangle& sourceRectangle, Color& color);

	//     Adds a sprite to a batch of sprites for rendering using the specified texture,
	//     position, source rectangle, and color.
	void Draw(Surface& surface, Point& position, Rectangle& sourceRectangle);
	void Draw(Surface& surface, Point& position, Rectangle& sourceRectangle, Color& color);

	//     Adds a string to a batch of sprites for rendering using the specified font,
	//     text, position, and color.
	void DrawString(TTF_Font* spriteFont, std::string& text, Point& position, Color& color,TextRenderMode mode = TextRenderMode::BLENDED);

	//     Adds a string to a batch of sprites for rendering using the specified font,
	//     text, position, and color.
	void DrawString(TTF_Font* spriteFont, std::stringstream& text, Point& position, Color& color,TextRenderMode mode = TextRenderMode::BLENDED);

	//     Adds a string to a batch of sprites for rendering using the specified font,
	//     text, position, and color.
	void DrawString(TTF_Font* spriteFont, char* text, Point& position, Color& color,TextRenderMode mode = TextRenderMode::BLENDED);

	~SpriteBatch();

};