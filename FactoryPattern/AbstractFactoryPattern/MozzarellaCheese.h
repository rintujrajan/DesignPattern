#pragma once

#include "CheeseBase.h"
class MozzarellaCheese: public CheeseBase
{
private:
    virtual std::string getName();
public:
    MozzarellaCheese();
};