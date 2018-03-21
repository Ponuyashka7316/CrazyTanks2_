// CrazyTanks2_.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "Item.h"
#include "IAction.h"
#include "Tank.h"
#include "direction.h"
using namespace std;
const int n = 30;
const int m = 80;


//enum class direction { UP, DOWN, LEFT, RIGHT };

//class IAction
//{
//public:
//	IAction();
//	virtual void Move(Tank& tank) = 0;
//	virtual void Shot(Tank& tank) = 0;
//
//	virtual ~IAction();
//
//private:
//
//};
class PlayerAction :IAction
{
public:
	PlayerAction();
	void Move(Tank& tank) {};
	void Shot(Tank& tank) {};

	~PlayerAction();
private:

};

PlayerAction::PlayerAction()
{
}

PlayerAction::~PlayerAction()
{
}

class EnemyAction :IAction
{
public:
	EnemyAction();
	void Move(Tank& tank) {};
	void Shot(Tank& tank) {};


	~EnemyAction();

private:

};

EnemyAction::EnemyAction()
{
}

EnemyAction::~EnemyAction()
{
}
//class Tank :public Item
//{
//public:
//	void setHealth(int value) {
//		if (value >= 0 && value < 1000)
//			this->health = value;
//		else
//			this->health = 1;
//	}
//	int health = 0;
//	direction dir = direction::UP;
//	Tank() { value = '+'; };
//	~Tank();
//	Tank(char ch) { value = ch; }
//private:
//
//};

//class Item
//{
//public:
//	Item();
//	IAction* ptr;
//
//	//void Shot(IAction* ptr) {}
//
//
//	char value = ' ';
//	Item(IAction* it) : p(it) {}
//	~Item() {  }
//	void Move(Tank& tank) {
//		p->Move(tank);
//	}
//	void Shot(Tank& tank) {
//		p->Shot(tank);
//	}
//private:
//	IAction * p;
//
//};
//Item::Item()
//{
//}




Tank::~Tank()
{
}





class Gold :public Item
{
public:
	Gold() { value = 'W'; };
	~Gold();

private:

};
void setcur(int x, int y)		//set coursor to x y 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};
Gold::~Gold()
{
}
class Wall :public Item
{
public:
	Wall() { value = char(219); }
	~Wall();

private:
	//char value = char(219);
};


Wall::~Wall()
{
}

class Map
{
public:
	Map(vector<Tank>& enemyTanks, Tank& playerTank)
	{
		srand(time(NULL));


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
					map[i][j] = Wall();

				if (i == n - 2 && j == m / 2 - 2)
					map[i][j] = Wall();
				if (i == n - 3 && j == m / 2 - 1)
					map[i][j] = Wall();
				if (i == n - 3 && j == m / 2 - 2)
					map[i][j] = Wall();
				if (i == n - 3 && j == m / 2)
					map[i][j] = Wall();
				if (i == n - 2 && j == m / 2)
					map[i][j] = Wall();
				if (i == n - 2 && j == m / 2 - 1)
					map[i][j] = Gold();
				if (i < n - 5 && rand() % 10 == 1)
					map[i][j] = Wall();
			}
		}

		map[n - 2][m / 2 + 2] = playerTank;
		int x;
		int y;
		for (auto tank : enemyTanks)
		{

			while (true)
			{
				x = rand() % n;
				y = rand() % m;
				if (map[x][y].value == ' ')
				{
					map[x][y] = Tank();
					break;
				}
			}

		}
	}
	~Map();

	//private:
	Item map[n][m];
};

Map::~Map()
{
}


class Game
{
public:
	Game();
	~Game();
	int score_ = 0;
private:

};



Game::Game()
{
}
Game::~Game()
{
}

void preRender(Map* map) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map->map[i][j].value;
		}
		cout << endl;
	}
}

void render(Map* map) {
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			cout << map->map[i][j].value;
		}

		cout << endl; setcur(i + 1, 1);
	}
}



IAction::IAction()
{
}

IAction::~IAction()
{
}



bool ShowConsoleCursor(bool bShow)
{
	CONSOLE_CURSOR_INFO cci;
	HANDLE hStdOut;
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE)
		return FALSE;
	if (!GetConsoleCursorInfo(hStdOut, &cci))
		return FALSE;
	cci.bVisible = bShow;
	if (!SetConsoleCursorInfo(hStdOut, &cci))
		return FALSE;
	return TRUE;
}
int main()
{
	ShowConsoleCursor(false);
	char playerIcon = 'X';
	Tank playerTank(playerIcon);
	vector<Tank> enemyTanks;
	int enemyTanksCount = 5;
	for (int i = 0; i < enemyTanksCount; i++)
		enemyTanks.push_back(Tank());
	Game *game = new Game();
	Map *map = new Map(enemyTanks, playerTank);
	char ch = '\0';

	preRender(map);
	setcur(1, 1);
	while (true)
	{
		if (_kbhit()) {

			ch = _getch();
			/*if (ch == char(72) || ch == 80 || ch == 77 || ch == 75)
				pTank.tankMove(pTank, arr, n, m, ch);
			else if (ch == 32 && pTank.getIsShoot() == false) {
				pTank.shot(bulletsMap, arr, n, m, 'o');
				pTank.setIsShoot(true);*/
		}

		if (map->map[n - 2][m / 2 - 1].value != 'W')
			break;
		render(map);
		setcur(1, 1);
	}
	_getch();
	return 0;
}

