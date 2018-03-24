#ifndef PA
#define PA
#include "Map.h"
#include "Bullet.h"
class PlayerAction //:public IAction
{
public:
	PlayerAction() ;
	void Move(Map& map, Tank& tank, char ch);
	static void Shot(Map& map, Tank& tank);
	~PlayerAction() ;
private:

};

#endif