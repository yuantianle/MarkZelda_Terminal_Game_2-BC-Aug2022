/******************************************************
** Program: Event.h
** Author:
** Date:
** Description:
** Input:
** Output:
******************************************************/
#pragma once
#include <String>

class Event
{

public:
	virtual void Percept() = 0;
	virtual std::string Logo() = 0;
	virtual std::string Encounter() = 0;
	virtual int ID() = 0;
};

