// CrazyTanks2_.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <memory>
#include "Item.h"
#include "Map.h"
#include "Game.h"
#include "Bullet.h"
#include "Tank.h"
#include "EnemyAction.h"
#include "PlayerAction.h"
#include "UI.h"
//#include "Wall.h"
//#include "Gold.h"

using namespace std;
//const int n = 30;
//const int m = 80;
class Item;
class Tank;
class IAction;


void setcur(int x, int y)		//set coursor to x y 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};

//class Map
//{
//public:
//	Map(vector<Tank>& enemytanks, Tank& playerTank)
//	{
//		srand(time(NULL));
//
//
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < m; j++)
//			{
//				if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
//					map[i][j] = Wall();
//
//				if (i == n - 2 && j == m / 2 - 2)
//					map[i][j] = Wall();
//				if (i == n - 3 && j == m / 2 - 1)
//					map[i][j] = Wall();
//				if (i == n - 3 && j == m / 2 - 2)
//					map[i][j] = Wall();
//				if (i == n - 3 && j == m / 2)
//					map[i][j] = Wall();
//				if (i == n - 2 && j == m / 2)
//					map[i][j] = Wall();
//				if (i == n - 2 && j == m / 2 - 1)
//					map[i][j] = Gold();
//				if (i < n - 5 && rand() % 10 == 1)
//					map[i][j] = Wall();
//			}
//		}
//
//		map[n - 2][m / 2 + 2] = playerTank;
//		playerTank.x_ = n - 2;
//		playerTank.y_ = m / 2 + 2;
//		int x;
//		int y;
//		for (auto &tank : enemytanks)
//		{
//
//			while (true)
//			{
//				x = rand() % n;
//				y = rand() % m;
//				if (map[x][y].value == ' ')
//				{
//					map[x][y] = Tank();
//					tank.x_ = x;
//					tank.y_ = y;
//					break;
//				}
//			}
//
//		}
//	}
//	~Map();
//
//	//private:
//	Item map[n][m];
//};
//
//Map::~Map()
//{
//}



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

		cout << endl << char(219);
	}

}
void deleteEnemy(vector<Tank>& enemies, int x, int y) {
	for (vector< Tank >::iterator i = enemies.begin(); i != enemies.end(); ++i)
	{
		/*try {*/
		if (enemies.size() == 1) break;
		
		else if ((i._Ptr->x_ == x || i._Ptr->x_ == x - 1 || i._Ptr->x_ == x) && (i._Ptr->y_ == y - 1 || i._Ptr->y_ == y || i._Ptr->y_ == y + 1))
			i = enemies.erase(i);
		/*}
		catch (invalid_argument& e) {e};*/
	}
};

