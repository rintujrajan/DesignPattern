#pragma once
#include "MenuComponent.h"
class MenuItem : public MenuComponent
{
private:
    std::string pName;
    std::string pDescription;
    bool pVegetarian;
    double pPrice;
public:
    MenuItem(std::string name, std::string description, bool vegetarian, double price);
    inline std::string GetName() const override{ return pName;}
    inline std::string GetDescription() override{ return pDescription;}
    inline bool IsVegetarian() override{ return pVegetarian;}
    inline double GetPrice() override{ return pPrice;}
    void print() override;   
    inline bool hasChildMenu() override { return false;}
    IIterator* createIterator() override;
};

