#pragma once

//namespace GameBase
//{
	class  Timer
	{
	private:
		unsigned int  startTicks;
		unsigned int  pausedTicks;

		bool paused;
		bool started;

	public:
		Timer();
		bool isStarted();
		bool isPaused();

		//Starts the timer
		void Start();
		//Stops the timer
		void Stop();
		//Pauses the timer
		void Pause();
		//Resumes a paused timer
		void Resume();

		//Gets the timer's time
		unsigned int GetTicks();
	};
//}