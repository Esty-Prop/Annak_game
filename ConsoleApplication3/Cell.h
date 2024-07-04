#pragma once


#include <string>
#include <fstream>
#include <vector>
#include <memory>
//#include "block.h"
#include "Tile.h"
#include <iostream>
#include "json.hpp"
//#include "Obj.h"
using namespace std;
class Cell
{
private:
	shared_ptr< Obj> groundPtr;
    shared_ptr< Obj> aerialPtr;
    shared_ptr<Block> blockPtr ;
public:
    Cell()  { }
   
    void setBlock(shared_ptr<Block>  block) {
        blockPtr = block;
    }
    void setGround(shared_ptr<Obj>  obj) {
        groundPtr = obj;
    }
    shared_ptr<Obj> getGround()  {
        if (groundPtr != nullptr) {
            return groundPtr;
        }
        else {
            throw std::runtime_error("Ground pointer is nullptr");
        }
    }
    shared_ptr<Block> getBlock()  {
        if (blockPtr != nullptr) {
            return blockPtr;
        }
        else{
            throw std::runtime_error("Block pointer is nullptr");
        }
    }
};

