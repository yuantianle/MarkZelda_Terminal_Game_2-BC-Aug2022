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
	** Function: Virtual function - Bats Encounter
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/
	std::string Encounter() {
		return "Time to be teleported! A group of Super bats in this room are grabing u to another empty room! o_o\n";
		
	}

	/*********************************************************************
	** Function: Virtual function - Bats ID
	** Description:
	** Parameters:
	** Pre-Conditions:
	** Post-Conditions:
	*********************************************************************/
	int ID()
	{
		return 2;
	}

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

