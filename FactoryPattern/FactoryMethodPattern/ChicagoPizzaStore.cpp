#include <iostream>

#include "ChicagoPizzaStore.h"
#include "ChicagoPepperoniPizza.h"
#include "ChicagoCheezePizza.h"

PizzaBase* ChicagoPizzaStore::createPizza(std::string type)
{
	std::cout << type+" pizza ordered at Chicago Pizza Store\n";
	if (type == "Cheeze")
	{
		return new ChicagoCheezePizza();
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
