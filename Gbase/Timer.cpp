#include "Timer.h"
#include <SDL.h>

//namespace GameBase
//{
	Timer::Timer()
	{
		startTicks = 0;
		pausedTicks = 0;
		paused = false;
		started = false;    
	}

	void Timer::Start()
	{
		started = true;
		paused = false;
		startTicks = SDL_GetTicks();    
	}

	void Timer::Stop()
	{
		started = false;
		paused = false;    
	}

	void Timer::Pause()
	{
		if( ( started == true ) && ( paused == false ) )
		{
			paused = true;
			pausedTicks = SDL_GetTicks() - startTicks;
		}
	}

	void Timer::Resume()
	{
		if( paused == true )
		{
			paused = false;
			startTicks = SDL_GetTicks() - pausedTicks;
			pausedTicks = 0;
		}
	}

	unsigned int  Timer::GetTicks()
	{
		if( started == true )
		{
			if( paused == true )
				return pausedTicks;
			else
				return SDL_GetTicks() - startTicks;
		}
		return 0;    
	}

	bool Timer::isStarted()
	{
		return started;    
	}

	bool Timer::isPaused()
	{
		return paused;    
	}
//}