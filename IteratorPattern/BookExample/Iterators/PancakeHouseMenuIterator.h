#pragma once
#include "IIterator.h"
#include "../Menus/PancakeHouseMenu.h"

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

