#include "World.h"
#include <iostream>
#include "json.hpp"
#include <string>
#include <fstream>
#include <vector>
#include "JsonHandler.h"

#define BUFFER 1;
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
    worldGrid = new Cell * [10];

    for (int i = 0; i < 10; i++)
    {
        worldGrid[i] = new Cell[15];
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
            for (int tileY = 0; tileY < 5; ++tileY) {
                for (int tileX = 0; tileX < 5; ++tileX) {
                    int worldGridX = j * 5 + tileX;
                    int worldGridY = i * 5 + tileY;
                    if (worldGridX < (sizeX * 5) && worldGridY < sizeY * 5) {
                        worldGrid[worldGridY][worldGridX].setBlock(blocks[blockIndex]);
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
        delete[] worldGrid[i];
    }
    delete[] worldGrid;
}

string World::getTileType(int locationX, int locationY)
{
    locationX -= BUFFER;
    locationY -= BUFFER;
    auto a = dynamic_cast<Tile*> (worldGrid[locationY][locationX].getBlock().get());
    return a->getTypeTile();
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
