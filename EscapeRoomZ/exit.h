#ifndef _EXIT_
#define _EXIT_

#include <string>
#include "entity.h"

class Room;

using namespace std;

enum ExitDirection
{
	STRAIGHT,
	BEHIND,
	LEFT,
	RIGHT
};

class Exit : public Entity
{
public:
	Exit(const char* name, const char* next_name, const char* description, Room* origin, Room* destination, ExitDirection ex_dir, bool one_way = false);
	~Exit();

	void Look() const;

	const string& GetDirectionName(const Room* room) const;
	Room* GetDestinationName(const Room* room) const;

public:
	bool one_way;
	bool closed;
	bool locked;
	string next_name;
	ExitDirection ex_dir;
	Room* destination;
	Entity* key;
};

#endif