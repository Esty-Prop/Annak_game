#pragma once
#include <iostream>
#include "Input.h"
#include "Command.h"
#include "json.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include "Tile.h"
#include "Cell.h"
#include <vector>
#include <map>



using namespace std;
using json = nlohmann::json;
class World
{
private:
    Cell ** grid;
	vector<shared_ptr<Block>> blocks;;
	int sizeX, sizeY;
	json jsonConfig;
public:
	map<int, string> tileTypeMap;
	World(vector<int> typeTiles, int sizex, int sizeY);
	~World();
	//vector<vector<Tile>> print();
	//vector<int> printVector();
	 string getTileType( Cell& cell);
     Tile* selectTile(int locationX, int locationY);
	 void addPerson(int locationX, int locationY);
	 Block* selectBlock(int locationX, int locationY);
	 Cell& selectCell(int locationX, int locationY);


};




