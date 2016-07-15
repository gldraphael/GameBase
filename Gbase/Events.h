//15 September, 2012

#ifndef _GAME_BASE_LIBRARY_EVENTS_H_
#define _GAME_BASE_LIBRARY_EVENTS_H_

#include <SDL.h>
//namespace GameBase
//{

// Inherit from this class to handle your events 
class Events
{
private:
	SDLKey previousKey , currentKey;
	//bool key_repeated;
public:
	Events();
	~Events();
	Events(const Events &e);
	Events& Events::operator=(const Events& source);

	//bool isKeyRepeated();

	// The Event union
	SDL_Event* Event;

	// Get the type of the current event
	Uint8 GetType();

	// Gets the triggered events and updates the Events object
	int GetEvents();

	// Calls the appropriate function
	bool HandleEvents();


	virtual void OnInputFocus();
	virtual void OnInputBlur();

#pragma region Keyboard Events

	virtual void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
	virtual void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);  

	// Checks if a different key is pressed
	bool KeyPressed(SDLKey sym, SDLMod mod, Uint16 unicode);

	bool IsNewKeyPress(SDLKey sym, SDLMod mod, Uint16 unicode);

	bool IsMenuSelect();

	bool IsCancel();

	bool IsMenuUp();

	bool IsMenuDown();

	bool IsPauseGame();

#pragma endregion

#pragma region Mouse Events

	virtual void OnMouseFocus();
	virtual void OnMouseBlur();
	virtual void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);
	virtual void OnMouseWheel(bool Up, bool Down);    //Not implemented
	virtual void OnLeftMouseButtonDown(int mX, int mY);
	virtual void OnLeftMouseButtonUp(int mX, int mY);
	virtual void OnRightMouseButtonDown(int mX, int mY);
	virtual void OnRightMouseButtonUp(int mX, int mY);
	virtual void OnMiddleMouseButtonDown(int mX, int mY);
	virtual void OnMiddleMouseButtonUp(int mX, int mY);  

#pragma endregion

#pragma region Joystick Events

	virtual void OnJoyAxis(uint8_t which, uint8_t axis, Sint16 value);
	virtual void OnJoyButtonDown(uint8_t which, uint8_t button); 
	virtual void OnJoyButtonUp(uint8_t which, uint8_t button); 
	virtual void OnJoyHat(uint8_t which, uint8_t hat, uint8_t value); 
	virtual void OnJoyBall(uint8_t which, uint8_t ball, Sint16 xrel, Sint16 yrel);

#pragma endregion

#pragma region Window Events

	// Override this for Minimize evnts
	virtual void OnMinimize();

	// Override this for Restore events
	virtual void OnRestore();

	// Override this for Resize events
	virtual void OnResize(int w,int h);

	// Override this for Expose events
	virtual void OnExpose();

	// Override this for Exit events
	virtual void OnExit();

#pragma endregion

	// Override this for Preview events
	virtual void OnUser(Uint8 type, int code, void* data1, void* data2);
};
//}  
#endif // _GAME_BASE_LIBRARY_EVENTS_H_