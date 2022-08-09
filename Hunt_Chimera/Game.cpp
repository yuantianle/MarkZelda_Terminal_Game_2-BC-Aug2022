/******************************************************
** Program: Game.cpp
** Author:
** Date:
** Description:
** Input:
** Output:
******************************************************/
#include "Game.h"

/*********************************************************************
** Function: 
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void Game::DisplayCave() {
	
	srand((unsigned)time(NULL));
	int Max_event_num = m_cave_size;
	int number_r = rand() % Max_event_num;
	int number_c = rand() % Max_event_num;
	while (m_cave[number_r][number_c].m_event != nullptr)
	{
		number_r = rand() % Max_event_num;
		number_c = rand() % Max_event_num;
	}
	m_player_location[0] = number_r;
	m_player_location[1] = number_c;

	int row_len = 4; /*should be even number*/
	int col_len = 8; /*should be even number*/
	for (int i = 0; i < m_cave_size * row_len + 1; i++)
	{
		for (int j = 0; j < m_cave_size * col_len + 1; j++)
		{
			if (i % row_len == 0)
			{
				if (j % col_len == 0)
					std::cout << "+";
				else
					std::cout << "-";
			}
			else if (i % row_len == 1 || i % row_len == 3)
			{
				if (j % col_len == 0)
					std::cout << "|";
				else
					std::cout << " ";
			}
			else
			{
				if (j % col_len == 0)
					std::cout << "|";
				else if (j % col_len != col_len/2)
					std::cout << " ";
				else
				{
					if (m_cave[i/ row_len][j/ col_len].m_event != nullptr)
						std::cout << m_cave[i/ row_len][j/ col_len].m_event->Logo();
					else if (i/ row_len == m_player_location[0] && j/ col_len == m_player_location[1])
						std::cout << "*";
					else
						std::cout << " ";
				}
			}
		}
		std::cout << std::endl;
	}
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
int Game::TakeTurn() {
	DisplayCave();
	displayPercepts();
	takeUserAction();
	detectWinorLoss();
	return true;
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void Game::displayPercepts() {
	int row = m_player_location[0];
	int col = m_player_location[1];
	/*Row+1,Col*/
	if (row < m_cave_size - 2)
		m_cave[row + 1][col].m_event->Percept();
	/*Row-1,Col*/
	if (row > 0)
		m_cave[row - 1][col].m_event->Percept();
	/*Row,Col+1*/
	if (col < m_cave_size - 2)
		m_cave[row][col + 1].m_event->Percept();
	/*Row,Col-1*/
	if (col < 0)
		m_cave[row][col - 1].m_event->Percept();
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void Game::takeUserAction() {
	move();
	m_is_chimera_dead = shootarrow();
}

void Game::checkForEvent() {

}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void Game::move() {
	std::cout << "Select One Direction for your movement:" << std::endl;
	std::cout << "A(a): go left  S(s): go down  D(d): go right  W(w): go up" << std::endl;
	char key;
	std::cin >> key;
	while (key != 'a' && key != 'A' && key != 's' && key != 'S' && key != 'd' && key != 'D' && key != 'w' && key != 'W')
	{
		std::cout << "WARNING: Please input correct move direction:" << std::endl;
		std::cin >> key;
	}
	int row = m_player_location[0];
	int col = m_player_location[1];
	if (key == 'a' || key == 'A')
	{
		if (col < 1)
		{
			std::cout << "You have reach the western wall. Cannot move left more. " << std::endl;
		}
		else {
			m_player_location[1] -= 1;
		}
	}
	else if (key == 's' || key == 'S')
	{
		if (row > m_cave_size - 2)
		{
			std::cout << "You have reach the southern wall. Cannot move down more. " << std::endl;
		}
		else {
			m_player_location[0] += 1;
		}
	}
	else if (key == 'd' || key == 'D')
	{
		if (col > m_cave_size - 2)
		{
			std::cout << "You have reach the eastern wall. Cannot move right more. " << std::endl;
		}
		else {
			m_player_location[1] += 1;
		}
	}
	else if (key == 'w' || key == 'W')
	{
		if (row < 1)
		{
			std::cout << "You have reach the northern wall. Cannot move up more. " << std::endl;
		}
		else {
			m_player_location[0] += 1;
		}
	}
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
bool Game::shootarrow() {

	std::cout << "Select One Direction for your arrow shooting:" << std::endl;
	std::cout << "Space+A(a): shoot left  Space+S(s): shoot down  Space+D(d): shoot right  Space+W(w): shoot up" << std::endl;
	std::string key;
	std::cin >> key;
	while (key != " a" && key != " A" && key != " s" && key != " S" && key != " d" && key != " D" && key != " w" && key != " W")
	{
		std::cout << "WARNING: Please input correct shoot direction:" << std::endl;
		std::cin >> key;
	}
	int row = m_player_location[0];
	int col = m_player_location[1];
	if (key == " a" || key == " A")
	{
		if (col < 1)
		{
			std::cout << "You shoot the western wall." << std::endl;
		}
		else {
			int count = 0;
			for (int i = col; col > 0; col--)
			{
				if (typeid(*m_cave[row][i].m_event).name() != "Chimera")
				{
					delete m_cave[row][i].m_event;
					m_cave[row][i].m_event = nullptr;
				}
				count++;
				if (count == 3) break;
			}
		}
	}
	else if (key == " s" || key == " S")
	{
		if (row > m_cave_size - 2)
		{
			std::cout << "You shoot the southern wall." << std::endl;
		}
		else {
			int count = 0;
			for (int i = row; row < m_cave_size - 1; row++)
			{
				if (typeid(*m_cave[i][col].m_event).name() != "Chimera")
				{
					delete m_cave[i][col].m_event;
					m_cave[i][col].m_event = nullptr;
				}
				count++;
				if (count == 3) break;
			}
		}
	}
	else if (key == " d" || key == " D")
	{
		if (col > m_cave_size - 2)
		{
			std::cout << "You shoot the eastern wall." << std::endl;
		}
		else {
			int count = 0;
			for (int i = col; col < m_cave_size - 1; col++)
			{
				if (typeid(*m_cave[row][i].m_event).name() != "Chimera")
				{
					delete m_cave[row][i].m_event;
					m_cave[row][i].m_event = nullptr;
				}
				count++;
				if (count == 3) break;
			}
		}
	}
	else if (key == " w" || key == " W")
	{
		if (row < 1)
		{
			std::cout << "You shoot the northern wall." << std::endl;
		}
		else {
			int count = 0;
			for (int i = row; row > 0; row--)
			{
				if (typeid(*m_cave[i][col].m_event).name() != "Chimera")
				{
					delete m_cave[i][col].m_event;
					m_cave[i][col].m_event = nullptr;
				}
				count++;
				if (count == 3) break;
			}
		}
	}

	return false;
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void Game::detectWinorLoss() {

}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
int Game::Play() {
	DisplayCave();
	return 1;
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void Game::Initialize() {
	for (int i = 0; i < m_cave_size; i++)
	{
		for (int j = 0; j < m_cave_size; j++)
		{
			m_cave[i][j].m_event = nullptr;
		}
	}

	srand((unsigned)time(NULL));
	int Max_event_num = m_cave_size;
	/*set 1 chimera*/
	int number_r = rand() % Max_event_num;
	int number_c = rand() % Max_event_num;
	m_cave[number_r][number_c].m_event = &m_chimera_event;

	/*set 2 bat*/
	while (m_cave[number_r][number_c].m_event != nullptr)
	{
		number_r = rand() % Max_event_num;
		number_c = rand() % Max_event_num;
	}
	m_cave[number_r][number_c].m_event = &m_bat_event;
	while (m_cave[number_r][number_c].m_event != nullptr)
	{
		number_r = rand() % Max_event_num;
		number_c = rand() % Max_event_num;
	}
	m_cave[number_r][number_c].m_event = &m_bat_event;

	/*set 2 lava*/
	while (m_cave[number_r][number_c].m_event != nullptr)
	{
		number_r = rand() % Max_event_num;
		number_c = rand() % Max_event_num;
	}
	m_cave[number_r][number_c].m_event = &m_lava_event;
	while (m_cave[number_r][number_c].m_event != nullptr)
	{
		number_r = rand() % Max_event_num;
		number_c = rand() % Max_event_num;
	}
	m_cave[number_r][number_c].m_event = &m_lava_event;

	/*set 1 gold*/
	while (m_cave[number_r][number_c].m_event != nullptr)
	{
		number_r = rand() % Max_event_num;
		number_c = rand() % Max_event_num;
	}
	m_cave[number_r][number_c].m_event = &m_gold_event;
}
