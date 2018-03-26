#include "stdafx.h"
#include "Game.h"
//#include "Game.h"
//

int Game::getScore() const {
	return score_;
}
void Game::increaseScore() {
	score_ = score_ + 1;
}

void Game::createEnemies(vector<Tank>& enemyTanks, int enemyTanksCount)
{
	for (int i = 0; i < enemyTanksCount; i++)
		enemyTanks.push_back(Tank());
}

void Game::deleteEnemy(vector<Tank>& enemies, int x, int y) {
	for (vector< Tank >::iterator i = enemies.begin(); i != enemies.end(); ++i)
	{
		int x_ = i._Ptr->getX();
		int y_ = i._Ptr->getY();

		if (enemies.size() == 1) break;

		else if ((x_ == x || x_ == x - 1 || x_ == x) && (y_ == y - 1 || y_ == y || y_ == y + 1))
			i = enemies.erase(i);

	}
};

void Game::checkColisions(Map& map, Game& game, vector<Tank>& enemies, Tank& player) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (map.map[i][j].value == 'o'&& map.map[i][j].dir == direction::UP&&i - 1 != 0)
			{
				if (map.map[i - 1][j].value == '+' || map.map[i - 1][j].value == char(219)) {
					if (map.map[i - 1][j].value == '+') {
						game.increaseScore();
						game.deleteEnemy(enemies, i, j);
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
						game.increaseScore();
						game.deleteEnemy(enemies, i, j);
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
						game.increaseScore();
						game.deleteEnemy(enemies, i, j);
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
						game.increaseScore();
						game.deleteEnemy(enemies, i, j);
					}
					map.map[i][j + 1] = Item();
					map.map[i][j] = Item();

				}
				else
					map.map[i][j + 1] = Bullet(direction::RIGHT, i, j + 1);
				map.map[i][j] = Item();
			}
			////////////////////////////////////////////////////////////////////////////////
			char val = '*';
			if (map.map[i][j].value == '*' && map.map[i][j].dir == direction::UP)
			{
				if (map.map[i - 1][j].value == 'X' || map.map[i - 1][j].value == char(219)) {
					if (map.map[i - 1][j].value == 'X') {
						player.decreaseHealth();

					}
					/*map.map[i - 1][j] = Item();*/
					map.map[i][j] = Item();

				}
				else
					map.map[i - 1][j] = Bullet(direction::UP, i - 1, j, val);
				map.map[i][j] = Item();
			}

			else if (map.map[i][j].value == '*'&& map.map[i][j].dir == direction::DOWN)
			{
				if (map.map[i + 1][j].value == 'X' || map.map[i + 1][j].value == char(219)) {
					if (map.map[i + 1][j].value == 'X')
						player.decreaseHealth();

					map.map[i][j] = Item();

				}
				else
					map.map[i + 1][j] = Bullet(direction::DOWN, i + 1, j, val);
				map.map[i][j] = Item();
			}
			else if (map.map[i][j].value == '*'&& map.map[i][j].dir == direction::LEFT)
			{
				if (map.map[i][j - 1].value == 'X' || map.map[i][j - 1].value == char(219)) {
					if (map.map[i][j - 1].value == 'X')
						player.decreaseHealth();

					map.map[i][j] = Item();

				}
				else
					map.map[i][j - 1] = Bullet(direction::LEFT, i, j - 1, val);
				map.map[i][j] = Item();
			}
			else if (map.map[i][j].value == '*'&& map.map[i][j].dir == direction::RIGHT)
			{
				if (map.map[i][j + 1].value == 'X' || map.map[i][j + 1].value == char(219)) {
					if (map.map[i][j + 1].value == 'X')
						player.decreaseHealth();

					map.map[i][j] = Item();

				}
				else
					map.map[i][j + 1] = Bullet(direction::RIGHT, i, j + 1, val);
				map.map[i][j] = Item();
			}
		}
		cout << endl;
	}
}
//
Game::Game()
{
}
Game::~Game()
{
}