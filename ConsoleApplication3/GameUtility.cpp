#include "GameUtility.h"
#include "JsonHandler.h"
#include "json.hpp"
#include "World.h"

#define WORK_REDUCE 0.5
using json = nlohmann::json;

 void GameUtility::work(Cell& cell)
{
	auto tile = dynamic_cast<Tile*> (cell.getBlock().get());
	tile->reduceResources(WORK_REDUCE,tile->resourceIndex);
}

 void GameUtility::rain(int amountRain, World* world)
 {

	 world->rain(amountRain);
 }
 //int GameUtility::amountRainWood = 0;
 //int GameUtility::amountRainWool = 0;