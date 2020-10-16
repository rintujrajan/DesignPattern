#pragma once
#include <string>

class IIterator;
/*
    Having a common interface for the aggregates is handy for the client;
    it decouples the client from the implementation of the collection of objects
*/
class IMenu
{
public:
    virtual void addItem(std::string name, std::string description,bool vegetarian, double price) = 0;
    virtual IIterator* createIterator() = 0;
};