void checkColisions(Map& map, Game& game, vector<Tank>& enemies, Tank& player) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (map.map[i][j].value == 'o'&& map.map[i][j].dir == direction::UP&&i - 1 != 0)
			{
				if (map.map[i - 1][j].value == '+' || map.map[i - 1][j].value == char(219)) {
					if (map.map[i - 1][j].value == '+') {
						game.score_++;
						deleteEnemy(enemies, i, j);
					}
					map.map[i - 1][j] = Item();
					map.map[i][j] = Item();

				}
				else
					map.map[i - 1][j] = Bullet(direction::UP, i - 1, j);
				map.map[i][j] = Item();
			}

			else if (map.map[i][j].value == 'o'&& map.map[i][j].dir == direction::DOWN && i + 1 != n)
			{
				if (map.map[i + 1][j].value == '+' || map.map[i + 1][j].value == char(219)) {
					if (map.map[i + 1][j].value == '+') {
						game.score_++;
						deleteEnemy(enemies, i, j);
					}
					map.map[i + 1][j] = Item();
					map.map[i][j] = Item();

				}
				else
					map.map[i + 1][j] = Bullet(direction::DOWN, i + 1, j);
				map.map[i][j] = Item();
			}
			else if (map.map[i][j].value == 'o'&& map.map[i][j].dir == direction::LEFT &&j - 1 != 0)
			{
				if (map.map[i][j - 1].value == '+' || map.map[i][j - 1].value == char(219)) {
					if (map.map[i][j - 1].value == '+') {
						game.score_++;
						deleteEnemy(enemies, i, j);
					}
					map.map[i][j - 1] = Item();
					map.map[i][j] = Item();

				}
				else
					map.map[i][j - 1] = Bullet(direction::LEFT, i, j - 1);
				map.map[i][j] = Item();
			}
			else if (map.map[i][j].value == 'o'&& map.map[i][j].dir == direction::RIGHT)
			{
				if (map.map[i][j + 1].value == '+' || map.map[i][j + 1].value == char(219)) {
					if (map.map[i][j + 1].value == '+') {
						game.score_++;
						deleteEnemy(enemies, i, j);
					}
					map.map[i][j + 1] = Item();
					map.map[i][j] = Item();

				}
				else
					map.map[i][j + 1] = Bullet(direction::RIGHT, i, j + 1);
				map.map[i][j] = Item();
			}
			////////////////////////////////////////////////////////////////////////////////
			if (map.map[i][j].value == '*' && map.map[i][j].dir == direction::UP)
			{
				if (map.map[i - 1][j].value == 'X' || map.map[i - 1][j].value == char(219)) {
					if (map.map[i - 1][j].value == 'X') {
						player.health--;

					}
					/*map.map[i - 1][j] = Item();*/
					map.map[i][j] = Item();

				}
				else
					map.map[i - 1][j] = Bullet(direction::UP, i - 1, j);
				map.map[i][j] = Item();
			}

			else if (map.map[i][j].value == '*'&& map.map[i][j].dir == direction::DOWN)
			{
				if (map.map[i + 1][j].value == 'X' || map.map[i + 1][j].value == char(219)) {
					if (map.map[i + 1][j].value == 'X')
						player.health--;

					map.map[i][j] = Item();

				}
				else
					map.map[i + 1][j] = Bullet(direction::DOWN, i + 1, j);
				map.map[i][j] = Item();
			}
			else if (map.map[i][j].value == '*'&& map.map[i][j].dir == direction::LEFT)
			{
				if (map.map[i][j - 1].value == 'X' || map.map[i][j - 1].value == char(219)) {
					if (map.map[i][j - 1].value == 'X')
						player.health--;

					map.map[i][j] = Item();

				}
				else
					map.map[i][j - 1] = Bullet(direction::LEFT, i, j - 1);
				map.map[i][j] = Item();
			}
			else if (map.map[i][j].value == '*'&& map.map[i][j].dir == direction::RIGHT)
			{
				if (map.map[i][j + 1].value == 'X' || map.map[i][j + 1].value == char(219)) {
					if (map.map[i][j + 1].value == 'X')
						player.health--;

					map.map[i][j] = Item();

				}
				else
					map.map[i][j + 1] = Bullet(direction::RIGHT, i, j + 1);
				map.map[i][j] = Item();
			}
		}
		cout << endl;
	}
}

//class PlayerAction //:public IAction
//{
//public:
//	PlayerAction() {};
//	void Move(Map& map, Tank& tank, char ch) {
//		if (ch == 72 && tank.x_ != 1) {
//			if (map.map[tank.x_ - 1][tank.y_].value != char(219) && map.map[tank.x_ - 1][tank.y_].value != '+') {
//				map.map[tank.x_ - 1][tank.y_] = Tank('X');
//				map.map[tank.x_][tank.y_] = Item();
//				tank.x_ -= 1;
//				tank.dir = direction::UP;
//			}
//		}
//		else if (ch == 80 && tank.x_ != n - 1) {
//			if (map.map[tank.x_ + 1][tank.y_].value != char(219) && map.map[tank.x_ + 1][tank.y_].value != '+') {
//				map.map[tank.x_ + 1][tank.y_] = Tank('X');
//				map.map[tank.x_][tank.y_] = Item();
//				tank.x_ += 1;
//				tank.dir = direction::DOWN;
//			}
//		}
//		else if (ch == 77 && tank.x_ != n && tank.y_ != n - 1) {
//			if (map.map[tank.x_][tank.y_ + 1].value != char(219) && map.map[tank.x_][tank.y_ + 1].value != '+') {
//				map.map[tank.x_][tank.y_ + 1] = Tank('X');
//				map.map[tank.x_][tank.y_] = Item();
//				tank.y_ += 1;
//				tank.dir = direction::RIGHT;
//			}
//		}
//		else if (ch == 75 && tank.x_ != n && tank.y_ != 1) {
//			if (map.map[tank.x_][tank.y_ - 1].value != char(219) && map.map[tank.x_][tank.y_ - 1].value != '+') {
//				map.map[tank.x_][tank.y_ - 1] = Tank('X');
//				map.map[tank.x_][tank.y_] = Item();
//				tank.y_ -= 1;
//				tank.dir = direction::LEFT;
//			}
//		}
//	};
//	static void Shot(Map& map, Tank& tank) {
//		if (tank.dir == direction::UP)
//			map.map[tank.x_ - 1][tank.y_] = Bullet(direction::UP, tank.x_, tank.y_);
//		else if (tank.dir == direction::DOWN)
//			map.map[tank.x_ + 1][tank.y_] = Bullet(direction::DOWN, tank.x_, tank.y_);
//		else if (tank.dir == direction::LEFT)
//			map.map[tank.x_][tank.y_ - 1] = Bullet(direction::LEFT, tank.x_, tank.y_);
//		else if (tank.dir == direction::RIGHT)
//			map.map[tank.x_][tank.y_ + 1] = Bullet(direction::RIGHT, tank.x_, tank.y_);
//	};
//
//	~PlayerAction() {};
//private:
//
//};



