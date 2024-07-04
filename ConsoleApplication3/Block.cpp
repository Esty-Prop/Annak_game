#include "Block.h"
#include "JsonHandler.h"
#include "Command.h"

using namespace std;

Block::Block()
{
}

Block::~Block()
{
}

Block::Block(TypesBlock typesBlock)
{
    
    this->type = typesBlock;
    
    //Read fron json config
    JsonHandler jsonHandler("config.json");
    json config = jsonHandler.read();
    //Set resources 
    resourcesType = new string[Command::N_RESOURCES];
    resources = new double[Command::N_RESOURCES] {0};

    if (config.contains("ResourceTypes") && config["ResourceTypes"].is_array()) {
        for (int i = 0; i < Command::N_RESOURCES; i++) {
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

void Block::addPerson(shared_ptr<Person> person)
{
    people.emplace_back(person);
}

void Block::workPeple(int time)
{

}



string Block::getBlockType()
{
    switch (type) {
            case TILE: return "Tile";
            case CITY: return "City";
            case VILLAGE: return "Village";
            case ROAD: return "Road";
            default: return "Unknown";
            }
}

void Block::increaseResources(double amount, int typeResource)
{
    resources[typeResource] += amount;
}

void Block::reduceResources(double amount, int typeResource)
{

    if (resources[typeResource] - amount > 0) {
        resources[typeResource] -= amount;
    }
    
    else
        resources[typeResource] = 0;

}

void Block::increaseResources(double amount, string typeResource)
{
    for (int i = 0; i < Command::N_RESOURCES; ++i) {
        if (resourcesType[i] == typeResource) {
            resources[i] += amount;
            return;
        }
    }
}

void Block::reduceResources(double amount, string typeResource)
{

    for (int i = 0; i < Command::N_RESOURCES; ++i) {
        if (resourcesType[i] == typeResource) {
            resources[i] -= amount;
            return;
        }
    }
}
