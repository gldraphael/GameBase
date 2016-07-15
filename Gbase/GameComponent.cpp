#include "GameComponent.h"
#include "Game.h"

//namespace GameBase
//{
GameComponent::GameComponent(Game* game)
{
	this->game = game;
	Enabled = true;
	updateOrder = game->Components.size();
	game->Components.push_front(this);
}

Game* GameComponent::GetGameInstance()
{
	return game;
}

int GameComponent::UpdateOrder()
{
	return updateOrder;
}

void GameComponent::ChangeUpdateOrder(int order)
{
	std::list<GameComponent*>::iterator from;
	for ( auto x : game->Components )
		if ( x->updateOrder == order )
		{
			x->updateOrder = updateOrder;
			from = std::find(x->game->Components.begin(), this->game->Components.end(), x);
			this->updateOrder = order;
			std::list<GameComponent*>::iterator to = std::find(this->game->Components.begin(), this->game->Components.end(), this);
			std::iter_swap(from, to);
			break;
		}
}
//}