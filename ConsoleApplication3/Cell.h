#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include "block.h"
#include "Tile.h"
#include <iostream>
#include "json.hpp"
#include "Obj.h"
using namespace std;
class Cell
{
private:
	shared_ptr< Obj> groundPtr;
    shared_ptr< Obj> aerialPtr;
    shared_ptr<Block> blockPtr = nullptr;
public:
    Cell() : blockPtr(nullptr),groundPtr(nullptr), aerialPtr(nullptr) { }
   
    void setBlock(shared_ptr<Block>  block) {
        blockPtr = block;
    }
    void setGround(shared_ptr<Obj>  obj) {
        groundPtr = obj;
    }
    shared_ptr<Obj> getGround() const {
        if (groundPtr != nullptr) {
            return groundPtr;
        }
        else {
            throw std::runtime_error("Ground pointer is nullptr");
        }
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

