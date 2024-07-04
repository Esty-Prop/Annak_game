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

 void GameUtility::rain(int amountRain)
 {
     //Read fron json config
     JsonHandler jsonHandler("config.json");
     json config = jsonHandler.read();
     int rainWood = (int)config["Rains"]["Wood"];
     int rainWool = (int)config["Rains"]["Wool"];

 }
