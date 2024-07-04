#pragma once
#include <iostream>
#include "json.hpp"
#include <string>
#include <fstream>
#include <vector>
#include "Block.h"

using namespace std;
class Tile :
    public Block {
public:
    int typeTile;
    unordered_map<int, string> tileTypeMap;
    int resourceIndex;

    Tile(int base = 1);
    string getTypeTile();
    ~Tile();


};