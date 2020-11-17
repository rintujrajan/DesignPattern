#include "ChicagoPizzaIngredientFactory.h"
#include "Ingredients\Dough\ThickCrustDough.h"
#include "Ingredients\Cheese\MozzarellaCheese.h"
#include "Ingredients\Sauce\PlumTomatoSauce.h"
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