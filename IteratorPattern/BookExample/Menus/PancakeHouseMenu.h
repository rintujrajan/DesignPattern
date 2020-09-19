#pragma once
#include "IMenu.h"
#include <vector>

class MenuItem;

class PancakeHouseMenu : public IMenu
{
private:
    std::vector<MenuItem*> menuItems;
public:
    PancakeHouseMenu();
    ~PancakeHouseMenu();
    void addItem(std::string name, std::string description,bool vegetarian, double price);
    IIterator* createIterator();
};
