#include "Game.h"
#include "DrawableGameComponent.h"
//namespace GameBase
//{

#pragma region cdtor

bool Game::isActive = true;

Game::Game()
{
	_initialized = false;
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
		throw GameBaseException(SDL_GetError());
	graphicsDevice = nullptr;
	gameEvent = nullptr;
	quit = false;
	_initialized = true;
}

Game::~Game()
{
	if (_initialized)
	{
		SDL_Quit();
	}
}

#pragma endregion

#pragma region Run

void Game::Run()
{
	Run(24);
}

void Game::Run(unsigned int frames_per_second)
{
	if (gameEvent == nullptr)
		throw GameBaseException("No Event Handler Set!\nUse Game::SetEventHandler(new Events) in your Application's Constructor()");

	const unsigned int secs = 1000/frames_per_second;
	this->Initialize();
	this->LoadContent();
	while(!quit)
	{
		//Start the timer
		timer.Start();

		this->Update();
		this->Draw();

		// Capping the frame rate
		if(timer.GetTicks()<secs)
		{
			//Utility::Wait(secs - timer.GetTicks());
			SDL_Delay(secs - timer.GetTicks());
		}
	}
}

#pragma endregion


#pragma region VirtualFns

void Game::Initialize()
{
	SetPreferredResolution (Point(800,600),32);
	for ( auto c: Components)
	{
		c->Initialize();
	}
	spriteBatch = new SpriteBatch(graphicsDevice);
}

void Game::LoadContent()
{
	// Load the Content of the Drawable Components
	DrawableGameComponent* tdgc;
	for ( auto dgc : Components)
	{
		tdgc = dynamic_cast<DrawableGameComponent*>(dgc);
		if(tdgc)
			tdgc->LoadContent();
	}
}

void Game::Update()
{
	//Handle Events
	while (gameEvent->GetEvents())
		// while (GetEvents())
	{
		if(gameEvent->HandleEvents())
			// if(HandleEvents())
		{
			quit = true;
			break;
		}
	}

	//if(!isActive)
	//	timer.Pause();

	//else if(isActive && timer.isStarted())
	{
		//Upate
		for (auto i: Components)
			if ( i->Enabled )
			{
				i->Update();
			}
	}
}

void Game::Draw()
{
	// Draw the Visible Drawable Components
	DrawableGameComponent* tdgc;
	//if(!Components.empty())
	//{
	for ( auto dgc : Components)
	{
		if (tdgc = dynamic_cast<DrawableGameComponent*>(dgc))
			if (tdgc->Visible)
				tdgc->Draw();
	}
	//}
	graphicsDevice->Draw();
}

void Game::UnloadContent()
{
	DrawableGameComponent* tdgc;
	for ( auto dgc : Components)
	{
		tdgc = dynamic_cast<DrawableGameComponent*>(dgc);
		if(tdgc)
			tdgc->UnloadContent();
	}

	delete spriteBatch;
	delete graphicsDevice;
}

#pragma endregion

void Game::SetTitle(char* title)
{
	SDL_WM_SetCaption(title,"GB");
}

Point Game::GetScreenBounds()
{
	if (graphicsDevice == nullptr)
		throw GameBaseException("The Graphics Device is not initialized yet");
	return Point(static_cast<float>(graphicsDevice->Viewport().Width),
		static_cast<float>(graphicsDevice->Viewport().Height));
}

void Game::SetPreferredResolution(Point Width_height, unsigned int bits_per_pixel,bool fullscreen)
{
	if (graphicsDevice)
		return;
	// If the graphics device hasn't been instantiated
	graphicsDevice = new GraphicsDevice (static_cast<int>(Width_height.X), static_cast<int>(Width_height.Y), bits_per_pixel, fullscreen);
	spriteBatch = new SpriteBatch(graphicsDevice);
}

GraphicsDevice* Game::GetGraphicsDevice()
{
	return graphicsDevice;
}

unsigned int Game::ElapsedTime()
{
	return timer.GetTicks();
}

bool Game::IsActive()
{
	return isActive;
}

void Game::SetIsActive(Events* events, bool _value)
{
	isActive = _value;
}

void Game::SetEventHandler(Events* e)
{
	delete gameEvent;
	gameEvent = e;
}

void Game::Close()
{
	quit = true;
}

void Game::HideCursor()
{
	SDL_ShowCursor(SDL_DISABLE);
}

void Game::ShowCursor()
{
	SDL_ShowCursor(SDL_ENABLE);
}
//}