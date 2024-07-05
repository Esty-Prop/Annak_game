#include "World.h"
#include <iostream>
#include "json.hpp"
#include <string>
#include <fstream>
#include <vector>
#include "JsonHandler.h"

#define BUFFER 1
using namespace std;
using json = nlohmann::json;

World::World(vector<int> typeTiles, int sizeX, int sizeY) {

    this->sizeX = sizeX;
    this->sizeY = sizeY;

    //Read fron json config
    JsonHandler jsonHandler("config.json");
    json config = jsonHandler.read();
    int width = (int)config["Sizes"]["Tile"][0];
    int height = (int)config["Sizes"]["Tile"][1];
    //Initalize grid wolrld
    grid = new Cell * [sizeY * height];
    for (int i = 0; i < sizeY * height; i++)
    {
        grid[i] = new Cell[sizeX * width];
    }
    //Initalize Tiles
    for (auto tile : typeTiles)
    {
        shared_ptr<Block> ptr(new Tile(tile));
        blocks.emplace_back(ptr);
    }

    int blockIndex = 0;

    for (int i = 0; i < sizeY; ++i) {
        for (int j = 0; j < sizeX; ++j) {
            for (int tileY = 0; tileY < height; ++tileY) {
                for (int tileX = 0; tileX < width; ++tileX) {
                    int worldGridX = j * width + tileX;
                    int worldGridY = i * height + tileY;
                    if (worldGridX < (sizeX * width) && worldGridY < sizeY * height) {
                        grid[worldGridY][worldGridX].setBlock(blocks[blockIndex]);
                    }
                }
            }
            ++blockIndex;
        }
    }

    if (config.contains("Tiles")) {

        for (auto& tile : config["Tiles"].items()) {
            tileTypeMap[tile.value()] = tile.key();
        }

    }
    else {
        throw runtime_error("Missing 'Tiles' in the configuration file.");
    }

}
World::~World()
{
    for (int i = 0; i < sizeY * 5; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}



string World::getTileType( Cell& cell)
{
    auto a = dynamic_cast<Tile*> (cell.getBlock().get());
    return a->getTypeTile();
}

Tile* World::selectTile(int locationX, int locationY)
{
    return dynamic_cast<Tile*> (grid[locationY][locationX].getBlock().get());
}
Block* World::selectBlock(int locationX, int locationY)
{
    return grid[locationY][locationX].getBlock().get();
}

void World::addPerson(int locationX, int locationY)
{
    locationX -= BUFFER;
    locationY -= BUFFER;
    shared_ptr<Person> personPtr(new Person());
    grid[locationY][locationX].setGround(personPtr);
    Block * currentBlock = selectBlock(locationX, locationY);
    currentBlock->addPerson(personPtr);

}

Cell& World::selectCell(int locationX, int locationY) {
    locationX -= BUFFER;
    locationY -= BUFFER;

    return (grid[locationY][locationX]);
}

void World::rain(int rainAmount)
{
    for (auto block : blocks) {
        //if (block.get()->type == 'TILE') {
            Tile* tile=dynamic_cast<Tile*>(block.get());
            if (tile->typeTile == 3 && rainAmount>=2000) {
                tile->increaseResources(1, 0);
            }
            else if (tile->typeTile == 4 && rainAmount >= 1000) {
                tile->increaseResources(1, 1);
            }
        //}
    }
}





//vector<vector<Tile>>  World :: print(){
//   
//   return mat;
//}
//vector<int>World :: printVector(){
//    return typeTiles;
//}
//string World :: getCategory(int i, int j){
//    int location= mat[j-1][i-1].type;
//    return tileTypeMap[location];
//    
//}
