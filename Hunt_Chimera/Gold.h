/******************************************************
** Program: Gold.h
** Author:
** Date:
** Description:
** Input:
** Output:
******************************************************/
#pragma once
#include <iostream>
#include "Event.h"

class Gold : public Event
{
public:
	using Event::Event; /*Inherited constructors*/
	Gold() {};
	~Gold() {};

public:
	/*********************************************************************
	** Function: Virtual function - Gold Percept
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/
	void Percept() { 
		std::cout << "You notice the shine of bullion in the distance.\n";
	};

	/*********************************************************************
	** Function: Virtual function - Gold Logo
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/
	std::string Logo()
	{
		return "G";
	}
};

