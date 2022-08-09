/******************************************************
** Program: Chimera.h
** Author:
** Date:
** Description:
** Input:
** Output:
******************************************************/
#pragma once
#include <iostream>
#include "Event.h"

class Chimera : public Event
{
public:
	using Event::Event; /*Inherited constructors*/
	Chimera() {};
	~Chimera() {};

public:
	/*********************************************************************
	** Function: Virtual function - Chimera Percept
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/
	void Percept() {
		std::cout << "You smell a terrible stench.\n";
	};

	/*********************************************************************
	** Function: Virtual function - Chimera Logo
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/
	std::string Logo()
	{
		return "M";
	}
};

