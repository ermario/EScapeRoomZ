#ifndef _ENTITY_
#define _ENTITY_

#include <string>
#include <list>

using namespace std;

enum EntityType
{
	ENTITY,
	ROOM,
	EXIT,
	ITEM,
	CREATURE,
	PLAYER
};

class Entity
{
public:
	Entity(const char* name, const char* description, Entity* prev);
	virtual ~Entity();

	virtual void Look() const;
	virtual void Update();

	void	ChangePrevTo(Entity* new_prev);
	bool    Find(Entity* entity) const;
	Entity* Find(EntityType type) const;
	Entity* Find(const string& name, EntityType type) const;
	void	FindAll(EntityType type, list<Entity*>& all_list) const;

public:
	EntityType type;
	string name;
	string description;
	Entity* prev;
	list<Entity*> contains;
};

#endif