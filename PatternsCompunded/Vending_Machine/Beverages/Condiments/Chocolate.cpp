#include "Chocolate.h"

Chocolate::Chocolate(IBeverage* beverage)
{
    baseBeverage = beverage;
}

Chocolate::~Chocolate()
{
    delete baseBeverage;
}

float Chocolate::cost()
{
    return 15.25 + baseBeverage->cost();
}