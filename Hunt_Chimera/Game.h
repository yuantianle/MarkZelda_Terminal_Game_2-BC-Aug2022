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
	int m_cave_size; /*length of one side*/
	std::vector<std::vector<Room>> m_cave;/* create a 2D vector of the requested size*/

	Bats m_bat_event;
	Chimera m_chimera_event;
	Gold m_gold_event;
	Lava m_lava_event;

	bool m_debug_switch = false;
	int m_barrier_row_len = 4; /*Format variable: should be even number*/
	int m_barrier_col_len = 8; /*Format variable: should be even number*/
	std::vector<std::vector<std::string>> m_grid;

	/*Game Terminal Switch*/
	bool m_quit_switch = true;

	std::string m_game_history = "\n";
	bool m_if_find_gold = false;
	bool m_if_chimera_dead = false;

private:
	void DisplayCave(); /*Set as private function because it can only be called by function named Play()*/
	void arrange_grid();
	void draw_grid();

	void DisplayPercepts();	
	int TakeTurn(); 
	void takeUserAction();
	void move();
	bool shootarrow();
	void checkForEvent();

	void detectWinorLoss();

public:	
	int Play();
	void Initialize();
	void Welcome();
};

