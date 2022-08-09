/******************************************************
** Program: Game.h
** Author:
** Date:
** Description:
** Input:
** Output:
******************************************************/
#pragma once
#include <vector>
#include "Lib.h"

class Game
{
public:
	Game() {};
	~Game() {};

public:
	int m_num_arrows = 3;
	/*location(Row, Col)*/
	std::vector <int> m_player_location = std::vector <int>(2, -1); /*"*"*/ 
	std::vector <int> m_escape_location = std::vector <int>(2, -1); /*ER*/
	int m_cave_size = 4; /*length of one side*/
	std::vector<std::vector<Room>> m_cave = std::vector<std::vector<Room>>(m_cave_size, std::vector<Room>(m_cave_size));/* create a 2D vector of the requested size*/
	bool m_is_chimera_dead = false;
	
	Bats m_bat_event;
	Chimera m_chimera_event;
	Gold m_gold_event;
	Lava m_lava_event;

private:
	void DisplayCave(); /*Set as private function because it can only be called by function named Play()*/
	int TakeTurn(); 
	void displayPercepts();
	void takeUserAction();
	void checkForEvent();
	void move();
	bool shootarrow();
	void detectWinorLoss();

public:	
	int Play();
	void Initialize();
	
};

