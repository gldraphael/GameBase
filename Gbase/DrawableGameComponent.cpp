#include "DrawableGameComponent.h"
#include "SpriteBatch.h"
#include "Game.h"
//namespace GameBase
//{
DrawableGameComponent::DrawableGameComponent(Game* game) : GameComponent(game)
{
	this->drawOrder = 0;
	for ( auto x : game->Components)
		if(dynamic_cast<DrawableGameComponent*>(x))
			drawOrder++;
	Visible = true;
}

int DrawableGameComponent::DrawOrder()
{
	return drawOrder;
}

void DrawableGameComponent::Initialize()
{

}

void DrawableGameComponent::ChangeUpdateOrder(int order)
{
	std::list<GameComponent*>::iterator from;
	DrawableGameComponent* dgc;
	for ( auto x : game->Components )
	{
		dgc = dynamic_cast<DrawableGameComponent*>(x);
		if (dgc)
		{
			if ( dgc->drawOrder == order )
			{
				dgc->drawOrder = drawOrder;
				from = std::find(dgc->game->Components.begin(), dgc->game->Components.end(), dynamic_cast<GameComponent*>(dgc) );
				this->drawOrder = order;
				std::list<GameComponent*>::iterator to = std::find(this->game->Components.begin(), this->game->Components.end(), dynamic_cast<GameComponent*>(this) );
				// Perform the swap
				std::iter_swap(from, to);
				break;
			}
		}
	}
}
