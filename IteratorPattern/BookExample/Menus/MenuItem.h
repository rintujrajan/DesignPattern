#pragma once
#include <string>
#include <ostream>

class MenuItem
{
private:
    std::string pName;
    std::string pDescription;
    bool pVegetarian;
    double pPrice;
public:
    MenuItem(std::string name, std::string description, bool vegetarian, double price);
    inline std::string GetName(){ return pName;}
    inline std::string GetDescription(){ return pDescription;}
    inline bool IsVegetarian(){ return pVegetarian;}
    inline double GetPrice(){ return pPrice;}
    friend std::ostream& operator<<(std::ostream& out,MenuItem* menuItem);
};
