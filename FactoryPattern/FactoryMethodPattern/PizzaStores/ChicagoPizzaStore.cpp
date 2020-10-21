#include <iostream>

#include "ChicagoPizzaStore.h"
#include "../Pizzas/ChicagoPepperoniPizza.h"
#include "../Pizzas/ChicagoCheesePizza.h"

PizzaBase* ChicagoPizzaStore::createPizza(std::string type)
{
	std::cout << type+" pizza ordered at Chicago Pizza Store\n";
	if (type == "Cheese")
	{
		return new ChicagoCheesePizza();
	}
	else if (type == "Pepperoni")
	{
		return new ChicagoPepperoniPizza();
	}
	else
	{
		std::cout << "Ordered pizza unavailable!\n";
		return NULL;
	}

}
