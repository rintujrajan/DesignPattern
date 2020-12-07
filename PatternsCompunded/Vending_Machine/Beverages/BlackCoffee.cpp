#include "BlackCoffee.h"

BlackCoffee::BlackCoffee(BeverageSize selBeverageSize)
        :beverageSize(selBeverageSize)
{
}

float BlackCoffee::cost()
{
    float cost = 0;
    switch (beverageSize)
    {
    case IBeverage::BeverageSize::SMALL:
        cost = 39.99;
        break;
    case IBeverage::BeverageSize::MEDIUM:
        cost = 64.99;
        break;
    case IBeverage::BeverageSize::LARGE:
        cost = 89.99;
        break;        
    }
    return cost;
}
