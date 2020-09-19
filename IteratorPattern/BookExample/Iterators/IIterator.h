#pragma once
#include "../Menus/MenuItem.h"

class IIterator
{
public:
    virtual bool hasNext() = 0;
    virtual MenuItem* next() = 0;
};

