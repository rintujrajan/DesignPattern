#include <iostream>

#include "NYPizzaStore.h"
#include "PepperoniPizza.h"
#include "CheesePizza.h"
#include "NYPizzaIngredientFactory.h"

PizzaBase* NYPizzaStore::createPizza(std::string type)
{
	std::cout << type+" pizza ordered at NY Pizza Store\n";
	PizzaIngredientFactory* factory = new NYPizzaIngredientFactory;
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
	delete factory;
}
