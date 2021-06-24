#include <iostream>
#include "global_f.h"
#include "Entity.h"


Entity::Entity(const char* name, const char* description, Entity* prev = NULL) :
	name(name), description(description), prev(prev)
{
	if (prev != NULL)
		prev->contains.push_back(this);

	type = EntityType::ENTITY;
}

Entity::~Entity()
{}


void Entity::Look() const
{
	cout << name << "\n";
	cout << description << "\n";
}

void Entity::Update()
{}

void Entity::ChangePrevTo(Entity* new_prev)
{
	if (prev != NULL)
		prev->contains.remove(this);

	prev = new_prev;

	if (prev != NULL)
		prev->contains.push_back(this);
}

bool Entity::Find(Entity* entity) const
{
	for (list<Entity*>::const_iterator x = contains.begin(); x != contains.cend(); ++x)
	{
		if ((*x) == entity)
			return true;
	}

	return false;
}

Entity* Entity::Find(EntityType type) const
{
	for (list<Entity*>::const_iterator x = contains.begin(); x != contains.cend(); ++x)
	{
		if ((*x)->type == type)
			return *x;
	}

	return NULL;
}

Entity* Entity::Find(const string& name, EntityType type) const
{
	for (list<Entity*>::const_iterator x = contains.begin(); x != contains.cend(); ++x)
	{
		if ((*x)->type == type)
		{
			if (Cmp((*x)->name, name))
				return *x;
		}
	}

	return NULL;
}

void Entity::FindAll(EntityType type, list<Entity*>& all_list) const
{
	for (list<Entity*>::const_iterator it = contains.begin(); it != contains.cend(); ++it)
	{
		if ((*it)->type == type)
			all_list.push_back(*it);
	}
}
