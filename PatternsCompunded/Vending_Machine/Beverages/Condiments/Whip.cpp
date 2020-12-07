#include "Whip.h"

Whip::Whip(IBeverage* beverage)
{
    baseBeverage = beverage;
}

Whip::~Whip()
{
    delete baseBeverage;
}

float Whip::cost()
{
    return 5.25 + baseBeverage->cost();
}