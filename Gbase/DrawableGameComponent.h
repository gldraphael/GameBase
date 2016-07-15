//14 September, 2012

#ifndef _GAME_BASE_LIBRARY_DRAWABLE_GAME_COMPONENT_H_
#define	_GAME_BASE_LIBRARY_DRAWABLE_GAME_COMPONENT_H_

#include "gamecomponent.h"

class GraphicsDevice;

//namespace GameBase
//{
class DrawableGameComponent :
	public GameComponent
{
protected:
	int drawOrder;
public:
	
	void DrawableGameComponent::ChangeUpdateOrder(int order);
	GraphicsDevice* GraphicsDevice;
	DrawableGameComponent(Game* game);
	int DrawOrder();
	bool Visible;
	virtual void Initialize();
	virtual void LoadContent() = 0;
	virtual void UnloadContent() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};
//}  

#endif // !_GAME_BASE_LIBRARY_DRAWABLE_GAME_COMPONENT_H_