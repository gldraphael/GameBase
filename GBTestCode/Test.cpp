#include "Test.h"

Test::Test(void) : test(this)
{
	fontManager = new FontManager;
}

void Test::Initialize()
{
	SetTitle("GB Testing");
	SetPreferredResolution(Point(600,400),32);
	Game::Initialize();
}

void Test::LoadContent()
{
	fontManager->Load("font","lazy.ttf",72);
	Services["spritebatch"] = reinterpret_cast<Component*>(spriteBatch);
	Services["fontmanager"] = reinterpret_cast<Component*> (fontManager);
	Game::LoadContent();
}

void Test::Update()
{
	Game::Update();
}

void Test::Draw()
{
	 graphicsDevice->Clear(Color::CornflowerBlue());
	 
	Game::Draw();
}

void Test::UnloadContent()
{
	Game::UnloadContent();
}

Test::~Test(void)
{
	delete fontManager;
}

// EVENT HANDLERS
void Test::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{
	if (sym == SDLK_ESCAPE)
		quit = true;
	switch (sym)
	{
	case SDLK_F4:
		break;
	default:
		break;
	}
}