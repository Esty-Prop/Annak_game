#include "Obj.h"

Obj::Obj()
{
}

Obj::Obj(TypesObj typesObj)
{
    this->type = typesObj;
}

string Obj::getBlockType()
{
    switch (type) {
    case PERSON: return "Person";
    case CAR: return "Car";
    case TRUCK: return "Truck";
    case HELICOPTER: return "Helicopter";
    default: return "Unknown";
    }
}
