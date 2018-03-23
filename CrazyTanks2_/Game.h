#pragma once
#include "Tank.h"
#include "Map.h"

class Game
{
public:
	Game();
	~Game();
	int score_ = 0;
	/*void checkColisions(Map& map, Game& game, vector<Tank>& enemies, Tank& player);
	void deleteEnemy(vector<Tank>& enemies, int x, int y) {
		for (vector<Tank>::iterator i = enemies.begin(); i != enemies.end(); ++i)
		{
			if (i._Ptr->x_ == x && i._Ptr->y_ == y)
				i = enemies.erase(i);
		}
	};*/
private:

};





