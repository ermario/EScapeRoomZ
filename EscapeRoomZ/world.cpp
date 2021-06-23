#include <iostream>
#include "global_f.h"
#include "entity.h"
#include "creature.h"
#include "item.h"
#include "exit.h"
#include "room.h"
#include "player.h"
#include "world.h"



World::World(const char* p_name)
{
	// ROOMS AND EXITS DECLARATION

	ttimer = clock();
	Room* bedroom = new Room("Bedroom", "You are in your bedroom, but everything feels weird");
	Room* hall = new Room("Hall", "You got into a long creepy hall", true);
	Room* outside = new Room("Outside", "Congratulations! You finished the game, it was all a dream and you woke up fine.");
	outside->type = FINISHROOM;

	Exit* exit_bedroom = new Exit("right", "behind", "Door", bedroom, hall, RIGHT);
	Exit* exit_bedroom2 = new Exit("left", "right", "Window", bedroom, outside, LEFT);
	exit_bedroom2->closed = true; //window is closed and cant be opened

	Room* gameroom1 = new Room("Gameroom", "You are in a bright little room");
	Exit* exit_hall = new Exit("straight", "behind", "Main door", hall, outside, STRAIGHT);
	exit_hall->locked = true; //Main door locked
	Exit* exit_hall2 = new Exit("left", "behind", "Door", hall, gameroom1, LEFT); //oneway true

	Room* gameroom2 = new Room("Gameroom", "You are in a bright little room");
	Room* gameroom8 = new Room("Gameroom", "You are in a dark little room... something starts beeping... ", false, true);
	Exit* exit_gr1 = new Exit("straight", "behind", "Door", gameroom1, gameroom2, STRAIGHT, true);
	Exit* exit_gr1b = new Exit("right", "behind", "Door", gameroom1, gameroom8, RIGHT, true);

	Room* gameroom3 = new Room("Gameroom", "You are in a bright little room");
	Room* gameroom9 = new Room("Gameroom", "You are in a dark little room... something starts beeping...", false, true);
	Exit* exit_gr2 = new Exit("straight", "behind", "Door", gameroom2, gameroom3, STRAIGHT, true);
	Exit* exit_gr2b = new Exit("right", "behind", "Door", gameroom2, gameroom9, RIGHT, true);

	Room* gameroom4 = new Room("Gameroom", "You are in a bright little room");
	Exit* exit_gr3 = new Exit("right", "behind", "Door", gameroom3, gameroom4, RIGHT, true);

	Room* gameroom5 = new Room("Gameroom", "You are in a bright little room");
	Exit* exit_gr4 = new Exit("straight", "behind", "Door", gameroom4, gameroom5, STRAIGHT, true);
	Exit* exit_gr4b = new Exit("right", "behind", "Door", gameroom4, gameroom9, RIGHT, true);

	Room* gameroom6 = new Room("Gameroom", "You are in a bright little room");
	Exit* exit_gr5 = new Exit("right", "behind", "Door", gameroom5, gameroom6, RIGHT, true);

	Room* gameroom7 = new Room("Gameroom", "You are in a bright little room");
	Exit* exit_gr6 = new Exit("straight", "behind", "Door", gameroom6, gameroom7, STRAIGHT, true);
	Exit* exit_gr6b = new Exit("right", "behind", "Door", gameroom6, gameroom8, RIGHT, true);

	Exit* exit_gr7 = new Exit("straight", "behind", "Door", gameroom7, hall, STRAIGHT, true);
	Exit* exit_gr7b = new Exit("right", "behind", "Door", gameroom7, gameroom9, RIGHT, true);


	entities.push_back(bedroom);
	entities.push_back(hall);
	entities.push_back(outside);
	entities.push_back(gameroom1);
	entities.push_back(gameroom2);
	entities.push_back(gameroom3);
	entities.push_back(gameroom4);
	entities.push_back(gameroom5);
	entities.push_back(gameroom6);
	entities.push_back(gameroom7);
	entities.push_back(gameroom8);

	// ITEMS DECLARATION

	Item* flashlight = new Item("Flashlight", "Just a flashlight, equip it to see in dark rooms", bedroom, TOOL);
	Item* note = new Item("Note", "A note, there is something written on it", gameroom1, NOTE);
	Item* key = new Item("key", "Your house key", gameroom7, COMMON);

	exit_hall->key = key;

	entities.push_back(flashlight);
	entities.push_back(note);
	entities.push_back(key);

	// PLAYER DECLARATION
	player = new Player(p_name, "New player", bedroom);


	entities.push_back(player);

}

World::~World()
{

}

bool World::Update(vector<string>& args)
{
	bool ret = true;

	if (args.size() > 0 && args[0].length() > 0)
		ret = ExecuteInteraction(args);

	UpdateGame();

	return ret;
}


void World::UpdateGame()
{
	clock_t now = clock();

	if ((now - ttimer) / CLOCKS_PER_SEC > TICK_FREQUENCY)
	{
		for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
			(*it)->Update();

		ttimer = now;
	}
}


bool World::ExecuteInteraction(vector<string>& args)
{
	bool end = true;

	switch (args.size())
	{
	case 1:
	{
		if (Cmp(args[0], "look") || Cmp(args[0], "l"))
		{
			player->Look(args);
		}
		else if (Cmp(args[0], "straight") || Cmp(args[0], "front"))
		{
			if (args.size() == 1)
			{
				args.push_back("straight");
			}
			else
			{
				args[1] = "straight";
			}
			player->Go(args);
		}

		else if (Cmp(args[0], "behind"))
		{
			if (args.size() == 1)
			{
				args.push_back("behind");
			}
			else
			{
				args[1] = "behind";
			}
			player->Go(args);
		}
		else if (Cmp(args[0], "right"))
		{
			if (args.size() == 1)
			{
				args.push_back("right");
			}
			else
			{
				args[1] = "right";
			}
			player->Go(args);
		}
		else if (Cmp(args[0], "left") || Cmp(args[0], "l"))
		{
			if (args.size() == 1)
			{
				args.push_back("left");
			}
			else
			{
				args[1] = "left";
			}
			player->Go(args);
		}
		else if (Cmp(args[0], "inventory") || Cmp(args[0], "i"))
		{
			player->Inventory();
		}
		else
			end = false;
		break;
	}
	case 2:
	{
		if (Cmp(args[0], "look") || Cmp(args[0], "l"))
		{
			player->Look(args);
		}
		else if (Cmp(args[0], "go") || Cmp(args[0], "move") || Cmp(args[0], "mv"))
		{
			player->Go(args);
		}
		else if (Cmp(args[0], "take") || Cmp(args[0], "pick") || Cmp(args[0], "get"))
		{
			player->Take(args);
		}
		else if (Cmp(args[0], "drop") || Cmp(args[0], "put"))
		{
			player->Drop(args);
		}
		else if (Cmp(args[0], "equip") || Cmp(args[0], "eq") || Cmp(args[0], "use"))
		{
			player->Equip(args);
		}
		else if (Cmp(args[0], "read"))
		{
			player->Equip(args);
		}
		else if (Cmp(args[0], "unequip") || Cmp(args[0], "uneq"))
		{
			player->UnEquip(args);
		}

		else
			end = false;
		break;
	}
	case 3:
	{
		break;
	}
	case 4:
	{
		if (Cmp(args[0], "unlock") || Cmp(args[0], "unlk"))
		{
			player->UnLock(args);
		}
		else
			end = false;
		break;
	}
	default:
		end = false;
	}

	return end;
}