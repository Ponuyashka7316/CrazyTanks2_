#ifndef BLT
#define BLT

#include "Item.h"
#include "direction.h"
class Bullet :public Item
{
public:
	Bullet(direction d, int x, int y, char val = 'o')
	{
		value = val;
		dir = d;
		setX(x);
		setY(y);
	};
	~Bullet();
	
	
private:
	
	//direction dir;
};

//Bullet::Bullet(direction d, int x, int y, char val = 'o')
//{
//	value = val;
//	dir = d;
//	setX(x);
//	setY(y);
//};

#endif