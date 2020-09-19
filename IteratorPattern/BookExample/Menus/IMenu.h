#pragma once
#include <string>

class IIterator;

class IMenu
{
public:
    virtual void addItem(std::string name, std::string description,bool vegetarian, double price) = 0;
    virtual IIterator* createIterator() = 0;
};
