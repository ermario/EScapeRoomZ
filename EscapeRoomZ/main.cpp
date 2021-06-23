#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "global_f.h"
#include "world.h"
#define esc 27
using namespace std;

// ----------------------------------------------

int main() {

	string input;
	vector<string> player_input;
	string aux_input;
	const char* player_name;
	bool ask_help = false;

	cout << "You feel dizzy.. you are trying to wake up but you have an awful headache...\n";
	cout << "You cant remember anything... you are trying to remember your name...\n";
	cout << "Insert your name >";
	cin >> aux_input;
	player_name = aux_input.c_str();

	cout << "\n Ohh yes... " << aux_input << " ...now you start to remember...\n";

	World new_world(player_name);

	player_input.push_back("look");
	while (!gameover)
	{

		getline(cin, input);
		if (input.length() > 0)
		{
			Tokenize(input, player_input);
			cout << ">";
		}
		else if (input.length() <= 0) {
			cout << ">";
		}
		if (Cmp(input, "help") || Cmp(input, "-h"))
		{
			helpingGuide();
			ask_help = true;
		}
		if (Cmp(input, "quit") || Cmp(input, "exit"))
		{
			gameover = true;
			break;
		}
		if (new_world.Update(player_input) == false && !ask_help)
		{
			cout << "\nSorry, I don't think that is something we can do right now.\n";
		}
		if (player_input.size() > 0)
		{
			player_input.clear();
			input = "";
			ask_help = false;
			cout << "> ";
		}
	}
	cout << "\nThanks for playing, see you next time.\n" << endl;

	return 0;
}