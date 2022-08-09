/******************************************************
** Program: Room.cpp
** Author:
** Date:
** Description:
** Input:
** Output:
******************************************************/
#include <iostream>
#include "Room.h"

using namespace std;

Room::Room() {
	m_name = "Empty room";
}

Room::Room(string name) : m_name(m_name) {
}

string Room::get_name() {
	return m_name;
}
