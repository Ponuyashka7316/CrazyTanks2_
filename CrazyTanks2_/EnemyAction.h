#pragma once
#include "Tank.h"
#include "Map.h"
#include "Bullet.h"

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