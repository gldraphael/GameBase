//#pragma once
//
//
//class GameScreen
//{
//public:
//	enum class State
//	{
//		ACTIVE,
//		HIDDEN,
//		TRANSITION_ON,
//		TRANSITION_OFF
//	};
//private:
//	friend class ScreenManager;
//
//protected:
//	ScreenManager* screenManager;
//	State screenState;
//	bool ispopup;
//	bool isExiting;
//	bool otherScreenHasFocus;
//	int transitionOnTime;
//	int transitionOffTime;
//	float transitionPosition;
//
//public:
//	GameScreen::GameScreen();
//	GameScreen(ScreenManager* screenManager);
//	~GameScreen();
//	// GameScreen::GameScreen(const GameScreen& cSource);
//	// GameScreen& GameScreen::operator=(const GameScreen& cSource);
//
//	virtual void LoadContent() = 0;
//	virtual void UnloadContent();
//
//	virtual void Update(bool otherScreenHasFocus, bool coveredByOtherScreen);
//
//	// virtual void HandleInput(Events* input) = 0;
//	virtual void Draw() = 0;
//
//	State ScreenState();
//	bool IsPopup();
//	void SetScreenManager(ScreenManager* screenManager);
//
//	virtual bool UpdateTransition(int transitionTime, int direction);
//	virtual void ExitScreen();
//private:
//
//	//bool UpdateTransition(GameTime gameTime, TimeSpan time, int direction)
//};