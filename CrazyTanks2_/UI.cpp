#include "stdafx.h"
#include "UI.h"
#include "windows.h"

void UI::preRender(Map* map) 
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map->map[i][j].value;
		}
		cout << endl;
	}
}

void UI::render(Map* map) 
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map->map[i][j].value;
		}
		cout << endl;
	}
}


void UI::setcur(int x, int y)		//set coursor to x y 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};
bool UI::ShowConsoleCursor(bool bShow)
{
	CONSOLE_CURSOR_INFO cci;
	HANDLE hStdOut;
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE)
		return FALSE;
	if (!GetConsoleCursorInfo(hStdOut, &cci))
		return FALSE;
	cci.bVisible = bShow;
	if (!SetConsoleCursorInfo(hStdOut, &cci))
		return FALSE;
	return TRUE;
}