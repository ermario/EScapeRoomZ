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
}
