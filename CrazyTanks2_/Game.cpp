#include "stdafx.h"
#include "Game.h"
//#include "Game.h"
//
//#include "Bullet.h"
//void Game::checkColisions(Map& map, Game& game, vector<Tank>& enemies, Tank& player) {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (map.map[i][j].value == 'o'&& map.map[i][j].dir == direction::UP)
//			{
//				if (map.map[i - 1][j].value == '+' || map.map[i - 1][j].value == char(219)) {
//					if (map.map[i - 1][j].value == '+') {
//						game.score_++;
//						game.deleteEnemy(enemies, i, j);
//					}
//					map.map[i - 1][j] = Item();
//					map.map[i][j] = Item();
//
//				}
//				else
//					map.map[i - 1][j] = Bullet(direction::UP, i - 1, j);
//				map.map[i][j] = Item();
//			}
//
//			else if (map.map[i][j].value == 'o'&& map.map[i][j].dir == direction::DOWN)
//			{
//				if (map.map[i + 1][j].value == '+' || map.map[i + 1][j].value == char(219)) {
//					if (map.map[i + 1][j].value == '+') {
//						game.score_++;
//						game.deleteEnemy(enemies, i, j);
//					}
//					map.map[i + 1][j] = Item();
//					map.map[i][j] = Item();
//
//				}
//				else
//					map.map[i + 1][j] = Bullet(direction::DOWN, i + 1, j);
//				map.map[i][j] = Item();
//			}
//			else if (map.map[i][j].value == 'o'&& map.map[i][j].dir == direction::LEFT)
//			{
//				if (map.map[i][j - 1].value == '+' || map.map[i][j - 1].value == char(219)) {
//					if (map.map[i][j - 1].value == '+') {
//						game.score_++;
//						game.deleteEnemy(enemies, i, j);
//					}
//					map.map[i][j - 1] = Item();
//					map.map[i][j] = Item();
//
//				}
//				else
//					map.map[i][j - 1] = Bullet(direction::LEFT, i, j - 1);
//				map.map[i][j] = Item();
//			}
//			else if (map.map[i][j].value == 'o'&& map.map[i][j].dir == direction::RIGHT)
//			{
//				if (map.map[i][j + 1].value == '+' || map.map[i][j + 1].value == char(219)) {
//					if (map.map[i][j + 1].value == '+') {
//						game.score_++;
//						game.deleteEnemy(enemies, i, j);
//					}
//					map.map[i][j + 1] = Item();
//					map.map[i][j] = Item();
//
//				}
//				else
//					map.map[i][j + 1] = Bullet(direction::RIGHT, i, j + 1);
//				map.map[i][j] = Item();
//			}
//			////////////////////////////////////////////////////////////////////////////////
//			if (map.map[i][j].value == '*' && map.map[i][j].dir == direction::UP)
//			{
//				if (map.map[i - 1][j].value == 'X' || map.map[i - 1][j].value == char(219)) {
//					if (map.map[i - 1][j].value == 'X') {
//						player.health--;
//
//					}
//					/*map.map[i - 1][j] = Item();*/
//					map.map[i][j] = Item();
//
//				}
//				else
//					map.map[i - 1][j] = Bullet(direction::UP, i - 1, j);
//				map.map[i][j] = Item();
//			}
//
//			else if (map.map[i][j].value == '*'&& map.map[i][j].dir == direction::DOWN)
//			{
//				if (map.map[i + 1][j].value == 'X' || map.map[i + 1][j].value == char(219)) {
//					if (map.map[i + 1][j].value == 'X')
//						player.health--;
//
//					map.map[i][j] = Item();
//
//				}
//				else
//					map.map[i + 1][j] = Bullet(direction::DOWN, i + 1, j);
//				map.map[i][j] = Item();
//			}
//			else if (map.map[i][j].value == '*'&& map.map[i][j].dir == direction::LEFT)
//			{
//				if (map.map[i][j - 1].value == 'X' || map.map[i][j - 1].value == char(219)) {
//					if (map.map[i][j - 1].value == 'X')
//						player.health--;
//
//					map.map[i][j] = Item();
//
//				}
//				else
//					map.map[i][j - 1] = Bullet(direction::LEFT, i, j - 1);
//				map.map[i][j] = Item();
//			}
//			else if (map.map[i][j].value == '*'&& map.map[i][j].dir == direction::RIGHT)
//			{
//				if (map.map[i][j + 1].value == 'X' || map.map[i][j + 1].value == char(219)) {
//					if (map.map[i][j + 1].value == 'X')
//						player.health--;
//
//					map.map[i][j] = Item();
//
//				}
//				else
//					map.map[i][j + 1] = Bullet(direction::RIGHT, i, j + 1);
//				map.map[i][j] = Item();
//			}
//		}
//		std::cout << std::endl;
//	}
//}
//
//
//
Game::Game()
{
}
Game::~Game()
{
}