#include "ChicagoPizzaIngredientFactory.h"
#include "ThickCrustDough.h"
#include "MozzarellaCheese.h"
#include "PlumTomatoSauce.h"
#include <iostream>

ChicagoPizzaIngredientFactory::ChicagoPizzaIngredientFactory()
{
    std::cout<<"Sourcing ingredients from Chicago factory\n";
}
DoughBase* ChicagoPizzaIngredientFactory::createDough()
{
    return new ThickCrustDough();
}
SauceBase* ChicagoPizzaIngredientFactory::createSauce()
{
    return new PlumTomatoSauce();
}
CheeseBase* ChicagoPizzaIngredientFactory::createCheese()
{
    return new MozzarellaCheese();
}

std::string ChicagoPizzaIngredientFactory::getName()
{
    return "Chicago factory";
}