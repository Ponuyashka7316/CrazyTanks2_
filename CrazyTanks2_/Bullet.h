#pragma once

#include "Item.h"
#include "direction.h"
class Bullet :public Item
{
public:
	Bullet(direction d, int x, int y, char val = 'o')
	{ 
		value = val; 
		dir = d;
		x_ = x;
		y_ = y;
	};
	~Bullet();
	int x_;
	int y_;

private:
	//direction dir;
};

