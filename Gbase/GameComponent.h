//14 September, 2012

#pragma once

class /*GCALL*/ Game;
//namespace GameBase
//{
	class GameComponent
	{
	protected:
		Game* game;
		int updateOrder;
	public:
		GameComponent(Game* game);
		//GameComponent(const GameComponent& cSource);
		//GameComponent& GameComponent::operator=(const GameComponent& source);
		int UpdateOrder();
		bool Enabled;
		void ChangeUpdateOrder(int order);
		Game* GetGameInstance();
		virtual void Initialize() = 0;
		virtual void Update() = 0;
	};
//}