#ifndef GLOBAL_F
#define GLOBAL_F

#include <string>
#include <sstream>
#include <vector>

using namespace std;

bool Cmp(const string& a, const string& b);
bool Cmp(const char* a, const string& b);
bool Cmp(const string& a, const char* b);
void Tokenize(const string& line, vector<string>& arguments);
void setDark();
void setLight();
extern bool flash_on;
#endif