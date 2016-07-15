// 25/10/12

#pragma once

#include <map>
#include <vector>
#include "structs.h"

typedef struct _TTF_Font TTF_Font;

// The FontManager class manages the fonts during the game
// UNICODE is not supported currently. Using it will throw a GameBaseException
class FontManager
{
public:
#if __cplusplus >= 199711L
	// The encodings supported by the FontManager
	enum class Encoding
	{
		ASCII,
		UTF8,
		UNICODE
	};
#else
	// The encodings supported by the FontManager
	enum Encoding
	{
		ASCII,
		UTF8,
		UNICODE
	};
#endif

private:
	struct data
	{
		TTF_Font* font;
		FontManager::Encoding enc;
		int line_spacing;
	};
	std::map <std::string, data > font_list;
	bool initialized;

	FontManager& operator =(const FontManager);
public:

	FontManager();

	// Load the font from path and size. font_name is used as the key to retrieve it
	// Returns false if error occured.
	// Using UNICODE will throw a GameBaseException
	bool Load(std::string font_name, char* path, unsigned int size, Encoding encoding = Encoding::ASCII);

	// Returns the associated TTF_Font*
	TTF_Font* operator[](std::string font_name);
	// Returns the associated TTF_Font*
	// Deprecated: Use the [] operator instead
	TTF_Font* GetFont(std::string font_name);
	// Returns the associated TTF_Font*
	FontManager::Encoding GetEncoding(std::string font_name);
	// Returns the line spacing for the font
	int GetLineSpacing (std::string font_id);
	// Sets the linespacing for the font.
	// Initial value is read from the file
	void SetLineSpacing(std::string font_id, int value_);

	// Returns the area the text will occupy
	Point MeasureString(std::string font_id, char* string);

	// Use this only if you need to unload a font during the game
	void Unload(std::string font_name);

	~FontManager();
};
