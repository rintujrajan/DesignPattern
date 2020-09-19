#pragma once
#include "IIterator.h"
#include "../Menus/DinerMenu.h"

class MenuItems;
class DinerMenuIterator : public IIterator 
{
private:
    MenuItem *pMenuItems[MAX_MENU_ITEMS];
    int pIteratorPosition;
    int pNumberOfItems;
public:
    DinerMenuIterator(MenuItem *menuItems[], int numberOfItems);
    bool hasNext();
    MenuItem* next();
};

