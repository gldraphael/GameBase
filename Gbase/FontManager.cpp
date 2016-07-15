#include "FontManager.h"

#include "GameBaseException.h"
#include <Extension/SDL_ttf.h>

//FontManager::FontManager(std::multimap<std::string, std::string, unsigned int> font_size)
//{
//	initialized = false;
//	if(TTF_Init() == -1)
//		throw GameBaseException(SDL_GetError());
//	initialized = true;
//}

FontManager::FontManager()
{
	initialized = false;
	if(TTF_Init() == -1)
		throw GameBaseException(SDL_GetError());
	initialized = true;
}

bool FontManager::Load(std::string font_name, char* path, unsigned int size, FontManager::Encoding encoding)
{
	font_list[font_name].font = nullptr;
	font_list[font_name].font = TTF_OpenFont(path,size);
	if (font_list[font_name].font == nullptr)
	{
		font_list.erase(font_name);
		throw  GameBaseException(SDL_GetError());
		return false;
	}

	font_list[font_name].enc = encoding;
	font_list[font_name].line_spacing = TTF_FontLineSkip( (*this)[font_name] );

	return true;
}

void FontManager::Unload(std::string font_id)
{
	TTF_CloseFont(font_list[font_id].font);
	font_list.erase(font_id);
}

TTF_Font* FontManager::GetFont(std::string font_id)
{
	return font_list[font_id].font;
}

int FontManager::GetLineSpacing (std::string font_id)
{
	return TTF_FontLineSkip(font_list[font_id].font);
}

void FontManager::SetLineSpacing (std::string font_id, int value_)
{
	font_list[font_id].line_spacing = value_;
}

Point FontManager::MeasureString (std::string font_id, char* string)
{
	int x , y;

	switch(font_list[font_id].enc)
	{
	case Encoding::ASCII:
		TTF_SizeText( font_list[font_id].font, string, &x, &y );
		break;
	case Encoding::UTF8:
		TTF_SizeUTF8( font_list[font_id].font, string, &x, &y );
		break;
	case Encoding::UNICODE:
		throw GameBaseException("Not Implemented");
		// TTF_SizeUNICODE(font_list[font_id].font,<Uint16*>(string),x,y);
		break;
	}

	return Point(x,y);
}

FontManager::Encoding FontManager::GetEncoding(std::string font_id)
{
	return font_list[font_id].enc;
}

TTF_Font* FontManager::operator[](std::string font_id)
{
	return font_list[font_id].font;
}

FontManager::~FontManager()
{
	if (initialized)
	{		
		for(auto i:font_list)
			TTF_CloseFont(i.second.font);
		TTF_Quit();
	}
}
