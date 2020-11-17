#include <iostream>

#include "ChicagoPizzaStore.h"
#include "..\Pizzas\CheesePizza.h"
#include "..\Pizzas\PepperoniPizza.h"
#include "..\AbstractFactories\ChicagoPizzaIngredientFactory.h"

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
