#ifndef _ITEM_
#define _ITEM_

#include <string>
#include "entity.h"

class Room;

using namespace std;

enum class ItemType
{
	COMMON,
	TOOL,
	NOTE, 
	FORNITURE
};

class Item : public Entity
{
public:
	Item(const char* name, const char* description, Entity* prev, ItemType item_type = ItemType::COMMON);
	~Item();

public:
	ItemType item_type;
};

#endif 