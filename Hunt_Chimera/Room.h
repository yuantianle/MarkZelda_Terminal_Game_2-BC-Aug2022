/******************************************************
** Program: Room.h
** Author:
** Date:
** Description:
** Input:
** Output:
******************************************************/
#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include "Event.h"

class Room {

public:
	Event* m_event = nullptr;

public:
	Room();
	Room(std::string name);
	~Room();
	std::string get_name();

private:
	std::string m_name;
};
#endif
