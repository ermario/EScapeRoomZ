#include <iostream>
#include "room.h"
#include "creature.h"


Creature::Creature(const char* title, const char* description, Room* room) :
	Entity(title, description, (Entity*)room), alive(true)
{
	type = EntityType::CREATURE;
}

Creature::~Creature()
{}


Room* Creature::getRoomN() const
{
	return (Room*)prev;
}


void Creature::Die()
{
	cout << "You died.\n";
	alive = false;
}