#pragma once
#include <string>
using namespace std;
class Obj
{
protected:
    enum TypesObj { PERSON = 0, CAR, TRUCK, HELICOPTER };
    TypesObj type;
public:
    Obj();
    Obj(TypesObj typesObj);
    string getBlockType();
    
};
