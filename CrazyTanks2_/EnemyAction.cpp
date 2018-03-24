#include "stdafx.h"
#include "EnemyAction.h"

EnemyAction::EnemyAction()
{
}

EnemyAction::~EnemyAction()
{
}

void EnemyAction::Move(Tank& tank, Map& map) {
	int x_ = tank.getX();
	int y_ = tank.getY();
	char carr[] = { 72,75,77,80 };
	char c = carr[rand() % 4];
	if (c == 72 && x_ != 1) {
		if (map.map[x_ - 1][y_].value != char(219) && map.map[x_ - 1][y_].value != '+') {
			map.map[x_ - 1][y_] = Tank('+');
			map.map[x_][y_] = Item();
			tank.setX(x_ - 1);
			tank.dir = direction::UP;
		}
	}
	else if (c == 80 && x_ != n - 1) {
		if (map.map[x_ + 1][y_].value != char(219) && map.map[x_ + 1][y_].value != '+') {
			map.map[x_ + 1][y_] = Tank('+');
			map.map[x_][y_] = Item();
			tank.setX(x_ + 1);
			tank.dir = direction::DOWN;
		}
	}
	else if (c == 77 && x_ != n && y_ != n - 1) {
		if (map.map[x_][y_ + 1].value != char(219) && map.map[x_][y_ + 1].value != '+') {
			map.map[x_][y_ + 1] = Tank('+');
			map.map[x_][y_] = Item();
			tank.setY(y_ + 1);
			tank.dir = direction::RIGHT;
		}
	}
	else if (c == 75 && x_ != n && y_ != 1) {
		if (map.map[x_][y_ - 1].value != char(219) && map.map[x_][y_ - 1].value != '+') {
			map.map[x_][y_ - 1] = Tank('+');
			map.map[x_][y_] = Item();
			tank.setY(y_ - 1);
			tank.dir = direction::LEFT;
		}
	}
};

void EnemyAction::Shot(Tank& tank, Map& map) {
	int x_ = tank.getX();
	int y_ = tank.getY();
	char blt = '*';
	if (tank.dir == direction::UP)
		map.map[x_ - 1][y_] = Bullet(direction::UP, x_, y_, blt);
	else if (tank.dir == direction::DOWN)
		map.map[x_ + 1][y_] = Bullet(direction::DOWN, x_, y_, blt);
	else if (tank.dir == direction::LEFT)
		map.map[x_][y_ - 1] = Bullet(direction::LEFT, x_, y_, blt);
	else if (tank.dir == direction::RIGHT)
		map.map[x_][y_ + 1] = Bullet(direction::RIGHT, x_, y_, blt);
};