#ifndef _ITEM_
#define _ITEM_

#include <string>
#include "entity.h"

class Room;

using namespace std;

enum ItemType
{
	COMMON,
	TOOL
};

class Item : public Entity
{
public:
	Item(const char* name, const char* description, Entity* prev, ItemType item_type = COMMON);
	~Item();

public:
	ItemType item_type;
};

#endif 