#include <iostream>
#include "server.hpp"
#include <stdlib.h>
#include <vector>
#include "log.hpp"

using namespace std;

int	main()
{
	Logger::Instance()->open("Server.txt");
	Logger::Instance()->log(0, "----------------Server Initialized-------------\n");
	srand(43);
	try 
	{
		Server	serv;
		serv.run();
    } 
	catch (std::exception* e)
	{
        std::cerr << e->what() << std::endl;
		Logger::Instance()->log(3, e->what());
        delete e;
    }
	Logger::Instance()->log(0, "Exit with code 0");
    return 0;
}
