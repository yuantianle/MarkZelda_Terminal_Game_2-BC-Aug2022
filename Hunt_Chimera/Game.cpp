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
int Game::Play() {
	system("color F0");
	DisplayCave();
	DisplayPercepts(2);
	return TakeTurn();

}

void Game::Title() {
	std::cout << "\033[2;7;30m\033[8m" << std::endl;
	std::cout << "=======================================================================================\n";
	std::cout << "\033[30m\033[8m";
	std::cout << " ";
	std::cout << "\033[34m\033[8m";
	std::cout << "  | \\  | \\   | _\\\\   | ____\\ ||    // ";
	std::cout << "\033[30m\033[8m";
	std::cout << " ";
	std::cout << "\033[32m\033[8m";
	std::cout << "  _____    _____  \\ \\       \\\\   ______       ";
	std::cout << "\033[30m\033[8m";
	std::cout << " "<< std::endl;

	std::cout << " ";
	std::cout << "\033[34m\033[8m";
	std::cout << "  ||\\\\ ||\\\\  ||  \\\\  ||    \\\\||___//  ";
	std::cout << "\033[30m\033[8m";
	std::cout << " ";
	std::cout << "\033[32m\033[8m";
	std::cout << " \\____ |  \\ ___ \\  \\ \\   ____\\\\   ____\\\\      ";
	std::cout << "\033[30m\033[8m";
	std::cout << " " << std::endl;

	std::cout << " ";
	std::cout << "\033[34m\033[8m";
	std::cout << "  || \\\\|| \\\\ ||___\\\\ ||____//||---\\\\  ";
	std::cout << "\033[30m\033[8m";
	std::cout << " ";
	std::cout << "\033[32m\033[8m";
	std::cout << "     | |   \\\\ __\\\\ \\ \\   \\ ____\\  \\ ____\\     ";
	std::cout << "\033[30m\033[8m";
	std::cout << " " << std::endl;

	std::cout << " ";
	std::cout << "\033[34m\033[8m";
	std::cout << "  ||  \\ |  \\\\||    \\\\||    \\\\||    \\\\ ";
	std::cout << "\033[30m\033[8m";
	std::cout << " ";
	std::cout << "\033[32m\033[8m";
	std::cout << "    | |____ \\\\_____ \\ \\__ \\\\___\\\\  \\\\___\\\\    ";
	std::cout << "\033[30m\033[8m";
	std::cout << " " << std::endl;

	std::cout << " ";
	std::cout << "\033[36m\033[8m";
	std::cout << "        --- Link's Awakening ---      ";
	std::cout << "\033[30m\033[8m";
	std::cout << " ";
	std::cout << "\033[32m\033[8m";
	std::cout << "     |____ / \\_____\\ \\___/ \\_____\\  \\_____\\   ";
	std::cout << "\033[30m\033[8m";
	std::cout << " " << std::endl;
	std::cout << "\033[30m\033[8m";
	std::cout << "=======================================================================================" << std::endl;
	std::cout << "\033[27;30m\033[8m";
}

void Game::Win() {
	std::cout << "\033[7;30m\033[8m" << std::endl;
	std::cout << "===========================================================================\n";
	std::cout << "\033[27;32m\033[8m";
	std::cout << "           _      _      _     __________      __     _     _____                  " << std::endl;
	std::cout << "           ||    / |    //    /___   ___/     / |    //    |     |                    " << std::endl;
	std::cout << "           ||   //||   //         //         //||   //     |     |        " << std::endl;
	std::cout << "           ||  // ||  //         //         // ||  //       |   |           " << std::endl;
	std::cout << "           || //  || //         //         //  || //         |_|         " << std::endl;
	std::cout << "           ||//   ||//      ___//____     //   ||//           _          " << std::endl;
	std::cout << "           |_/    |_/     /_________/    //    |_/           |_|         " << std::endl;
	std::cout << "\033[7;30m\033[8m";
	std::cout << "============================================================================" << std::endl;
	std::cout << "\033[27;30m\033[8m";
}

