#include "PizzaStore.h"
#include <iostream>

PizzaStore::PizzaStore(SimplePizzaFactory simplePizzaFactory)
{
	this->simplePizzaFactory = simplePizzaFactory;
}

IPizza* PizzaStore::orderPizza(std::string pizzaType)
{
	IPizza* pizza = NULL;

	/* 
	We could have a switch case to determine the type of pizza and create it's corrsponding objects
	However keeping it here would mean that the class would be open to further change if the pizza types change
	Hence we remove the code which is likely to change from here to the SimplePizzaFactory
	The task of creating pizza objects is delegated to the SimplePizzaFactory
	This also is aligned to the Single Responsibility of SOLID principles wherein a class would be changed for only one reason
	*/
	pizza = simplePizzaFactory.createPizza(pizzaType);

	if(pizza != NULL)
	{
		// The following piece of code is not likely to change and hence is placed here
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();
		pizza->clearOrder();
	}
	else
	{
		std::cout<<"Pizza could not be delivered!\n";		
	}
	
	return pizza;
}
