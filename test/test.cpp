// test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "gtest/gtest.h"
#include "../CrazyTanks2_/Game.h"



TEST(test, myScoreTest)
{
	Game g;
	g.increaseScore()
	EXPECT_EQ(1, g.getScore());
}

int main()
{

    return 0;
}

