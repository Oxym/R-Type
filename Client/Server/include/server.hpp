#ifndef SERVER
# define SERVER

#include <list>
#include <iostream>
#include <stdlib.h>
#include <vector>

#define WELCOME_MSG "salut"

using namespace std;

class Server
{
public:
/*	typedef	list<Player*>	PlayerList; // Creation de la liste des joueurs
	typedef	list<Game*>		GameList;   // Liste des parties.
	*/

	Server(int port = SERVER_PORT);
	~Server();
	void		run();
	void		stop();
	/*Player*     findPlayer(string& ip);
	PlayerList& getPlayers();
	Game*&      getCurrentGame();*/

private:
	/*PlayerList	players;
	GameList	games;
	ISocket		*socket;
	Game*   	game;*/
	bool		running;
};

#endif // SERVER