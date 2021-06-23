#include <iostream>
#include "room.h"
#include "exit.h"


Exit::Exit(const char* name, const char* next_name, const char* description, Room* origin, Room* destination, ExitDirection ex_dir, bool one_way) :
	Entity(name, description, (Entity*)origin),
	closed(false), locked(false), key(NULL), one_way(one_way), destination(destination), next_name(next_name), ex_dir(ex_dir)
{
	type = EXIT;

	if (one_way == false)
		if (destination == NULL)
		{
			closed = true;
		}
		else
		{
			destination->contains.push_back(this);
		}

}


Exit::~Exit()
{
}


void Exit::Look() const
{
	cout << name << " to " << next_name << "\n";
	cout << description << "\n";
}

const string& Exit::GetDirectionName(const Room* room) const
{
	if (room == prev)
		return name;
	if (room == destination)
		return next_name;

	return name;
}

Room* Exit::GetDestinationName(const Room* room) const
{
	if (room == prev)
		return destination;
	if (room == destination)
		return (Room*)prev;

	return NULL;
}