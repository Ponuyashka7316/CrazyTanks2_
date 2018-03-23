//#pragma once
//#include "Map.h"
//#include "Bullet.h"
//
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