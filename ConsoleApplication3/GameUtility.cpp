#include "GameUtility.h"
#include "World.h"

#define WORK_REDUCE 0.5

 void GameUtility::work(Cell& cell)
{
	auto tile = dynamic_cast<Tile*> (cell.getBlock().get());
	tile->reduceResources(WORK_REDUCE,tile->resourceIndex);
}
