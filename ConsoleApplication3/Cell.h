#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include "block.h"
#include "Tile.h"
#include <iostream>
#include "json.hpp"

using namespace std;
class Cell
{
private:
	string ground;
    shared_ptr<Block> blockPtr = nullptr;
public:
    Cell() : blockPtr(nullptr) { }
   
    void setBlock(shared_ptr<Block>  block) {
        blockPtr = block;
    }

    shared_ptr<Block> getBlock() const {
        if (blockPtr != nullptr) {
            return blockPtr;
        }
        else {
            throw std::runtime_error("Block pointer is nullptr");
        }
    }
};

