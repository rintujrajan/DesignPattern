#include <iostream>

#include "NYPizzaStore.h"
#include "NYPepperoniPizza.h"
#include "NYCheezePizza.h"

PizzaBase* NYPizzaStore::createPizza(std::string type)
{
	std::cout << type+" pizza ordered at NY Pizza Store\n";
	if (type == "Cheeze")
	{
		return new NYCheezePizza();
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
