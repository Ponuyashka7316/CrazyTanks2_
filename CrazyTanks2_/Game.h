#ifndef GAME
#define GAME

#include "Tank.h"
#include "Map.h"
#include "Bullet.h"
#include <memory>

using namespace std;

class Game
{
public:
	Game();
	~Game();
	void checkColisions(Map& map, Game& game, vector<Tank>& enemies, Tank& player);
	void createEnemies(vector<Tank>& enemyTanks, int enemyTanksCount);
	void deleteEnemy(vector<Tank>& enemies, int x, int y);
	int getScore() const;
	void increaseScore();
private:
	int score_ = 0;
};

#endif



