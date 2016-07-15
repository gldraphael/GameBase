//14 September, 2012


#ifndef _GAME_BASE_LIBRARY_GAME_H_
#define	_GAME_BASE_LIBRARY_GAME_H_


#include <SDL.h>

#include "GameComponent.h"
//#include "ScreenManager.h"			// Includes Events
#include "Events.h"
#include "Timer.h"
#include "SpriteBatch.h"			// Includes Graphicsdevice, Structs, ...

// STL headers
#include <list>
#include <map>

//namespace GameBase
//{
// An empty class that does nothing
class Component
{

};

// This is the main Game class
// Inherit from this class to make your own game
// This class should NOT be instantiated more than once
// This is the most important class of this library from it's user's point of view 
class Game
{

private:
	Timer timer;
	bool _initialized;
	static bool isActive;
protected:

	// Changing the value of this variable to true will quit the game
	bool quit;

	// The GraphicsDevice handles all the window related stuff
	GraphicsDevice * graphicsDevice;

	// Use this to draw images or text on the screen
	SpriteBatch* spriteBatch;


public:
	// Make this point to your event class of the current game state
	Events* gameEvent;

public:

	// A list of Game Components
	std::list<GameComponent*> Components;

	// A map of Services
	// Load Stuff and register them as a service by reinterpret_cast<Component*>
	// You'll need to cast it back while getting it back
	std::map<char*,Component*> Services;

	// Must be called before Game::Initialize to take effect
	// Sets the preferred screen resolution for the game
	void SetPreferredResolution(Point Width_height, unsigned int bits_per_pixel, bool fullscreen = false);

	// Set the Window's Title
	void SetTitle(char* title);

	// Returns the bottom right Point of the window from which the Width and Height can be obtained
	Point GetScreenBounds();
	// Returns a pointer to the GraphicsDevice
	GraphicsDevice* GetGraphicsDevice();
	Game();
	~Game();

	// Time Elapsed since last update
	unsigned int ElapsedTime();

	// Returns the State of the game window
	static bool IsActive();

	// To be used only by Event's child class
	static void SetIsActive(Events* events, bool _value);

	static void HideCursor();
	static void ShowCursor();

	void SetEventHandler(Events* e);

protected:

	//Initializes the game
	virtual void Initialize();

	//Loads the game contents
	virtual void LoadContent();

	//Unloads the game contents
	virtual void UnloadContent();

	//Updates the GameScreen
	virtual void Update();

	//Draws the GameScreen
	virtual void Draw();

public:

	//Runs the game
	virtual void Run();

	// Runs the game at the given frames per second
	virtual void Run(unsigned int frames_per_second);

	void Close();
};

//}

#endif // !_GAME_BASE_LIBRARY_GAME_H_