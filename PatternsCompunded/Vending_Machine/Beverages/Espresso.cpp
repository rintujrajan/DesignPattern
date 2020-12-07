#include "Espresso.h"

Espresso::Espresso(BeverageSize selBeverageSize)
        :beverageSize(selBeverageSize)
{
}

float Espresso::cost()
{
    float cost = 0;
    switch (beverageSize)
    {
    case IBeverage::BeverageSize::SMALL:
        cost = 49.99;
        break;
    case IBeverage::BeverageSize::MEDIUM:
        cost = 74.99;
        break;
    case IBeverage::BeverageSize::LARGE:
        cost = 99.99;
        break;        
    }
    return cost;
}
