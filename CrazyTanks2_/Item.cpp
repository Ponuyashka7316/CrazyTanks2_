#include "stdafx.h"
#include "Item.h"

int Item::getX() const 
{
	return x_;
};
int Item::getY() const 
{
	return y_;
};
void Item::setX(int x) 
{
	x_ = x;
}
void Item::setY(int y) 
{
	y_ = y;
}

Item::~Item() {};