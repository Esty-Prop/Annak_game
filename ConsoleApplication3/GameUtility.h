#pragma once
#include "Cell.h"
#include "World.h"
class GameUtility 
{
public:
	//static int amountRainWood;
	//static int amountRainWool;
	static void work(Cell& cell);
	static void rain(int amountRain, World* world);

};

