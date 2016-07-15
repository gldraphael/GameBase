#include "Events.h"
#include <SDL.h>
#include "Game.h"

//namespace GameBase
//{

#pragma region cdtor

Events::Events() 
{
	previousKey = SDLKey::SDLK_UNKNOWN;
	Event = new SDL_Event;
	//key_repeated = false;
}

Events::~Events() 
{
	delete Event;
}

//Copy Constructor
Events::Events(const Events &source)
{
	if(source.Event)
	{
		*Event = *source.Event;
		previousKey = source.previousKey;
		currentKey = source.currentKey;
		//key_repeated = source.key_repeated;
	}
	else
	{
		Event = NULL;
	}
}

Events& Events::operator=(const Events& source)
{
	if(this == &source)
		return *this;
	if(Event)
		delete Event;
	if(source.Event)
	{
		*Event = *source.Event;
		previousKey = source.previousKey;
		currentKey = source.currentKey;
		//key_repeated = source.key_repeated;
	}
	else Event = 0;
	return *this;
}

#pragma endregion

Uint8 Events::GetType()
{
	return Event->type;
}

bool Events::HandleEvents()
{
	switch(Event->type) 
	{
	case SDL_ACTIVEEVENT: 
		{
			switch(Event->active.state) 
			{
			case SDL_APPMOUSEFOCUS: 
				{
					if ( Event->active.gain )
						OnMouseFocus();
					else
						OnMouseBlur();

					break;
				}
			case SDL_APPINPUTFOCUS: 
				{
					if ( Event->active.gain )   
						OnInputFocus();
					else
						OnInputBlur();

					break;
				}
			case SDL_APPACTIVE:    
				{
					if ( Event->active.gain )    
						OnRestore();
					else
						OnMinimize();

					break;
				}
			}
			break;
		}

	case SDL_KEYDOWN:
		{
			previousKey = currentKey;
			currentKey = Event->key.keysym.sym;

			//if (previousKey == currentKey)
			//	key_repeated = true;
			//else 
			//	key_repeated = false;

			OnKeyDown(currentKey,Event->key.keysym.mod,Event->key.keysym.unicode);
			break;
		}

	case SDL_KEYUP: 
		{
			//key_repeated = false;

			previousKey = currentKey;
			OnKeyUp(currentKey,Event->key.keysym.mod,Event->key.keysym.unicode);
			break;
		}

	case SDL_MOUSEMOTION: 
		{
			OnMouseMove(Event->motion.x,Event->motion.y,Event->motion.xrel,Event->motion.yrel,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0);
			break;
		}

	case SDL_MOUSEBUTTONDOWN: 
		{
			switch(Event->button.button) 
			{
			case SDL_BUTTON_LEFT: 
				{
					OnLeftMouseButtonDown(Event->button.x,Event->button.y);
					break;
				}
			case SDL_BUTTON_RIGHT: 
				{
					OnRightMouseButtonDown(Event->button.x,Event->button.y);
					break;
				}
			case SDL_BUTTON_MIDDLE: 
				{
					OnMiddleMouseButtonDown(Event->button.x,Event->button.y);
					break;
				}
			}
			break;
		}

	case SDL_MOUSEBUTTONUP:    
		{
			switch(Event->button.button) 
			{
			case SDL_BUTTON_LEFT: 
				{
					OnLeftMouseButtonUp(Event->button.x,Event->button.y);
					break;
				}
			case SDL_BUTTON_RIGHT: 
				{
					OnRightMouseButtonUp(Event->button.x,Event->button.y);
					break;
				}
			case SDL_BUTTON_MIDDLE: 
				{
					OnMiddleMouseButtonUp(Event->button.x,Event->button.y);
					break;
				}
			}
			break;
		}

	case SDL_JOYAXISMOTION: 
		{
			OnJoyAxis(Event->jaxis.which,Event->jaxis.axis,Event->jaxis.value);
			break;
		}

	case SDL_JOYBALLMOTION: 
		{
			OnJoyBall(Event->jball.which,Event->jball.ball,Event->jball.xrel,Event->jball.yrel);
			break;
		}

	case SDL_JOYHATMOTION: 
		{
			OnJoyHat(Event->jhat.which,Event->jhat.hat,Event->jhat.value);
			break;
		}
	case SDL_JOYBUTTONDOWN: 
		{
			OnJoyButtonDown(Event->jbutton.which,Event->jbutton.button);
			break;
		}

	case SDL_JOYBUTTONUP: 
		{
			OnJoyButtonUp(Event->jbutton.which,Event->jbutton.button);
			break;
		}

	case SDL_QUIT: 
		{
			OnExit();
			return true;
		}

	case SDL_SYSWMEVENT: 
		{
			//Ignore
			break;
		}

	case SDL_VIDEORESIZE: 
		{
			OnResize(Event->resize.w,Event->resize.h);
			break;
		}

	case SDL_VIDEOEXPOSE: 
		{
			OnExpose();
			break;
		}

	default: 
		{
			OnUser(Event->user.type,Event->user.code,Event->user.data1,Event->user.data2);
			break;
		}
	}
	return false;
}

