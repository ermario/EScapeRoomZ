#ifndef _WORLD_
#define _WORLD_


#include <string>
#include <list>
#include <time.h>

#define TICK_FREQUENCY 0.5f

using namespace std;

class Entity;
class Player;

class World
{
public:

	World(const char* p_name);
	~World();

	bool Update(vector<string>& args);
	bool ExecuteInteraction(vector<string>& args);
	void UpdateGame();
private:

	clock_t ttimer;
	list<Entity*> entities;
	Player* player;
};

#endif	