#pragma once
#include <fstream>
#include <vector>
#include <memory>
#include <iostream>
#include "json.hpp"
#include <string>
#include "Person.h"
#include "Obj.h"
using namespace std;
class Block
{
protected:
    enum TypesBlock { TILE = 0, CITY, VILLAGE, ROAD };
    TypesBlock type;

private:
    
    double* resources;
    string* resourcesType;
    vector<shared_ptr<Person>> people;
    vector<shared_ptr<Obj>> cars;
    vector<shared_ptr<Obj>> trucks;
    vector<shared_ptr<Obj>> helicopters;
   
   /* int width, height;*/
public:
    
    Block();
    virtual ~Block();
    Block(TypesBlock typesBlock);
    virtual  string getBlockType();
    virtual  void increaseResources(double amount, string typeResource);
    virtual  void reduceResources(double amount, string typeResource);
    virtual  double* getResourses();
    void addPerson(shared_ptr<Person> person);

    


};


