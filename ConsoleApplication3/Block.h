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
private:
   
    string typesBlock;
    double* resources;
    string* resourcesType;
    int width, height;
public:
    enum TypesBlock { Tile=0, City, Village, Road };

    Block();
    virtual ~Block();
    Block(string typesBlock);
    virtual  string getBlockType();
    virtual  void increaseResources(double amount, string typeResource);
    virtual  void reduceResources(double amount, string typeResource);
    virtual  double* getResourses();

    


};


