#pragma once
#include "../Menus/MenuItem.h"

/*
    The Iterator interface provides the interface that all iterators must implement,
    and a set of methods for traversing over elements of a collection.
*/

class IIterator
{
public:
    virtual bool hasNext() = 0;
    virtual MenuItem* next() = 0;
};

