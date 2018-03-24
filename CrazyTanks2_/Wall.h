#pragma once
#include "Item.h"

class Wall :public Item
{
public:
	Wall() { value = char(219); }
	~Wall();

private:
	//char value = char(219);
};




