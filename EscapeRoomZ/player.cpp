#include <iostream>
#include "global_f.h"
#include "room.h"
#include "exit.h"
#include "item.h"
#include "player.h"


Player::Player(const char* title, const char* description, Room* room) :
	Creature(title, description, room)
{
	type = PLAYER;
}


Player::~Player()
{
}

void Player::Look(const vector<string>& args) const
{
	if (args.size() > 1)
	{
		for (list<Entity*>::const_iterator it = prev->contains.begin(); it != prev->contains.cend(); ++it)
		{
			if (Cmp((*it)->name, args[1]) || ((*it)->type == EXIT && Cmp(args[1], ((Exit*)(*it))->GetDirectionName((Room*)prev))))
			{
				(*it)->Look();
				return;
			}
		}

		if (Cmp(args[1], "me"))
		{
			cout << "\n" << name << "\n";
			cout << description << "\n";
		}
	}
	else
	{
		prev->Look();
	}
}


bool Player::Go(const vector<string>& args)
{
	Exit* exit = getRoomN()->GetExit(args[1]);

	if (exit == NULL)
	{
		cout << "\nYou can't go '" << args[1] << "'.\n";
		return false;
	}
	if (exit->closed)
	{
		cout << "\nLooks like " << exit->description << " is closed and can't be opened\n";
		cout << exit->destination->name << " is behind that\n";
		return false;
	}

	if (exit->locked)
	{
		cout << "\n" << exit->description << " is locked.\n";
		return false;
	}

	cout << "\nYou take direction " << exit->GetDirectionName((Room*)prev) << "...\n";
	ChangePrevTo(exit->GetDestinationName((Room*)prev));
	prev->Look();
	if (prev->type == DEATHROOM)
	{
		Die();
		gameover = true;
	}
	return true;
}


bool Player::Take(const vector<string>& args)
{
	if (args.size() == 2)
	{
		Item* item = (Item*)prev->Find(args[1], ITEM);

		if (item == NULL)
		{
			cout << "\nThere is no " << args[1] << " here\n";
			return false;
		}

		cout << "\nYou take " << item->name << ".\n";
		item->ChangePrevTo(this);
	}

	return false;
}


void Player::Inventory() const
{
	list<Entity*> items;
	FindAll(ITEM, items);

	if (items.size() == 0)
	{
		cout << "\nYou don't have any item with you.\n";
		return;
	}
	cout << "\nYou have this with you:.\n";
	for (list<Entity*>::const_iterator it = items.begin(); it != items.cend(); ++it)
	{
		cout << "\n" << (*it)->name;
	}

	cout << "\n";
}


bool Player::Drop(const vector<string>& args)
{
	if (args.size() == 2)
	{
		Item* item = (Item*)Find(args[1], ITEM);

		if (item == NULL)
		{
			cout << "\nThere is no item on you with that name.\n";
			return false;
		}

		cout << "\nYou drop " << item->name << "...\n";
		item->ChangePrevTo(prev);

		return true;
	}

	return false;
}


bool Player::Equip(const vector<string>& args)
{
	Item* item = (Item*)Find(args[1], ITEM);

	if (item == NULL)
	{
		cout << "\nCannot find '" << args[1] << "' is not in your inventory.\n";
		return false;
	}

	if (item->item_type == TOOL) {
		cout << "\nYou equip " << item->name << "...\n";
		setLight();
	}
	else if (item->item_type == NOTE) {

		cout << "\n Lets play a game....\n";
		cout << "\n In order to complete the game and survive, you will need to find the exit.\n";
		cout << "There are 9 rooms, some of them may have 2 doors, choose one wisely ... or it will be your end.\n";
		cout << "Only two rooms can kill you.\n";
		cout << "\nHave fun.\n";

		return false;
	}
	else {
		cout << "\n" << item->name << " cannot be equipped.\n";
		return false;
	}

	return true;
}


bool Player::UnEquip(const vector<string>& args)
{

	Item* item = (Item*)Find(args[1], ITEM);

	if (item == NULL)
	{
		cout << "\n'" << args[1] << "' is not in your inventory.\n";
		return false;
	}

	if (item->item_type == TOOL) {
		cout << "\nYou un-equip " << item->name << "...\n";
		setDark();
	}
	else {
		cout << "\n" << item->name << " is not equipped.\n";
		return false;
	}


	return true;
}


bool Player::UnLock(const vector<string>& args)
{

	Exit* exit = getRoomN()->GetExit(args[1]);

	if (exit == NULL)
	{
		cout << "\nThere is nothing to unlock there. (" << args[1] << ")." << endl;
		return false;
	}

	if (exit->locked == false)
	{
		cout << "\nThat exit is not locked." <<endl;
		return false;
	}

	Item* item = (Item*)Find(args[3], ITEM);

	if (item == NULL)
	{
		cout << "\nCan't find Key '" << args[3] << "' in your inventory." << endl;
		return false;
	}

	if (exit->key != item)
	{
		cout << "\nKey '" << item->name << "' is not the key for " << exit->GetDirectionName((Room*)prev) << "." << endl;
		return false;
	}

	cout << "\nYou unlocked " << exit->GetDirectionName((Room*)prev) << "..." << endl;

	exit->locked = false;

	return true;
}
