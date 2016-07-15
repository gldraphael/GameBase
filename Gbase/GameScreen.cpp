//#include "GameScreen.h"
//#include "ScreenManager.h"
//#include "MathHelper.h"
//
//#pragma region cdtor
//
//GameScreen::GameScreen(ScreenManager* sm)
//{
//	//screenManager = sm;
//	//sm->Screens.push_front(this);
//	sm->AddScreen(this);
//	screenState= State::ACTIVE;
//}
//
//GameScreen::GameScreen()
//{
//	screenState= State::ACTIVE;
//}
//
//GameScreen::~GameScreen(void)
//{
//
//}
//
////GameScreen::GameScreen(const GameScreen& cSource)
////{
////    // because m_nLength is not a pointer, we can shallow copy it
////    m_nLength = cSource.m_nLength;
//// 
////    // m_pchString is a pointer, so we need to deep copy it if it is non-null
////    if (cSource.m_pchString)
////    {
////        // allocate memory for our copy
////        m_pchString = new char[m_nLength];
//// 
////        // Copy the string into our newly allocated memory
////        strncpy(m_pchString, cSource.m_pchString, m_nLength);
////    }
////    else
////        m_pchString = 0;
////}
////
////GameScreen& GameScreen::operator=(const GameScreen& cSource)
////{
////    // check for self-assignment
////    if (this == &cSource)
////        return *this;
//// 
////    // first we need to deallocate any value that this string is holding!
////    delete[] m_pchString;
//// 
////    // because m_nLength is not a pointer, we can shallow copy it
////    m_nLength = cSource.m_nLength;
//// 
////    // now we need to deep copy m_pchString
////    if (cSource.m_pchString)
////    {
////        // allocate memory for our copy
////        m_pchString = new char[m_nLength];
//// 
////        // Copy the parameter the newly allocated memory
////        strncpy(m_pchString, cSource.m_pchString, m_nLength);
////    }
////    else
////        m_pchString = 0;
//// 
////    return *this;
////}
//
//#pragma endregion
//
//void GameScreen::Update(bool otherScreenHasFocus, bool coveredByOtherScreen)
//{
//	this->otherScreenHasFocus = otherScreenHasFocus;
//
//	if(isExiting)
//	{
//		screenState = State::TRANSITION_OFF;
//
//		if(!UpdateTransition(transitionOffTime, 1))
//		{
//			screenManager->RemoveScreen(this);
//		}
//	}
//	else if(coveredByOtherScreen)
//	{
//		// If the screen is covered by another, it should transition off.
//		if (UpdateTransition(transitionOffTime, 1))
//		{
//			// Still busy transitioning.
//			screenState = State::TRANSITION_OFF;
//		}
//		else
//		{
//			// Transition finished!
//			screenState = State::HIDDEN;
//		}
//	}
//	else
//	{
//		// Otherwise the screen should transition on and become active.
//		if (UpdateTransition(transitionOnTime, -1))
//		{
//			// Still busy transitioning.
//			screenState = State::TRANSITION_ON;
//		}
//		else
//		{
//			// Transition finished!
//			screenState = State::ACTIVE;
//		}
//	}
//}
//
//void GameScreen::UnloadContent()
//{
//
//}
//
//GameScreen::State GameScreen::ScreenState()
//{
//	return screenState;
//}
//
//bool GameScreen::IsPopup()
//{
//	return ispopup;
//}
//
//bool GameScreen::UpdateTransition(int transitionTime, int direction)
//{
//	// How much should we move by?
//	float transitionDelta;
//
//	if (transitionTime == 0)
//		transitionDelta = 1;
//	else
//		transitionDelta = 0.1f;//(float)(gameTime.ElapsedGameTime.TotalMilliseconds / transitionTime);
//
//	// Update the transition position.
//	transitionPosition += transitionDelta * direction;
//
//	// Did we reach the end of the transition?
//	if (((direction < 0) && (transitionPosition <= 0)) ||
//		((direction > 0) && (transitionPosition >= 1)))
//	{
//		transitionPosition = MathHelper::clamp<float>(transitionPosition, 0, 1);
//		return false;
//	}
//
//	// Otherwise we are still busy transitioning.
//	return true;
//}
//
///// <summary>
///// Tells the screen to go away.
///// Unlike ScreenManager.RemoveScreen, which instantly kills the screen,
///// this method respects the transition timings and will give the screen a chance to gradually transition off.
///// </summary>
//void GameScreen::ExitScreen()
//{
//	if (transitionOffTime == 0)
//	{
//		// If the screen has a zero transition time, remove it immediately.
//		screenManager->RemoveScreen(this);
//	}
//	else
//	{
//		// Otherwise flag that it should transition off and then exit.
//		isExiting = true;
//	}
//}
//
//void GameScreen::SetScreenManager(ScreenManager* screenManager)
//{
//	if (this->screenManager == screenManager)
//		this->screenManager = screenManager;
//}