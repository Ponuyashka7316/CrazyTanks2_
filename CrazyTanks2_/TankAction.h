#ifndef PA
#define PA
#include "Map.h"
#include "Bullet.h"
class TankAction //:public IAction
{
public:
	TankAction() ;
	void Move(Map& map, Tank& tank, char ch, char val);
	static void Shot(Map& map, Tank& tank, char val);
	~TankAction() ;
private:

};

#endif