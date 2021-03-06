// CrazyTanks2_.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "headers.h"


using namespace std;

int main()
{
	UI ui;
	system("mode con cols=85 lines=40");
	ui.ShowConsoleCursor(false);
	char playerIcon = 'X';
	Tank playerTank(playerIcon);
	playerTank.setHealth(3);
	vector<Tank> enemyTanks;
	int enemyTanksCount = 5;
	
	Game* game = new Game();
	(*game).createEnemies(enemyTanks, enemyTanksCount);
	Map* map = new Map(enemyTanks, playerTank);
	char ch = '\0';
	TankAction pAction;
	
	ui.preRender(map);
	ui.setCur(1, 1);
	//game cycle
	while (true)
	{
		
		(*game).checkColisions(*map, *game, enemyTanks, playerTank);
		ui.setCur(1, 1);
		if (_kbhit()) {

			ch = _getch();
			if (ch == char(72) || ch == 80 || ch == 77 || ch == 75)
				pAction.Move(*map, playerTank, ch, 'X');
			else if (ch == 32) {
				pAction.Shot(*map, playerTank, 'o');

			}
		}
		if (clock() % 10 == 0)
		{
			for (auto &item : enemyTanks)
			{
				int x_ = item.getX();
				int y_ = item.getY();
				char carr[] = { 72,75,77,80 };
				char c = carr[rand() % 4];
				pAction.Move(*map, item, c, '+');
			}
		}
		if (clock() % 30 == 0)
		{
			for (auto &item : enemyTanks)
			{
				pAction.Shot(*map, item, '*');
			}
		}
		if (map->map[n - 2][m / 2 - 1].value != 'W')
			break;
		ui.render(map);
		ui.setCur(0, n + 1);
		cout <<"Current score: "<< game->getScore() << endl;
		cout << "Time spent: " <<clock() << endl;
		cout << "Health: " << playerTank.getHealth() << endl;
		ui.setCur(0, 0);
		if (playerTank.getHealth() == 0) break;
	}
	cout << "Your score: " << game->getScore();
	_getch();
	return 0;
}

