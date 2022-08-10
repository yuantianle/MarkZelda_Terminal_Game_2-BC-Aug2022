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

/*********************************************************************
** Function: 
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
Room::Room() {
	m_name = "Empty room";
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
Room::Room(string name) : m_name(m_name) {
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
Room::~Room() {

}

string Room::get_name() {
	return m_name;
}
