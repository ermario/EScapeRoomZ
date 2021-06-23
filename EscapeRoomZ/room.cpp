#include <iostream>
#include "global_f.h"
#include "exit.h"
#include "item.h"
#include "creature.h"
#include "room.h"


Room::Room(const char* title, const char* description, bool dark, bool death_r) :
	Entity(title, description, NULL),
	is_dark(dark), death_room(death_r)
{
	if (death_r)
		type = DEATHROOM;
	else
		type = ROOM;
}


Room::~Room()
{
}


void Room::Look() const
{
	if (is_dark && flash_on == false)
	{
		cout << "\n Is too dark to see anything\n";
		cout << "You can use the door behind to go back\n";
	}
	else
	{
		cout << "\n" << name << endl;
		cout << description << endl;
		if (type == FINISHROOM)
		{
			gameover = true;
			return;
		}
		
		for (list<Entity*>::const_iterator x = contains.begin(); x != contains.cend(); ++x)
		{
			if ((*x)->type == EXIT)
			{
				Exit* exit = (Exit*)*x;
				cout << "\nYou see a " << exit->description << " in direction (" << exit->GetDirectionName(this) << ")\n";
			}
		}

		
		for (list<Entity*>::const_iterator x = contains.begin(); x != contains.cend(); ++x)
		{
			if ((*x)->type == ITEM)
			{
				Item* item = (Item*)*x;
				cout << "\nThere is an item here: " << item->name;
			}
		}


		cout << "\n";
	}
}


Exit* Room::GetExit(const string& direction) const
{
	for (list<Entity*>::const_iterator x = contains.begin(); x != contains.cend(); ++x)
	{
		if ((*x)->type == EXIT)
		{
			Exit* ex = (Exit*)*x;
			if (Cmp(ex->GetDirectionName(this), direction))
				return ex;
		}
	}

	return NULL;
}


