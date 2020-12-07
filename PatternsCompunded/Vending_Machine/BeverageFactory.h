#pragma once
class IBeverage;
class BeverageFactory
{
public:
    IBeverage* prepareBeverage(int coffeeType,int beverageSize);
};


