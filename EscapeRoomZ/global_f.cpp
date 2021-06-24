#include "global_f.h"

bool flash_on = false;
bool gameover = false;

bool Cmp(const string& a, const string& b) // Compare string to string
{
	return _stricmp(a.c_str(), b.c_str()) == 0;
}

bool Cmp(const char* a, const string& b) // Compare char_p to string
{
	return _stricmp(a, b.c_str()) == 0;
}

bool Cmp(const string& a, const char* b)
{
	return _stricmp(a.c_str(), b) == 0; // Compare string to char_p
}

void Tokenize(const string& line, vector<string>& arguments)
{
	{
		// construct a stream from the string 
		istringstream iss(line);

		string s;
		while (getline(iss, s, ' ')) {
			if (s.find_first_not_of(' ') != s.npos) // exclude spaces
			{
				arguments.push_back(s.c_str());
			}
		}
	}
}

void setDark()
{
	flash_on = false;
}
void setLight()
{
	flash_on = true;
}

void helpingGuide()
{
	cout << "\n------------- HELPING GUIDE -------------\n";
	cout << "The objective of the game is to find out what is going on in your house\n";
	cout << "Explore, take items, survive and exit your house. \n";
	cout << "\nHELPFUL COMMANDS: \n";
	cout << "- Look | l\n";
	cout << "- Look (entity)| l (entity)\n";
	cout << "- Inventory | i\n";
	cout << "- Go (direction) | Move (direction) | mv (direction)\n";
	cout << "directions: (straight/right/left/behind)\n";
	cout << "- Take (item) | Pick (item)\n";
	cout << "- Take (item) from (entity)| Pick (item) from (entity)\n";
	cout << "- Drop (item) | Put (item)\n";
	cout << "- Equip (item) | eq (item) | Use (item)\n";
	cout << "- Unequip (item) | uneq (item)\n";
	cout << "- Read (note)\n";
	cout << "- Unlock (direction) with (key)\n";
	cout << "\nTIPS:\n";
	cout << " - Use the flashlight to see in the dark\n";
	cout << " - Use a key to unlock a door\n";
	cout << " - Read a note to get more information or hints\n";
	cout << "----------------------------------------\n\n";
}
