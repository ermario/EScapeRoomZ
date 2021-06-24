#include <iostream>
#include "item.h"

Item::Item(const char* title, const char* description, Entity* prev, ItemType item_type) :
	Entity(title, description, prev), item_type(item_type)
{
	type = EntityType::ITEM;
}

Item::~Item()
{}
