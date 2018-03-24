#pragma once
#include "Tank.h"
#include "Map.h"
#include "Bullet.h"

class EnemyAction //:public iaction
{
public:
	EnemyAction();
	void Move(Tank& tank, Map& map);
	void Shot(Tank& tank, Map& map);
	~EnemyAction();
};