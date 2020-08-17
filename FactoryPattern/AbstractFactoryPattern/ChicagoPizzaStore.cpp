#include <iostream>

#include "ChicagoPizzaStore.h"
#include "CheesePizza.h"
#include "PepperoniPizza.h"
#include "ChicagoPizzaIngredientFactory.h"

PizzaBase* ChicagoPizzaStore::createPizza(std::string type)
{
	std::cout << type+" pizza ordered at Chicago Pizza Store\n";
	PizzaIngredientFactory *factory = new ChicagoPizzaIngredientFactory();
	if (type == "Cheese")
	{
		return new CheesePizza(factory);
	}
	else if (type == "Pepperoni")
	{
		return new PepperoniPizza(factory);
	}
	else
	{
		std::cout << "Ordered pizza unavailable!\n";
		return NULL;
	}

}