int Events::GetEvents()
{
	return SDL_PollEvent(this->Event);
}

//bool Events::isKeyRepeated()
//{
//	return key_repeated;
//}

void Events::OnInputFocus()
{
	Game::SetIsActive(this,true);
}

void Events::OnInputBlur() 
{
	Game::SetIsActive(this,false);
}

void Events::OnKeyDown(SDLKey sym, SDLMod mod, uint16_t unicode) 
{

}

bool Events::KeyPressed(SDLKey sym, SDLMod mod, Uint16 unicode)
{
	return sym == currentKey && currentKey != previousKey;
}

bool Events::IsNewKeyPress(SDLKey sym, SDLMod mod, Uint16 unicode)
{
	return KeyPressed(sym, mod, unicode);
}

bool Events::IsMenuSelect()
{
	return KeyPressed(SDLKey::SDLK_RETURN, KMOD_NONE, SDLK_RETURN);
}

bool Events::IsCancel()
{
	return KeyPressed(SDLKey::SDLK_ESCAPE, KMOD_NONE, SDLK_ESCAPE);
}

bool Events::IsMenuUp()
{
	return KeyPressed(SDLKey::SDLK_UP, KMOD_NONE, SDLK_UP);
}

bool Events::IsMenuDown()
{
	return KeyPressed(SDLKey::SDLK_DOWN, KMOD_NONE, SDLK_DOWN);
}

bool Events::IsPauseGame()
{
	return KeyPressed(SDLKey::SDLK_ESCAPE, KMOD_NONE, SDLK_ESCAPE) ||
		KeyPressed(SDLKey::SDLK_p, KMOD_NONE, SDLK_p);
}

void Events::OnKeyUp(SDLKey sym, SDLMod mod, uint16_t unicode) 
{

}

void Events::OnMouseFocus() 
{

}

void Events::OnMouseBlur() 
{

}

void Events::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) 
{

}

void Events::OnMouseWheel(bool Up, bool Down) 
{

}

void Events::OnLeftMouseButtonDown(int mX, int mY) 
{

}

void Events::OnLeftMouseButtonUp(int mX, int mY) 
{

}

void Events::OnRightMouseButtonDown(int mX, int mY) 
{

}

void Events::OnRightMouseButtonUp(int mX, int mY) 
{

}

void Events::OnMiddleMouseButtonDown(int mX, int mY) 
{

}

void Events::OnMiddleMouseButtonUp(int mX, int mY) 
{

}

void Events::OnJoyAxis(uint8_t which,uint8_t axis,Sint16 value) 
{

}

void Events::OnJoyButtonDown(uint8_t which,uint8_t button) 
{

}

void Events::OnJoyButtonUp(uint8_t which,uint8_t button) 
{

}

void Events::OnJoyHat(uint8_t which,uint8_t hat,uint8_t value) 
{

}

void Events::OnJoyBall(uint8_t which,uint8_t ball,Sint16 xrel,Sint16 yrel) 
{

}

void Events::OnMinimize() 
{
	Game::SetIsActive(this,false);
}

void Events::OnRestore() 
{
	Game::SetIsActive(this,true);
}

void Events::OnResize(int w,int h) 
{

}

void Events::OnExpose() 
{

}

void Events::OnExit() 
{

}

void Events::OnUser(uint8_t type, int code, void* data1, void* data2) 
{

}
//}