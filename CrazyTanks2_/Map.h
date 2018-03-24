#ifndef MAP
#define MAP
#include <iostream>
#include "Wall.h"
#include "Gold.h"
#include "Tank.h"
#include<vector>
#include <conio.h>

const int n = 30;
const int m = 80;
using namespace std;
class Map
{
public:
	Map(vector<Tank>& enemytanks, Tank& playerTank);
	~Map();
	//private:
	Item map[n][m];
};

#endif