void Game::Loss() {
	std::cout << "\033[7;30m\033[8m" << std::endl;
	std::cout << "============================================================================\n";
	std::cout << "\033[27;31m\033[8m";
	std::cout << "           _             ________    ________    ________    _____                  " << std::endl;
	std::cout << "           ||           | ______ |  | ______ |  | ______ |  |     |                  " << std::endl;
	std::cout << "           ||           ||      ||  ||      ||  ||      ||  |     |      " << std::endl;
	std::cout << "           ||           ||      ||  ||_______   ||_______    |   |       " << std::endl;
	std::cout << "           ||           ||      ||          ||          ||    |_|       " << std::endl;
	std::cout << "           ||_______    ||______||  ||______||  ||______||     _           " << std::endl;
	std::cout << "           |________|   |________|  |________|  |________|    |_|           " << std::endl;
	std::cout << "\033[7;30m\033[8m";
	std::cout << "============================================================================" << std::endl;
	std::cout << "\033[27;30m\033[8m";
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void Game::Welcome(){

	Title();
	std::cout << "\nGo to reach collect gold in one room and come back to where you started.\n";
	std::cout << "                                                                        \n";
	std::string k = "";
	while (k != "n" && k != "N" && k != "q" && k != "Q")
	{
		std::cout << "\033[1;30m\033[8m";
		std::cout << "   Please press ";
		std::cout << "\033[1;34m\033[8m";
		std::cout << "'N(n)'";
		std::cout << "\033[30m\033[8m";
		std::cout << " to start the game, OR press ";
		std::cout << "\033[1;31m\033[8m";
		std::cout << "'Q(q)'";
		std::cout << "\033[30m\033[8m";
		std::cout << "to quit.   \n";
		std::cin >> k;
		if (k == "n" || k == "N")
			break;
		else if (k == "q" || k == "Q")
		{
			m_quit_switch = false;
			break;
		}
	}
	std::cout << "\033[0;40;37m\033[8m" << std::endl;
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void Game::ResetVariable()
{
	m_if_find_gold = false;
	m_if_chimera_dead = false;
	m_if_chimera_sleep = true;
	m_arrow_number = 3;
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void Game::Initialize() {
	m_cave = std::vector<std::vector<Room>>(m_cave_size, std::vector<Room>(m_cave_size));

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

	/*set 1 player*/
	number_r = rand() % Max_event_num;
	number_c = rand() % Max_event_num;
	while (m_cave[number_r][number_c].m_event != nullptr)
	{
		number_r = rand() % Max_event_num;
		number_c = rand() % Max_event_num;
	}
	m_player_location[0] = number_r;
	m_player_location[1] = number_c;

	m_escape_location = m_player_location;

	m_grid.resize(m_cave_size * m_barrier_row_len + 1, std::vector<std::string>(m_cave_size * m_barrier_col_len + 1, ""));

}

/*********************************************************************
** Function: 
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void Game::DisplayCave() {

	system("CLS");
	arrange_grid();
	//edit_grid();
	draw_grid();
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void Game::arrange_grid()
{
	std::cout << "==============================================\n";
	std::cout << "\033[7;2;34m\033[8m";
	std::cout << "Game History:";
	std::cout << "\033[27;4;34m\033[8m";
	std::cout << " " << m_game_history;
	std::cout << "\033[24;30m\033[8m";

	std::cout << "\033[7;33m\033[8m";
	if (m_if_find_gold)
	{
		std::cout << "Gold Explore Status:";
		std::cout << "\033[27;4;33m\033[8m";
		std::cout << " Found!" << std::endl;
		std::cout << "\033[24;30m\033[8m";
	}
	else
	{
		std::cout << "Gold Explore Status:";
		std::cout << "\033[27;4;33m\033[8m";
		std::cout << " Not Found!" << std::endl;
		std::cout << "\033[24;30m\033[8m";
	}


	std::string chimera_sleep;
	if (m_if_chimera_sleep)
		chimera_sleep = "Chimera is sleeping..";
	else
		chimera_sleep = "Chimera is waking! Don't bother it!";

	std::cout << "\033[7;35m\033[8m";
	if (m_if_chimera_dead)
	{
		std::cout << "Chimera Status:";
		std::cout << "\033[27;4;35m\033[8m";
		std::cout << " Dead! " << std::endl;
		std::cout << "\033[24;30m\033[8m";
	}
	else
	{
		std::cout << "Chimera Status:";
		std::cout << "\033[27;4;35m\033[8m";
		std::cout << " Alive. " << chimera_sleep << std::endl;
		std::cout << "\033[24;30m\033[8m";
	}

	std::cout << "\033[7;31m\033[8m";
	std::cout << "Number of arrows you have:";
	std::cout << "\033[27;4;31m\033[8m";
	std::cout << " " << m_arrow_number << std::endl;
	std::cout << "\033[24;30m\033[8m";
	std::cout << "==============================================\n";
	int row_len = m_barrier_row_len;
	int col_len = m_barrier_col_len;


	for (int i = 0; i < m_grid.size(); i++)
	{
		for (int j = 0; j < m_grid[0].size(); j++)
		{
			if (i % row_len == 0)
			{
				if (j % col_len == 0)
					m_grid[i][j] = "+";
				else
					m_grid[i][j] = "-";
			}
			else if (i % row_len != row_len / 2)
			{
				if (j % col_len == 0)
					m_grid[i][j] = "|";
				else
					m_grid[i][j] = " ";
			}
			else
			{
				if (j % col_len == 0)
					m_grid[i][j] = "|";
				else if (j % col_len != col_len / 2)
					m_grid[i][j] = " ";
				else
				{
					m_grid[i][j] = "";
					if (m_cave[i / row_len][j / col_len].m_event != nullptr)
						m_grid[i][j] = m_cave[i / row_len][j / col_len].m_event->Logo();
					if (i / row_len == m_player_location[0] && j / col_len == m_player_location[1])
						m_grid[i][j] += "*";
					if ((i / row_len != m_player_location[0] || j / col_len != m_player_location[1]) && (m_cave[i / row_len][j / col_len].m_event == nullptr))
						m_grid[i][j] = " ";
				}
			}
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
void Game::draw_grid() {
	int row_len = m_barrier_row_len;
	int col_len = m_barrier_col_len;

	std::cout << "\033[7m\033[8m";
	for (int i = 0; i < m_grid.size(); i++)
	{
		for (int j = 0; j < m_grid[0].size(); j++)
		{
			std::string s = m_grid[i][j];
			if (i % row_len == row_len / 2)
			{
				if (j % col_len == col_len / 2)
				{
					if (i / row_len == m_player_location[0] && j / col_len == m_player_location[1])
					{
						std::cout << "\033[1;31m\033[8m";
						std::cout << s; //player
						std::cout << "\033[22;30m\033[8m";
					}
					else
					{
						if (m_debug_switch)
						{
							std::cout << "\033[27;30m\033[8m";
							if (s == "~")//items
							{
								std::cout << "\033[31m\033[8m";
							}
							else if (s == "G")
							{
								std::cout << "\033[33m\033[8m";
							}
							else if (s == "Y")
							{
								std::cout << "\033[36m\033[8m";
							}
							else if (s == "G")
							{
								std::cout << "\033[33m\033[8m";
							}
							else if (s == "M")
							{
								std::cout << "\033[35m\033[8m";
							}
							else if (s == "#")
							{
								std::cout << "\033[32m\033[8m";
							}
							std::cout << s; 	
							std::cout << "\033[7;30m\033[8m";
						}
						else
						{
							std::cout << "\033[27;30m\033[8m";
							std::cout << " ";
							std::cout << "\033[7;30m\033[8m";
						}
					}
				}
				else
				{
					if (s == " ")
					{
						std::cout << "\033[27;30m\033[8m";
						std::cout << s;
						std::cout << "\033[7;30m\033[8m";
					}
					else if (s == "#")
					{
						std::cout << "\033[27;32m\033[8m";
						std::cout << s;
						std::cout << "\033[7;30m\033[8m";
					}
					else
						std::cout << s;
				}
			}
			else
			{
				if (s == " ")
				{
					std::cout << "\033[27;30m\033[8m";
					std::cout << s;
					std::cout << "\033[7;30m\033[8m";
				}
				else if (s == "#")
				{
					std::cout << "\033[27;32m\033[8m";
					std::cout << s;
					std::cout << "\033[7;30m\033[8m";
				}
				else
					std::cout << s;
			}
		}
		std::cout << std::endl;
	}		
	std::cout << "\033[27;30m\033[8m";
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
int Game::TakeTurn() {
	/*customer take actions*/
	takeUserAction();
	int result_code = checkForEvent(); //0 loss, 1 win, 2 continue

	/*render again*/
	DisplayPercepts(result_code);
	return result_code;
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void Game::DisplayPercepts(int result_code) {
	
	if (result_code == 2)
	{
		std::cout << "\033[7;32m\033[8m";
		std::cout << "\nEvents Near You:\n";
		std::cout << "\033[27;4;32m\033[8m";
		int row = m_player_location[0];
		int col = m_player_location[1];
		bool b = true;
		/*Row+1,Col*/
		if (row < m_cave_size - 1 && m_cave[row + 1][col].m_event != nullptr)
		{
			m_cave[row + 1][col].m_event->Percept();
			b = false;
		}
		/*Row-1,Col*/
		if (row > 0 && m_cave[row - 1][col].m_event != nullptr)
		{
			m_cave[row - 1][col].m_event->Percept();
			b = true;
		}
		/*Row,Col+1*/
		if (col < m_cave_size - 1 && m_cave[row][col + 1].m_event != nullptr)
		{
			m_cave[row][col + 1].m_event->Percept();
			b = true;
		}
		/*Row,Col-1*/
		if (col > 0 && m_cave[row][col - 1].m_event != nullptr)
		{
			m_cave[row][col - 1].m_event->Percept();
			b = true;
		}
		if (b)
			std::cout << "percept nothing surrounding." << std::endl;
		std::cout << "\033[24;32m\033[8m";
		std::cout << "\033[30m\033[8m";

	}
	else
	{
		std::cout << "\033[7;32m\033[8m";
		std::cout << "Events Near You:";
		std::cout << "\033[27;4;32m\033[8m";
		std::cout << "perception not avaliable" << std::endl;
		std::cout << "\033[24;32m\033[8m";
		std::cout << "\033[30m\033[8m";
	}
	std::cout << "\033[24;30m\033[8m";

}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void Game::takeUserAction() {
	if (m_arrow_number > 0)
	{
		std::cout << "\nPlease choose the action you wanna do:\n";

		std::cout << "\033[1;34m\033[8m";
		std::cout << "    A(a).move";
		std::cout << "\033[31m\033[8m";
		std::cout << "    B(b).shoot an arrow  \n";
		std::cout << "\033[22;30m\033[8m";
		std::string chose = "";
		while (chose != "A" && chose != "a" && chose != "B" && chose != "b")
		{
			std::cin >> chose;
			if (chose != "A" && chose != "a" && chose != "B" && chose != "b")
			{
				std::cout << "\033[1;30m\033[8m";
				std::cout << "Please push ";
				std::cout << "\033[1;34m\033[8m";
				std::cout << "A(a)";
				std::cout << "\033[30m\033[8m";
				std::cout << " OR ";
				std::cout << "\033[31m\033[8m";
				std::cout << "B(b).\n";
				std::cout << "\033[22;30m\033[8m";
			}
		}
		if (chose == "A" || chose == "a")
			move();
		else
			shootarrow();
	}
	else
	{
		std::cout << "You have no arrows for choose shooting action.\n";
		move();
	}
}

int Game::checkForEvent() {
	int row = m_player_location[0];
	int col = m_player_location[1];
	int g_row, g_col;
	if (m_cave[row][col].m_event != nullptr)
	{
		int e = m_cave[row][col].m_event->ID();
		m_game_history = m_cave[row][col].m_event->Encounter();	
		std::cout << m_game_history<<std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(2));
		switch (e)
		{
		case 1:
		{	g_row = (int)(((float)row + 0.5) * (float)
					m_barrier_row_len);
			g_col = (int)(((float)col + 0.5) * (float)m_barrier_col_len) + 2;
			system("CLS");
			arrange_grid();
			m_grid[g_row][g_col] = "";
			draw_grid();

			std::this_thread::sleep_for(std::chrono::seconds(2));

			if (!m_if_chimera_sleep)
			{
				m_game_history = "You see an awake Chimera and had been aten by it.\n";
				std::cout << "You see an awake Chimera and had been aten by it.\n";
				std::this_thread::sleep_for(std::chrono::seconds(2));
				system("CLS");
				arrange_grid();
				m_grid[g_row][g_col] = "";
				draw_grid();
				return 0;
			}
			else
			{
				m_game_history = "You see an sleeping Chimera, let's move and don't bother it!\n";
				std::cout << "You see an sleeping Chimera, let's move and don't bother it!\n";
				std::this_thread::sleep_for(std::chrono::seconds(2));
				system("CLS");
				arrange_grid();
				m_grid[g_row][g_col] = "";
				draw_grid();
				return 2;
			}
		}
		case 2:
		{					
			srand((unsigned)time(NULL));
			int Max_event_num = m_cave_size;
			/*set 1 chimera*/
			int number_r = rand() % Max_event_num;
			int number_c = rand() % Max_event_num;
			while (m_cave[number_r][number_c].m_event != nullptr)
			{
				number_r = rand() % Max_event_num;
				number_c = rand() % Max_event_num;
			}
			m_player_location = {number_r, number_c};
			m_cave[number_r][number_c].m_event = &m_bat_event;
			m_cave[row][col].m_event = nullptr;
			g_row = (int)(((float)number_r + 0.5) * (float)
				m_barrier_row_len);
			g_col = (int)(((float)number_c + 0.5) * (float)m_barrier_col_len) + 2;
			
			system("CLS");
			arrange_grid();
			m_grid[g_row][g_col] = "";
			draw_grid();

			std::this_thread::sleep_for(std::chrono::seconds(2));
			m_cave[number_r][number_c].m_event = nullptr;
			m_cave[row][col].m_event = &m_bat_event;
			m_game_history = "Seen Super bats.\n";
			
			DisplayCave();
			return 2;
		}
		case 3:
		{
			g_row = (int)(((float)row + 0.5) * (float)
				m_barrier_row_len);
			g_col = (int)(((float)col + 0.5) * (float)m_barrier_col_len) + 2;

			system("CLS");
			arrange_grid();
			m_grid[g_row][g_col] = "";
			draw_grid();

			std::cout << "You falled in fire and had been killed by Lava.\n";
			std::this_thread::sleep_for(std::chrono::seconds(2));
			m_game_history = "You falled in fire and had been killed by Lava.\n";

			return 0;
		}
		case 4:
		{
			g_row = (int)(((float)row + 0.5) * (float)
				m_barrier_row_len);
			g_col = (int)(((float)col + 0.5) * (float)m_barrier_col_len) + 2;

			system("CLS");
			arrange_grid();
			m_grid[g_row][g_col] = "";
			draw_grid();

			std::this_thread::sleep_for(std::chrono::seconds(2));
			m_game_history = "You find the Gold in this cave!\n";
			m_cave[row][col].m_event = nullptr;
			m_if_find_gold = true;
			DisplayCave();
			break;
		}
		}
	}
	if (m_if_find_gold == true && m_player_location == m_escape_location)
	{
		DisplayCave();
		return 1;
	}
	else
		return 2;
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void Game::move() {
	std::cout << "\033[34m\033[8m";
	std::cout << "Select One Direction for your movement:" << std::endl;
	std::cout << "\033[30m\033[8m";
	std::cout << "A(a): go left  S(s): go down  D(d): go right  W(w): go up" << std::endl;
	char key;
	std::cin >> key;
	while (key != 'a' && key != 'A' && key != 's' && key != 'S' && key != 'd' && key != 'D' && key != 'w' && key != 'W')
	{
		std::cout << "\033[31m\033[8m";
		std::cout << "WARNING: Please input correct move direction:" << std::endl;	
		std::cout << "\033[30m\033[8m";
		std::cin >> key;
	}
	int row = m_player_location[0];
	int col = m_player_location[1];

	std::cout << "\033[7;31m\033[8m";
	if (key == 'a' || key == 'A')
	{
		if (col < 1)
		{
			std::cout << "You have reach the western wall. Cannot move left more. " << std::endl;
		}
		else {
			m_player_location[1] -= 1;
			m_game_history = "Moved left.\n";
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
			m_game_history = "Moved south.\n";
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
			m_game_history = "Moved right.\n";
		}
	}
	else if (key == 'w' || key == 'W')
	{
		if (row < 1)
		{
			std::cout << "You have reach the northern wall. Cannot move up more. " << std::endl;
		}
		else {
			m_player_location[0] -= 1;
			m_game_history = "Moved up.\n";
		}
	}
	std::cout << "\033[27;30m\033[8m";
}

/*********************************************************************
** Function:
** Description:
** Parameters:
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
void Game::shootarrow() {

	std::cout << "\033[31m\033[8m";
	std::cout << "Select One Direction for your arrow shooting:" << std::endl;
	std::cout << "\033[30m\033[8m";
	std::cout << "'Space' + A(a) : shoot left  'Space' + S(s) : shoot down  'Space' + D(d) : shoot right  'Space' + W(w) : shoot up" << std::endl;
	std::string key;
	getline(std::cin, key);
	getline(std::cin, key);
	while (key != " a" && key != " A" && key != " s" && key != " S" && key != " d" && key != " D" && key != " w" && key != " W")
	{
		std::cout << "\033[31m\033[8m";
		std::cout << "WARNING: Please input correct shoot direction:" << std::endl;
		std::cout << "\033[30m\033[8m";
		getline(std::cin, key);
		
	}
	int row = m_player_location[0];
	int col = m_player_location[1];
	std::cout << "\033[7;31m\033[8m";
	if (key == " a" || key == " A")
	{
		m_game_history = "Shoot arrow to western.\n";
		int count = 3;
		for (int i = col - 1; i >= 0; i--)
		{
			if (m_cave[row][i].m_event != nullptr && m_cave[row][i].m_event->ID() == 1)
			{
				srand((unsigned)time(NULL));
				int number = rand() % 1;
				if (number == 0)
				{
					std::cout << "Arrow misses Chimera on its orbit"<< std::endl;
					std::cout << "Chimera is awake, it fled into another room" << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(3));
					int r = rand() % m_cave_size;
					int c = rand() % m_cave_size;
					while (m_cave[r][c].m_event != nullptr && r != m_player_location[0] && c != m_player_location[1])
					{
						r = rand() % m_cave_size;
						c = rand() % m_cave_size;
					}
					m_cave[r][c].m_event = &m_chimera_event;
					m_cave[row][i].m_event = nullptr;
					m_if_chimera_sleep = false;
				}
				else
				{
					std::cout << "Arrow killed the Chimera on its orbit"<< std::endl;
					m_cave[row][i].m_event = nullptr;
					m_if_chimera_dead = true;
					break;
				}	
			}
			else if (i <= 0 && count > 0)
			{
				int g_row = (int)(((float)row + 0.5) * (float)
					m_barrier_row_len);
				int g_col = (int)(((float)i + 0.5) * (float)m_barrier_col_len) + 1;
				system("CLS");
				arrange_grid();
				m_grid[g_row][g_col] = "#";
				m_grid[g_row][g_col + 1] += "";
				draw_grid();
				std::this_thread::sleep_for(std::chrono::seconds(1));
				std::cout << "Shooting stop because of the western wall." << std::endl;
				DisplayCave();
				break;
			}
			int g_row = (int)(((float)row + 0.5) * (float)
				m_barrier_row_len);
			int g_col = (int)(((float)i + 0.5) * (float)m_barrier_col_len) + 1;

			system("CLS");
			arrange_grid();
			m_grid[g_row][g_col] = "#";
			m_grid[g_row][g_col + 1] += "";
			draw_grid();
			std::this_thread::sleep_for(std::chrono::seconds(1));

			DisplayCave();

			count--;
			if (count == 0) break;
		}	
		if (count == 3)
		{
			std::cout << "Shooting stop because of the western wall." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}
	}
	else if (key == " s" || key == " S")
	{
		m_game_history = "Shoot arrow to southern.\n";
		int count = 3;
		for (int i = row + 1; i < m_cave_size; i++)
		{
			if (m_cave[i][col].m_event != nullptr && m_cave[i][col].m_event->ID() == 1)
			{
				srand((unsigned)time(NULL));
				int number = rand() % 1;
				if (number == 0)
				{
					std::cout << "Arrow misses Chimera on its orbit" << std::endl;
					std::cout << "Chimera is awake, it fled into another room" << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(3));
					int r = rand() % m_cave_size;
					int c = rand() % m_cave_size;
					while (m_cave[r][c].m_event != nullptr && r != m_player_location[0] && c != m_player_location[1])
					{
						r = rand() % m_cave_size;
						c = rand() % m_cave_size;
					}
					m_cave[r][c].m_event = &m_chimera_event;
					m_cave[i][col].m_event = nullptr;
					m_if_chimera_sleep = false;
				}
				else
				{
					std::cout << "Arrow killed the Chimera on its orbit" << std::endl;
					m_cave[i][col].m_event = nullptr;
					m_if_chimera_dead = true;
					break;
				}
			}
			else if (i >= m_cave_size - 1 && count > 0)
			{
				int g_row = (int)(((float)i + 0.5) * (float)
					m_barrier_row_len);
				int g_col = (int)(((float)col + 0.5) * (float)m_barrier_col_len) + 1;
				system("CLS");
				arrange_grid();
				m_grid[g_row][g_col] = "#";
				m_grid[g_row][g_col + 1] += "";
				draw_grid();
				std::this_thread::sleep_for(std::chrono::seconds(1));
				std::cout << "Shooting stop because of the southern wall." << std::endl;
				DisplayCave();
				break;
			}

			int g_row = (int)(((float)i + 0.5) * (float)
				m_barrier_row_len);
			int g_col = (int)(((float)col + 0.5) * (float)m_barrier_col_len) + 1;

			system("CLS");
			arrange_grid();
			m_grid[g_row][g_col] = "#";
			m_grid[g_row][g_col + 1] += "";
			draw_grid();
			std::this_thread::sleep_for(std::chrono::seconds(1));

			DisplayCave();

			count--;
			if (count == 0) break;
		}
		if (count == 3)
		{
			std::cout << "Shooting stop because of the southern wall." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}
	}
	else if (key == " d" || key == " D")
	{
		m_game_history = "Shoot arrow to eastern.\n";
		int count = 3;
		for (int i = col+1; i < m_cave_size; i++)
		{
			if (m_cave[row][i].m_event != nullptr && m_cave[row][i].m_event->ID() == 1)
			{
				srand((unsigned)time(NULL));
				int number = rand() % 1;
				if (number == 0)
				{
					std::cout << "Arrow misses Chimera on its orbit" << std::endl;
					std::cout << "Chimera is awake, it fled into another room" << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(3));
					int r = rand() % m_cave_size;
					int c = rand() % m_cave_size;
					while (m_cave[r][c].m_event != nullptr && r != m_player_location[0] && c != m_player_location[1])
					{
						r = rand() % m_cave_size;
						c = rand() % m_cave_size;
					}
					m_cave[r][c].m_event = &m_chimera_event;
					m_cave[row][i].m_event = nullptr;
					m_if_chimera_sleep = false;
				}
				else
				{
					std::cout << "Arrow killed the Chimera on its orbit" << std::endl;
					m_cave[row][i].m_event = nullptr;
					m_if_chimera_dead = true;
					break;
				}

			}
			else if (i >= m_cave_size - 1 && count > 0)
			{
				int g_row = (int)(((float)row + 0.5) * (float)
					m_barrier_row_len);
				int g_col = (int)(((float)i + 0.5) * (float)m_barrier_col_len) + 1;
				system("CLS");
				arrange_grid();
				m_grid[g_row][g_col] = "#";
				m_grid[g_row][g_col + 1] += "";
				draw_grid();
				std::this_thread::sleep_for(std::chrono::seconds(1));
				std::cout << "Shooting stop because of the eastern wall." << std::endl;
				DisplayCave();
				break;
			}

			int g_row = (int)(((float)row + 0.5) * (float)
				m_barrier_row_len);
			int g_col = (int)(((float)i + 0.5) * (float)m_barrier_col_len) + 1;

			system("CLS");
			arrange_grid();
			m_grid[g_row][g_col] = "#";
			m_grid[g_row][g_col + 1] += "";
			draw_grid();
			std::this_thread::sleep_for(std::chrono::seconds(1));

			DisplayCave();

			count--;
			if (count == 0) break;
		}
		if (count == 3)
		{
			std::cout << "Shooting stop because of the eastern wall." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}
	}
	else if (key == " w" || key == " W")
	{		
		m_game_history = "Shoot arrow to northern.\n";
		int count = 3;
		for (int i = row-1; i >= 0; i--)
		{
			if (m_cave[i][col].m_event != nullptr && m_cave[i][col].m_event->ID() == 1)
			{
				srand((unsigned)time(NULL));
				int number = rand() % 1;
				if (number == 0)
				{
					std::cout << "Arrow misses Chimera on its orbit" << std::endl;
					std::cout << "Chimera is awake, it fled into another room" << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(3));
					int r = rand() % m_cave_size;
					int c = rand() % m_cave_size;
					while (m_cave[r][c].m_event != nullptr && r != m_player_location[0] && c != m_player_location[1])
					{
						r = rand() % m_cave_size;
						c = rand() % m_cave_size;
					}
					m_cave[r][c].m_event = &m_chimera_event;
					m_cave[i][col].m_event = nullptr;
					m_if_chimera_sleep = false;
				}
				else
				{
					std::cout << "Arrow killed the Chimera on its orbit" << std::endl;
					m_cave[i][col].m_event = nullptr;
					m_if_chimera_dead = true;
					break;
				}

			}
			else if (i <= 0 && count > 0)
			{
				int g_row = (int)(((float)i + 0.5) * (float)
					m_barrier_row_len);
				int g_col = (int)(((float)col + 0.5) * (float)m_barrier_col_len) + 1;
				system("CLS");
				arrange_grid();
				m_grid[g_row][g_col] = "#";
				m_grid[g_row][g_col + 1] += "";
				draw_grid();
				std::this_thread::sleep_for(std::chrono::seconds(1));
				std::cout << "Shooting stop because of the northern wall." << std::endl;
				DisplayCave();
				break;
			}

			int g_row = (int)(((float)i + 0.5) * (float)
				m_barrier_row_len);
			int g_col = (int)(((float)col + 0.5) * (float)m_barrier_col_len) + 1;

			system("CLS");
			arrange_grid();
			m_grid[g_row][g_col] = "#";
			m_grid[g_row][g_col+1] += "";
			draw_grid();
			std::this_thread::sleep_for(std::chrono::seconds(1));

			DisplayCave();

			count--;
			if (count == 0) break;
		}
		if (count == 3)
		{
			std::cout << "Shooting stop because of the northern wall." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}
	}
	std::cout << "\033[27;30m\033[8m";
	m_arrow_number -= 1;
	DisplayCave();
}

