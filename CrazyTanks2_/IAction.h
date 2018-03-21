#pragma once
#include "Tank.h"
#include "Item.h"

class IAction
{
public:
	IAction();
	virtual void Move(Tank& tank) = 0;
	virtual void Shot(Tank& tank) = 0;

	virtual ~IAction();

private:

};