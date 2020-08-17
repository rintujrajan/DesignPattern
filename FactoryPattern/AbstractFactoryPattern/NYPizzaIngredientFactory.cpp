#include "NYPizzaIngredientFactory.h"
#include "ThinCrustDough.h"
#include "MarianaSauce.h"
#include "ReggianoCheese.h"
#include <iostream>

NYPizzaIngredientFactory::NYPizzaIngredientFactory()
{
    std::cout<<"Sourcing ingredients from NY Pizza Ingredient Factory\n";
}

DoughBase* NYPizzaIngredientFactory::createDough()
{
    return new ThinCrustDough();
}

SauceBase* NYPizzaIngredientFactory::createSauce()
{
    return new MarianaSauce();
}

CheeseBase* NYPizzaIngredientFactory::createCheese()
{
    return new ReggianoCheese();
}

std::string NYPizzaIngredientFactory::getName()
{
    return "NY factory";
}