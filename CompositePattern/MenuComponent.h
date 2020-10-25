#pragma once
#include <string>
// #include "Iterators/IIterator.h"
class IIterator;
class MenuComponent
{
public:
    virtual std::string GetName() const;
    virtual std::string GetDescription();
    virtual bool IsVegetarian();
    virtual double GetPrice();
    virtual void print();
    virtual void add(MenuComponent* component, bool hasChildMenu = false);
    virtual void remove(MenuComponent* component);
    virtual MenuComponent* getChild(int i);
    virtual bool hasChildMenu(); 
    virtual IIterator* createIterator();
    virtual size_t size();
    void printDashLine();
};

