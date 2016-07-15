//#pragma once
//
//#include "DrawableGameComponent.h"
//#include "Events.h"
//#include "FontManager.h"
//#include "SpriteBatch.h"
//#include <list>
//#include <vector>
//
//class GameScreen;
//
//// The Screen Manager Class Handles the flow of your game through the different screens
//// An Interface to handle GameScreens only
//
//class ScreenManager :
//	public DrawableGameComponent
//{
//	bool isInitialized;
//	
//	// FontManager fontManager;
//	// SpriteBatch* spriteBatch;
//	// Surface blankSurface;
//
//protected:
//	std::vector<GameScreen*> ScreensToUpdate;
//
//public:
//
//	std::list<GameScreen*> Screens;
//
//	ScreenManager(Game* game);
//	~ScreenManager();
//
//	void Initialize();
//	void LoadContent();
//	void Update();
//	void Draw();
//	void UnloadContent();
//
//	virtual void AddScreen(GameScreen* screen);
//	virtual void RemoveScreen(GameScreen* screen);
//	// Doesn't Function ;)
//	void FadeBackBufferToBlack(float alpha);
//};