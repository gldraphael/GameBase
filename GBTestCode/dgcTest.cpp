#include "dgcTest.h"
#include "../Gbase/Game.h"

dgcTest::dgcTest(Game* game) : DrawableGameComponent(game)
{

}


dgcTest::~dgcTest(void)
{

}

void dgcTest::Initialize()
{

}

void dgcTest::LoadContent()
{
	sb = reinterpret_cast<SpriteBatch*> (game->Services["spritebatch"]) ;
	fm = reinterpret_cast<FontManager*> (game->Services["fontmanager"]) ;
}

void dgcTest::Update()
{

}

void dgcTest::Draw()
{
	sb->DrawString(fm->GetFont("font"),
		"The Game", 
		(game->GetScreenBounds() - fm->MeasureString("font","The Game")) / 2 ,
		Color::Black()
		);
}

void dgcTest::UnloadContent()
{

}