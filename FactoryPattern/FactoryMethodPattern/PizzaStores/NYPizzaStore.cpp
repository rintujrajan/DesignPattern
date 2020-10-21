#include <iostream>

#include "NYPizzaStore.h"
#include "../Pizzas/NYPepperoniPizza.h"
#include "../Pizzas/NYCheesePizza.h"

PizzaBase* NYPizzaStore::createPizza(std::string type)
{
	std::cout << type+" pizza ordered at NY Pizza Store\n";
	if (type == "Cheese")
	{
		return new NYCheesePizza();
	}
	else if (type == "Pepperoni")
	{
		return new NYPepperoniPizza();
	}
	else
	{
		std::cout << "Ordered pizza unavailable!\n";
		return NULL;
	}

}
