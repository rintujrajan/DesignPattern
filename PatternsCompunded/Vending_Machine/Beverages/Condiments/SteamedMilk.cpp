#include "SteamedMilk.h"

SteamedMilk::SteamedMilk(IBeverage* beverage)
{
    baseBeverage = beverage;
}

SteamedMilk::~SteamedMilk()
{
    delete baseBeverage;
}

float SteamedMilk::cost()
{
    return 25.75 + baseBeverage->cost();
}