class EnemyAction //:public iaction
{
public:
	EnemyAction();
	void Move(Tank& tank, Map& map) {
		char carr[] = { 72,75,77,80 };
		char c = carr[rand() % 4];
		if (c == 72 && tank.x_ != 1) {
			if (map.map[tank.x_ - 1][tank.y_].value != char(219) && map.map[tank.x_ - 1][tank.y_].value != '+') {
				map.map[tank.x_ - 1][tank.y_] = Tank('+');
				map.map[tank.x_][tank.y_] = Item();
				tank.x_ -= 1;
				tank.dir = direction::UP;
			}
		}
		else if (c == 80 && tank.x_ != n - 1) {
			if (map.map[tank.x_ + 1][tank.y_].value != char(219) && map.map[tank.x_ + 1][tank.y_].value != '+') {
				map.map[tank.x_ + 1][tank.y_] = Tank('+');
				map.map[tank.x_][tank.y_] = Item();
				tank.x_ += 1;
				tank.dir = direction::DOWN;
			}
		}
		else if (c == 77 && tank.x_ != n && tank.y_ != n - 1) {
			if (map.map[tank.x_][tank.y_ + 1].value != char(219) && map.map[tank.x_][tank.y_ + 1].value != '+') {
				map.map[tank.x_][tank.y_ + 1] = Tank('+');
				map.map[tank.x_][tank.y_] = Item();
				tank.y_ += 1;
				tank.dir = direction::RIGHT;
			}
		}
		else if (c == 75 && tank.x_ != n && tank.y_ != 1) {
			if (map.map[tank.x_][tank.y_ - 1].value != char(219) && map.map[tank.x_][tank.y_ - 1].value != '+') {
				map.map[tank.x_][tank.y_ - 1] = Tank('+');
				map.map[tank.x_][tank.y_] = Item();
				tank.y_ -= 1;
				tank.dir = direction::LEFT;
			}
		}
	};
	void Shot(Tank& tank, Map& map) {
		char blt = '*';
		if (tank.dir == direction::UP)
			map.map[tank.x_ - 1][tank.y_] = Bullet(direction::UP, tank.x_, tank.y_, blt);
		else if (tank.dir == direction::DOWN)
			map.map[tank.x_ + 1][tank.y_] = Bullet(direction::DOWN, tank.x_, tank.y_, blt);
		else if (tank.dir == direction::LEFT)
			map.map[tank.x_][tank.y_ - 1] = Bullet(direction::LEFT, tank.x_, tank.y_, blt);
		else if (tank.dir == direction::RIGHT)
			map.map[tank.x_][tank.y_ + 1] = Bullet(direction::RIGHT, tank.x_, tank.y_, blt);
	};


	~EnemyAction();

private:

};

EnemyAction::EnemyAction()
{
}

EnemyAction::~EnemyAction()
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
	system("mode con cols=85 lines=40");
	ShowConsoleCursor(false);
	char playerIcon = 'X';
	Tank playerTank(playerIcon);
	playerTank.setHealth(3);
	vector<Tank> enemyTanks;
	int enemyTanksCount = 5;
	for (int i = 0; i < enemyTanksCount; i++)
		enemyTanks.push_back(Tank());
	Game* game = new Game();
	Map* map = new Map(enemyTanks, playerTank);
	char ch = '\0';
	PlayerAction pAction;
	EnemyAction eAction;
	//UI ui;
	//ui.preRender(map);
	preRender(map);
	setcur(1, 1);
	while (true)
	{
		//game.checkColisions(*map, *game, enemyTanks, playerTank);
		checkColisions(*map, *game, enemyTanks, playerTank);
		setcur(1, 1);
		if (_kbhit()) {

			ch = _getch();
			if (ch == char(72) || ch == 80 || ch == 77 || ch == 75)
				pAction.Move(*map, playerTank, ch);
			else if (ch == 32) {
				pAction.Shot(*map, playerTank);

			}
		}
		if (clock() % 10 == 0)
		{
			for (auto &item : enemyTanks)
			{
				eAction.Move(item, *map);
			}
		}
		if (clock() % 30 == 0)
		{
			for (auto &item : enemyTanks)
			{
				eAction.Shot(item, *map);
			}
		}
		if (map->map[n - 2][m / 2 - 1].value != 'W')
			break;
		//ui.render(map);
		render(map);
		setcur(0, n + 1);
		cout << game->score_ << endl;
		cout << clock() << endl;
		cout << playerTank.health << endl;
		setcur(0, 0);
		if (playerTank.health == 0) break;
	}
	cout << "Your score: " << game->score_;
	_getch();
	return 0;
}

