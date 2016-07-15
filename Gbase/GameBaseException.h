//14 September, 2012

#ifndef _GAME_BASE_LIBRARY_GAME_BASE_EXCEPTION_H_
#define	_GAME_BASE_LIBRARY_GAME_BASE_EXCEPTION_H_

#include <exception>
#include <string>
//namespace GameBase
//{
	class GameBaseException :
		public std::exception
	{
	private:
		std::string message;
	public:
		GameBaseException();
		GameBaseException(std::string message);
		const char* what() const;
	};
//}

#endif