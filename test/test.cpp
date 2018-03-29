// test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "gtest/gtest.h"
#include "../CrazyTanks2_/Game.h"

Game g;

TEST(test, myScoreTest)
{
	
	g.increaseScore();
	EXPECT_EQ(1, g.getScore());
}

TEST(test, myScoreTest)
{

	g.increaseScore();
	EXPECT_EQ(2, g.getScore());
}

int main()
{

    return 0;
}

