/******************************************************
** Program: Bats.h
** Author:
** Date:
** Description:
** Input:
** Output:
******************************************************/
#pragma once
#include <iostream>
#include "Event.h"

class Bats : public Event
{
public:
	using Event::Event; /*Inherited constructors*/
	Bats() {};
	~Bats() {};

public:
	/*********************************************************************
	** Function: Virtual function - Bats Percept
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/
	void Percept() {
		std::cout << "You hear wings flapping.\n";
	};

	/*********************************************************************
	** Function: Virtual function - Bats Logo
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/
	std::string Logo()
	{
		return "Y";
	}
};

