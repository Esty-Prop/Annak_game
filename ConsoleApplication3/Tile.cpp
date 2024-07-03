#include <iostream>
#include <string>
#include <vector>
#include "Tile.h"
#include "JsonHandler.h"
#include "Block.h"

#define N_RESOURCES 4;
using namespace std;



Tile::Tile(int typeTile) :Block(TILE) {
    /*enum TypesBlock { Tile, City, Village, Road };
    TypesBlock type;*/
    this->typeTile = typeTile;
    //Read fron json config
    JsonHandler jsonHandler("config.json");
    json config = jsonHandler.read();
    int width = (int)config["Sizes"]["Tile"][0];
    int height = (int)config["Sizes"]["Tile"][1];
    if (config.contains("Tiles")) {

        for (auto& tile : config["Tiles"].items()) {
            tileTypeMap[tile.value()] = tile.key();
        }

    }
    else {
        throw runtime_error("Missing 'Tiles' in the configuration file.");
    }
    /*Block ::Block("Tile", width, height);*/

}

string Tile::getTypeTile()
{
    return tileTypeMap[typeTile];
}
//string Tile::getTypeTile()
//{
//    return tileTypeMap[typeTile]; 
//}
//







Tile::~Tile()
{
    //if(resources != nullptr) {
    //    delete[] resources;
    //    //resources = nullptr;
    //}
    //if (resourcesType != nullptr) {
    //    delete[] resourcesType;
    //    //resources = nullptr;
    //}
}

