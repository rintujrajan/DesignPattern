#include "MenuItem.h"
#include <iostream>
#include <iomanip>

MenuItem::MenuItem(std::string name,std::string description
                    ,bool vegetarian,double price)
{
    pName = name;
    pDescription = description;
    pVegetarian = vegetarian;
    pPrice = price;
}
void MenuItem::print()
{
    std::string veg = pVegetarian?"Veg":"Non-Veg";
    std::cout<<std::left;
    std::cout << std::setw(30) << pName
        << std::setw(70) << pDescription
        << std::setw(10) << pPrice
        << std::setw(5) <<  veg <<"\n";
}
IIterator* MenuItem::createIterator()
{
    return nullptr;
}