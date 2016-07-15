#pragma once
#include "../Gbase/DrawableGameComponent.h"
#include "../Gbase/FontManager.h"
class dgcTest : DrawableGameComponent
{
	SpriteBatch* sb;
	FontManager* fm;
public:
	dgcTest(Game* game);

	void Initialize();
	void LoadContent();
	void Update();
	void Draw();
	void UnloadContent();

	~dgcTest();
};

