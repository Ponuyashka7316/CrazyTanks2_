#include "stdafx.h"
#include <iostream>
#include "Wall.h"
#include "Gold.h"
#include "Tank.h"
#include <conio.h>
#include "Map.h"
#include <time.h>

Map::Map(vector<Tank>& enemytanks, Tank& playerTank)
{
	srand(time(NULL));


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
				map[i][j] = Wall();

			if (i == n - 2 && j == m / 2 - 2)
				map[i][j] = Wall();
			if (i == n - 3 && j == m / 2 - 1)
				map[i][j] = Wall();
			if (i == n - 3 && j == m / 2 - 2)
				map[i][j] = Wall();
			if (i == n - 3 && j == m / 2)
				map[i][j] = Wall();
			if (i == n - 2 && j == m / 2)
				map[i][j] = Wall();
			if (i == n - 2 && j == m / 2 - 1)
				map[i][j] = Gold();
			if (i < n - 5 && rand() % 10 == 1)
				map[i][j] = Wall();
		}
	}

	map[n - 2][m / 2 + 2] = playerTank;
	playerTank.x_ = n - 2;
	playerTank.y_ = m / 2 + 2;

	int x;
	int y;
	for (auto &tank : enemytanks)
	{

		while (true)
		{
			x = rand() % n;
			y = rand() % m;
			if (map[x][y].value == ' ')
			{
				map[x][y] = Tank();
				tank.x_ = x;
				tank.y_ = y;
				break;
			}
		}

	}
}