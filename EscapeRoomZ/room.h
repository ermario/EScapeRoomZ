#ifndef _ROOM_
#define _ROOM_

#include <string>
#include <list>
#include "entity.h"

class Exit;
class Item;

using namespace std;

class Room : public Entity
{
public:
	Room(const char* name, const char* description, bool isDark = false);
	~Room();

	void Look() const;

	Exit* GetExit(const string& direction) const;
public:
	bool isDark;

};

#endif 