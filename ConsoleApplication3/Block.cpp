#include "Block.h"
#include "JsonHandler.h"

#define N_RESOURCES 4;
using namespace std;

Block::Block()
{
}

Block::~Block()
{
}

Block::Block(string typesBlock)
{
    this->typesBlock = typesBlock;
   
    //Read fron json config
    JsonHandler jsonHandler("config.json");
    json config = jsonHandler.read();
  //Set resources 
     const int n = N_RESOURCES
        resourcesType = new string[n];
    resources = new double[n] {0};

    if (config.contains("ResourceTypes") && config["ResourceTypes"].is_array()) {
        for (int i = 0; i < n; i++) {
            resourcesType[i] = config["ResourceTypes"][i];
        }
    }
    else {
        throw runtime_error("Missing 'ResourceTypes' in the configuration file.");
    }
}






double* Block::getResourses()
{
    return resources;
}



string Block::getBlockType()
{
   /* switch (type) {
            case Tile: return "Tile";
            case City: return "City";
            case Village: return "Village";
            case Road: return "Road";
            default: return "Unknown";
            }*/
    return typesBlock;
}

void Block::increaseResources(double amount, string typeResource)
{
    const int n = N_RESOURCES;
    
        for (int i = 0; i < n; ++i) {
            if (resourcesType[i] == typeResource) {
                resources[i] += amount;
                return;
            }
        }
}

void Block::reduceResources(double amount, string typeResource)
{
    const int n = N_RESOURCES;
    
        for (int i = 0; i < n; ++i) {
            if (resourcesType[i] == typeResource) {
                resources[i] -= amount;
                return;
            }
        }
}
