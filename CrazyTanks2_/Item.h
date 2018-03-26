#ifndef ITEM
#define ITEM

#include "Item.h"
#include "direction.h"

class Item
{
private:
	int x_;
	int y_;
public:
	direction dir = direction::STOP;
	char value = 'o';
	Item() { value = ' '; };
	~Item();
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
};
#endif
