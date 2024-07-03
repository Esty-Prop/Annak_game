#pragma once
#include <fstream>
#include <vector>
#include <memory>
#include <iostream>
#include "json.hpp"
#include <string>

using namespace std;
class Block
{
protected:
    enum TypesBlock { TILE = 0, CITY, VILLAGE, ROAD };
    TypesBlock type;

private:
    
    double* resources;
    string* resourcesType;
   /* int width, height;*/
public:
    
    Block();
    virtual ~Block();
    Block(TypesBlock typesBlock);
    virtual  string getBlockType();
    virtual  void increaseResources(double amount, string typeResource);
    virtual  void reduceResources(double amount, string typeResource);
    virtual  double* getResourses();

    


};


