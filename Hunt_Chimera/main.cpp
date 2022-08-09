/******************************************************
** Program: main.cpp
** Author:
** Date:
** Description:
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


/*Game Functions*/
void IfContinue();

/*Game Terminal Switch*/
bool game_switch = true;

/*********************************************************************
** Function: Main function
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
int main()
{
	Game HTC;
    while (game_switch == 1)
    {
		HTC.Initialize();
		int result = HTC.Play();
		if (result == 1)
		{
			//won
		}
		else if (result == 0)
		{
			//lost

		}
		system("CLS");
    }
    return 0;
}


/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void IfContinue() {
	std::cout << "Press 'L(l)' to replay the last map; Press 'N(n)' to replay the last map; Press any other keys to quit game:\n";
	std::cin >> game_switch;
	std::cout << endl;
	if (game_switch != 'Y' && game_switch != 'y')
	{
		std::cout << "You have quit the game. See you next time >_< ...\n";
	}
}
