/******************************************************
** Program: Lava.h
** Author:
** Date:
** Description:
** Input:
** Output:
******************************************************/
#pragma once
#include <iostream>
#include "Event.h"

class Lava : public Event
{
public:
	using Event::Event; /*Inherited constructors*/
	Lava() {};
	~Lava() {};

public:
	/*********************************************************************
	** Function: Virtual function - Lava Percept
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/
	void Percept() {
		std::cout << "You feel an intense blast of heat.\n";
	};

	/*********************************************************************
	** Function: Virtual function - Lava Logo
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/
	std::string Logo()
	{
		return "~";
	}
};

