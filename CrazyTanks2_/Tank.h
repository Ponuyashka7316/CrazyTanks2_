#pragma once

#include "direction.h"
#include "Item.h"
#include "IAction.h"
struct Tank:Item
{
public:
	void setHealth(int value) {
		if (value >= 0 && value < 1000)
			this->health = value;
		else
			this->health = 1;
	}
	int health = 0;
	direction dir = direction::UP;
	Tank() { value = '+'; };
	~Tank();
	Tank(char ch) { value = ch; }
private:

};