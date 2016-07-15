#include "../Gbase/GameBaseException.h"
#include "Test.h"
#include <iostream>

int main (int argc, char** argv)
{
	try
	{
		Test test;
		test.Run();
	}
	catch(GameBaseException gbe)
	{
		std::cerr<<std::endl<<gbe.what();
	}
	return 0;
}