// test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "gtest/gtest.h"
#include "../CrazyTanks2_/Game.h"



TEST(test, myScoreTest)
{
	Game g;
	EXPECT_EQ(1, g);
}

int main()
{

    return 0;
}

