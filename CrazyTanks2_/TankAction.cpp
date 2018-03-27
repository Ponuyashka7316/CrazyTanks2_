#include "stdafx.h"
#include "TankAction.h"


TankAction::TankAction() 
{
};
TankAction::~TankAction()
{
};
void TankAction::Move(Map& map, Tank& tank, char ch, char val)
{
	int x_ = tank.getX();
	int y_ = tank.getY();
	if (ch == 72 && x_ != 1) {
		if (map.map[x_ - 1][y_].value != char(219) && map.map[x_ - 1][y_].value != '+') {
			map.map[x_ - 1][y_] = Tank(val);
			map.map[x_][y_] = Item();
			tank.setX(x_ - 1);
			tank.dir = direction::UP;
		}
	}
	else if (ch == 80 && x_ != n - 1) {
		if (map.map[x_ + 1][y_].value != char(219) && map.map[x_ + 1][y_].value != '+') {
			map.map[x_ + 1][y_] = Tank(val);
			map.map[x_][y_] = Item();
			tank.setX(x_ + 1);
			tank.dir = direction::DOWN;
		}
	}
	else if (ch == 77 && x_ != n && y_ != n - 1) {
		if (map.map[x_][y_ + 1].value != char(219) && map.map[x_][y_ + 1].value != '+') {
			map.map[x_][y_ + 1] = Tank(val);
			map.map[x_][y_] = Item();
			tank.setY(y_ + 1);
			tank.dir = direction::RIGHT;
		}
	}
	else if (ch == 75 && x_ != n && y_ != 1) {
		if (map.map[x_][y_ - 1].value != char(219) && map.map[x_][y_ - 1].value != '+') {
			map.map[x_][y_ - 1] = Tank(val);
			map.map[x_][y_] = Item();
			tank.setY(y_ - 1);
			tank.dir = direction::LEFT;
		}
	}
};
 void TankAction::Shot(Map& map, Tank& tank, char val) 
 {
	int x_ = tank.getX();
	int y_ = tank.getY();
	if (tank.dir == direction::UP)
		map.map[x_ - 1][y_] = Bullet(direction::UP, x_, y_, val);
	else if (tank.dir == direction::DOWN)
		map.map[x_ + 1][y_] = Bullet(direction::DOWN, x_, y_, val);
	else if (tank.dir == direction::LEFT)
		map.map[x_][y_ - 1] = Bullet(direction::LEFT, x_, y_, val);
	else if (tank.dir == direction::RIGHT)
		map.map[x_][y_ + 1] = Bullet(direction::RIGHT, x_, y_, val);
};
