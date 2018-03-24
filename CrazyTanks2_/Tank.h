#ifndef TANK
#define TANK
#include "direction.h"
#include "Item.h"

class Tank :public Item
{
private:
	//IAction * action;
	int health = 0;
public:
	void setHealth(int value);
	int getHealth() const;
	void decreaseHealth();
	Tank();
	Tank(char ch);
	direction dir = direction::UP;
	//Tank(IAction* comp) : action(comp) {}
	~Tank();
};

#endif

