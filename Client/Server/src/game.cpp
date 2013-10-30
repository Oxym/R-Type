#include "game.hpp"
#include "monster.hpp"
#include "level.hpp"
#include "spawn.hpp"
#include "monsterType.hpp"
#include "math/time.hpp"
#include "player.hpp"
#include "bullet.hpp"
#include "server.hpp"

Game::Game(Server* server) : server(server)
{
    cout << "New game " << getId() << endl;
    life = 5;
    score = 0;
    referee = NULL;
    begin = -1;
}

Game::~Game()
{
    cout << "Destroying game " << getId() << endl;
 	Player *pl;
	while (players.size() > 0)
	{
		pl = players.front();
		delete (pl);
		server->getPlayers().remove(pl);
		players.pop_front();
	}
    server->getCurrentGame() = NULL;
}

void	Game::start()
{
    if (started())
    	return;
    begin = now();
    cout << "Starting game " << getId() << endl;
    time = 0;
    last = 0;
    pos = 0;
    endTime = -1;
    PlayerList::iterator pl, plEnd = players.end();
	for (pl = players.begin(); pl != plEnd; ++pl)
	{
		(*pl)->init();
	}
}

int    Game::pixPos() const
{
	return (time * BLOCKS_PER_SECOND * blockSize);
}

bool   Game::nextLevel()
{
	return false;
}


bool    Game::started() const
{
    return (begin > 0);
}

void    Game::sendMapInfo() const
{

}

int		Game::addPlayer(Player* p)
{
	if (players.size() < MAX_PLAYERS)
	{
		if (referee == NULL)
			referee = p;
		players.push_back(p);

        // Send map info
		sendMapInfo();
		return (players.size());
	}
	else
		return (-1);
}

void 	Game::removePlayer(Player* p)
{
	players.remove(p);
	if (players.size() == 0)
		delete this;
	if (referee == p)
		referee = players.front();
	// Notify user deco
}

void	Game::sendAll(string& data) const
{
 	PlayerList::const_iterator pl, plEnd = players.end();
	for (pl = players.begin(); pl != plEnd; ++pl)
	{
		(*pl)->send(data);
	}
}


int		Game::loop()
{
	return (players.size());
}

bool    Game::gameOver() const
{
    PlayerList::const_iterator pl, plEnd = players.end();
	for (pl = players.begin(); pl != plEnd; ++pl)
	{
		if ((*pl)->isAlive())
            return (false);
	}
	return (true);
}

int     Game::run()
{
    return (0);
}

void        Game::addPoints(int pts)
{
}

float		Game::loadingBlock() const
{
	return ((float)pos / (float)blockSize + 10); // Anticipative loading
}

Player*    Game::findPlayer(int id)
{
    PlayerList::iterator it, itEnd = players.end();
	for (it = players.begin(); it != itEnd; ++it)
	{
	    if ((*it)->getId() == id)
            return ((*it));
	}
	return (NULL);
}

Game::PlayerList& Game::getPlayers()
{
    return players;
}

Player*     Game::getReferee() const
{
    return referee;
}

int     threadFunc(void *data)
{
    return (0);
}
