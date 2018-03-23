//#pragma once
//#include "Map.h"
//
//using namespace std;
//class UI {
//	
//	void preRender(Map* map) {
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				cout << map->map[i][j].value;
//			}
//			cout << endl;
//		}
//	}
//
//	void render(Map* map) {
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				cout << map->map[i][j].value;
//			}
//			cout << endl;
//		}
//	}
//
//	bool ShowConsoleCursor(bool bShow)
//	{
//		CONSOLE_CURSOR_INFO cci;
//		HANDLE hStdOut;
//		hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//		if (hStdOut == INVALID_HANDLE_VALUE)
//			return FALSE;
//		if (!GetConsoleCursorInfo(hStdOut, &cci))
//			return FALSE;
//		cci.bVisible = bShow;
//		if (!SetConsoleCursorInfo(hStdOut, &cci))
//			return FALSE;
//		return TRUE;
//	}
//};