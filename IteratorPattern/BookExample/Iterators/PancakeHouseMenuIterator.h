#pragma once
#include "IIterator.h"
#include "../Menus/PancakeHouseMenu.h"
/*
    The ConcreteIterator is responsible for managing the current position of the iteration.
    It is manged by pIteratorPosition in here.
*/
class MenuItems;
class PancakeHouseMenuIterator : public IIterator 
{
private:
    std::vector<MenuItem*> pMenuItems;
    int pIteratorPosition;
public:
    PancakeHouseMenuIterator(std::vector<MenuItem*> menuItems);
    bool hasNext();
    MenuItem* next();
};

