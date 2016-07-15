#pragma once
#include "../Gbase/game.h"
#include "../Gbase/FontManager.h"
#include "dgcTest.h"

class Test :
	public Game
{
	FontManager* fontManager;
	dgcTest test;
private:

	void Initialize();
	void LoadContent();
	void Update();
	void Draw();
	void UnloadContent();

	// Event Handlers
	void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) override;

public:
	Test();

	~Test();
};