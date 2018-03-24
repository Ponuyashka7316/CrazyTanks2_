#ifndef UIT
#define UIT
#include "Map.h"

struct UI {
	void preRender(Map* map);
	void render(Map* map);
	void setcur(int x, int y);		//set coursor to x y 
	bool ShowConsoleCursor(bool bShow);
};

#endif