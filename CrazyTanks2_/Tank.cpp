#include "stdafx.h"
#include "Tank.h"

void Tank::setHealth(int value) 
{
	if (value >= 0 && value < 1000)
		this->health = value;
	else
		this->health = 1;
}
int Tank::getHealth() const 
{
	return health;
}
void Tank::decreaseHealth()
{
	health--;
}
Tank::Tank() 
{ 
	value = '+'; 
};

Tank::Tank(char ch)
{ 
	value = ch;
}

Tank::~Tank()
{
};