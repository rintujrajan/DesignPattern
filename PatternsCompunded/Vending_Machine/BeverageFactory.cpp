#include "BeverageFactory.h"
#include "Beverages/BlackCoffee.h"
#include "Beverages/Espresso.h"
#include "Beverages/Condiments/SteamedMilk.h"
#include "Beverages/Condiments/Whip.h"
#include "Beverages/Condiments/Chocolate.h"

IBeverage* BeverageFactory::prepareBeverage(int coffeeType,int beverageSize)
{
    IBeverage* selectedBeverage = nullptr;
    IBeverage::BeverageSize selectedBeverageSize;
    switch (beverageSize)
    {
    case 1:
        selectedBeverageSize = IBeverage::BeverageSize::SMALL;
        break;
    case 2:
        selectedBeverageSize = IBeverage::BeverageSize::MEDIUM;
        break;
    case 3:
        selectedBeverageSize = IBeverage::BeverageSize::LARGE;
        break;
    default:
        selectedBeverageSize = IBeverage::BeverageSize::MEDIUM;
        break;
    }
    switch (coffeeType)
    {
    case 1:
        selectedBeverage = new BlackCoffee(selectedBeverageSize);
        break;
    case 2:
        selectedBeverage = new SteamedMilk(new BlackCoffee(selectedBeverageSize));
        break;
    case 3:
        selectedBeverage = new Espresso(selectedBeverageSize);
        break;
    case 4:
        selectedBeverage = new SteamedMilk(new Espresso(selectedBeverageSize));
        break;
    case 5:
        selectedBeverage = new Whip(new SteamedMilk(new Espresso(selectedBeverageSize)));
        break;
    case 6:
        selectedBeverage = new SteamedMilk(new Chocolate(new Espresso(selectedBeverageSize)));
        break;        
    } 
    return selectedBeverage;
}