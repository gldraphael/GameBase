//#include "ScreenManager.h"
//#include "GameScreen.h"
//#include "Game.h"
//#include <algorithm>
//
//ScreenManager::ScreenManager(Game* game)
//	:DrawableGameComponent(game)
//{
//	isInitialized = false;
//}
//
//
//ScreenManager::~ScreenManager(void)
//{
//
//}
//
//void ScreenManager::Initialize()
//{
//	isInitialized = true;
//}
//
//void ScreenManager::LoadContent()
//{
//	// spriteBatch = new SpriteBatch (game->GetGraphicsDevice());
//	// fontManager.Load ("lazyfont", "lazy.ttf", 36);
//	// blankSurface = Surface::Load("blank.png",ImageFormat::PNG);
//	for (auto scr : Screens)
//		scr->LoadContent();
//}
//
//void ScreenManager::Update()
//{
//	//while (InputHandler.GetEvents() )
//	//{
//	//	InputHandler.HandleEvents();
//	//}
//
//	ScreensToUpdate.clear();
//
//	std::copy (Screens.begin (), Screens.end (), std::back_inserter (ScreensToUpdate));
//
//	bool otherScreenHasFocus = false;//!Game.IsActive;
//	bool coveredByOtherScreen = false;
//
//	//for ( auto i: ScreensToUpdate)
//	//	i->Update(false,false);
//
//	// Loop as long as there are screens waiting to be updated.
//	while (ScreensToUpdate.size() > 0)
//	{
//		// Pop the topmost screen off the waiting list.
//		GameScreen* screen = ScreensToUpdate[ScreensToUpdate.size() - 1];
//		ScreensToUpdate.pop_back();
//
//		// Update the screen.
//		screen->Update( otherScreenHasFocus, coveredByOtherScreen);
//
//		if (screen->ScreenState() == GameScreen::State::TRANSITION_ON ||
//			screen->ScreenState() == GameScreen::State::ACTIVE)
//		{
//			// If this is the first active screen we came across,
//			// give it a chance to handle input.
//			if (!otherScreenHasFocus)
//			{
//				// screen.HandleInput(input);
//				otherScreenHasFocus = true;
//			}
//
//			// If this is an active non-popup, inform any subsequent
//			// screens that they are covered by it.
//			if (!screen->IsPopup())
//				coveredByOtherScreen = true;
//		}
//	}
//
//}
//
//void ScreenManager::Draw()
//{
//	for (auto i : Screens)
//	{
//		if (i->ScreenState() == GameScreen::State::HIDDEN)
//			continue;
//		i->Draw();
//	}
//}
//
//void ScreenManager::UnloadContent()
//{
//	for (auto scr : Screens)
//		scr->UnloadContent();
//}
//
//void ScreenManager::AddScreen(GameScreen* screen)//, PlayerIndex? controllingPlayer)
//{
//	//screen.ControllingPlayer = controllingPlayer;
//	// if (screen->screenManager != this)
//		// screen->screenManager = this;
//	//screen->SetScreenManager(this);
//	screen->isExiting = false;
//
//	// If we have a graphics device, tell the screen to load content.
//	if (isInitialized)
//	{
//		screen->LoadContent();
//	}
//
//	Screens.push_back(screen);
//
//}
//
///// <summary>
///// Removes a screen from the screen manager.
///// You should normally use GameScreen.ExitScreen instead of calling this directly,
///// so that the screen can gradually transit off rather than just being instantly removed.
///// </summary>
//void ScreenManager::RemoveScreen(GameScreen* screen)
//{
//	// If we have a graphics device, tell the screen to unload content.
//	if (isInitialized)
//	{
//		screen->UnloadContent();
//	}
//
//	
//	Screens.remove(screen);
//	ScreensToUpdate.erase(std::remove(ScreensToUpdate.begin(), ScreensToUpdate.end(), screen), ScreensToUpdate.end());
//
//	if (screen != nullptr || screen != NULL)
//		delete screen;
//}
//
///// <summary>
///// Expose an array holding all the screens.
///// We return a copy rather than the real master list,
///// because screens should only ever be added or removed using the AddScreen and RemoveScreen methods.
///// </summary>
////GameScreen[] GetScreens()
////{
////	return screens.ToArray();
////}
//
//
///// <summary>
///// Helper method that draws a translucent black fullscreen sprite,
///// used for fading screens in and out, and for darkening the background behind popups.
///// </summary>
//void ScreenManager::FadeBackBufferToBlack(float alpha)
//{
//	/*Viewport viewport = GraphicsDevice.Viewport;
//
//	spriteBatch.Begin();
//
//	spriteBatch.Draw(blankTexture, new Rectangle(0, 0, viewport.Width, viewport.Height), Color.Black * alpha);
//
//	spriteBatch.End();*/
//}