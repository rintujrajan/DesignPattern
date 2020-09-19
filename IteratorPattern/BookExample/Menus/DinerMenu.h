#pragma once
#include "IMenu.h"

class MenuItem;

namespace
{
    const int MAX_MENU_ITEMS = 10;
};

class DinerMenu : public IMenu
{
private:
    MenuItem *menuItems[MAX_MENU_ITEMS];
    int numberOfItems; 
public:
    DinerMenu();
    ~DinerMenu();
    void addItem(std::string name, std::string description,bool vegetarian, double price);
    IIterator* createIterator();
};
