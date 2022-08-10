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
	** Function: Virtual function - Chimera Encounter
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/
	std::string Encounter() {
		return "OMG!! You have seen a Chimera in this room! >_<\n";
	}

	/*********************************************************************
	** Function: Virtual function - Chimera ID
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/
	int ID() {
		return 1;
	}

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

