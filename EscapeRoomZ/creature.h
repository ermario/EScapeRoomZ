#ifndef _CREATURE_
#define _CREATURE_

#include <string>
#include "entity.h"

class Room;
class Item;

using namespace std;

class Creature : public Entity
{
public:
	Creature(const char* name, const char* description, Room* room);
	~Creature();

	Room* getRoomN() const;


public:

};

#endif 