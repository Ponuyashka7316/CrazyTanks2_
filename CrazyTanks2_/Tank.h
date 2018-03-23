#pragma once
//
#include "direction.h"
#include "Item.h"
class Tank :public Item
{
private:
	//IAction * action;
public:
	int x_;
	int y_;
	void setHealth(int value) {
		if (value >= 0 && value < 1000)
			this->health = value;
		else
			this->health = 1;
	}
	int health = 0;
	direction dir = direction::UP;
	Tank() { value = '+'; };

	Tank(char ch) { value = ch; }
	//Tank(IAction* comp) : action(comp) {}
	~Tank() {   }



};

