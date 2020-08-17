#pragma once
#include <string>
class DoughBase;
class SauceBase;
class CheeseBase;

/*
    The abstract PizzaIngredientFactory is the interface that defines how to make a family of related products,
    everything we need to make a pizza
*/
class PizzaIngredientFactory
{
    public:
        virtual DoughBase* createDough() = 0;
        virtual SauceBase* createSauce() = 0;
        virtual CheeseBase* createCheese() = 0;
        virtual std::string getName() = 0;
};