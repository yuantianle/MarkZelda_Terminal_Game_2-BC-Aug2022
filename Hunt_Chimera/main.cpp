/******************************************************
** Program: main.cpp
** Author:
** Date:
** Description: player do not need to kill Chimera inorder to win
** Input:
** Output:
******************************************************/

#include "Lib.h"

using namespace std;

template <typename T1>
const T1& minimum(const T1& x, const T1& y) {
	// check to see which value is smaller
	if (x < y)
		return x;
	else
		return y;
}

template <typename TYPEOFVAR1, typename TYPEOFVAR2>
void displayVars(TYPEOFVAR1 x, string myString, const TYPEOFVAR2& y) {
	cout << "Output: " << x << myString << y << endl;
}



/*********************************************************************
** Function: Main function
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
int main(int argc, char** argv)
{
	Game HTC;
	HTC.m_cave_size = atoi(argv[1]);
	std::stringstream ss(argv[2]);
	bool b;
	if (!(ss >> std::boolalpha >> HTC.m_debug_switch)) {
		cout << "Parsing error.\n";
	}

	HTC.Welcome();
	HTC.Initialize();
    while (HTC.m_quit_switch == true)
    {
		int result = HTC.Play();
		while (result != 1 && result != 0)
		{
			result = HTC.Play();
		}
		if (result == 1)
		{
			//WIN
			//new or quit
			std::cout << "Press 'N(n)' to move into the next map; Press any other keys to quit game:\n";
			string k;
			std::cin >> k;
			if (k != "N" && k != "n")
			{				
				HTC.m_quit_switch = false;
				std::cout << "You have quit the game. See you next time >_< ...\n";
			}
			else
			{
				system("CLS");
				HTC.Initialize();
				std::cout << "Welcome to new cave!\n";
			}
		}
		else if (result == 0)
		{
			//LOST
			//new or old or quit
			std::cout << "Press 'R(r)' to replay the last map; Press 'N(n)' to play a new map; Press any other keys to quit game:\n";
			string k;
			std::cin >> k;
			if (k == "N" || k == "n")
			{
				system("CLS");
				HTC.Initialize();
				std::cout << "Time to explore new cave!\n";
				
			}
			else if (k == "R" || k == "r")
			{
				system("CLS");
				HTC.m_player_location = HTC.m_escape_location;
				std::cout << "Try the cave again!\n";
			}
			else
			{
				HTC.m_quit_switch = false;
				std::cout << "You have quit the game. See you next time >_< ...\n";
			}
		}
		
    }
    return 0;
}
