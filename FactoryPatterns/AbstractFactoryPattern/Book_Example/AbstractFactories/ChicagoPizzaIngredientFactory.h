#include "PizzaIngredientFactory.h"
/*
    The job of the concrete pizza factories is to make pizza ingredients.
    Each factory knows how to create the right objects for their region.
    Each factory produces a different implementation for the family of products
*/
class ChicagoPizzaIngredientFactory: public PizzaIngredientFactory
{
    virtual DoughBase* createDough();
    virtual SauceBase* createSauce();
    virtual CheeseBase* createCheese();
public:
    ChicagoPizzaIngredientFactory();
    virtual std::string getName();
};


