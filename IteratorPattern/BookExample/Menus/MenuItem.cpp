#include "MenuItem.h"
#include <iomanip>

MenuItem::MenuItem(std::string name,std::string description
                    ,bool vegetarian,double price)
{
    pName = name;
    pDescription = description;
    pVegetarian = vegetarian;
    pPrice = price;
}

std::ostream& operator<<(std::ostream& out,MenuItem* menuItem)
{
    std::string veg = menuItem->pVegetarian?"Veg":"Non-Veg";
    out<<std::left;
    out << std::setw(30) << menuItem->pName
        << std::setw(70) << menuItem->pDescription
        << std::setw(10) << menuItem->pPrice
        << std::setw(5) <<  veg <<"\n";
    return out;
}