#include "PizzaStore.h"
#include <iostream>
#include "CheesePizza.h"

/* 
	Dependency inversion principle - Depend upon abstractions. Do not depend upon concrete classes.
   	High-level components should not depend on our low-level components; rather, they should both depend on abstractions.

	PizzaStore is a high-level component because its behavior is defined in terms of pizzas -
	It creates all the different pizza objects, prepares, bakes, cuts, and boxes them, while the pizzas it uses are low-level components.

	PizzaStore(High level component) -> PizzaBase(Abstraction) -> Concrete Pizza Classes

	The high-level component, the PizzaStore, and low-level components, the pizzas, both depend on PizzaBase, the abstraction

*/

PizzaBase* PizzaStore::orderPizza(std::string pizzaType)
{
	PizzaBase* pizza = NULL;

	/* 
	The entire comment is as of teh Factory menthod since we are using the same cocpet:

	The Factory Method Pattern defines an interface for creating an object,
	but lets subclasses decide which class to instantiate. Factory Method lets a class defer instantiation to subclasses

	Abstract Creator gives an interface with a method for creating objects, also known as the “factory method.”
	Subclasses actually implement the factory method and create products.
	Any other methods implemented in the abstract Creator are written to operate on products produced by the factory method.

	In our current code:
	The Abstract Creator - PizzaStore gives an interface with a method - "createPizza" for creating objects.
	The createPizza function is not defined in the PizzaStore class, 
	but individial concrete creator classes inheriting from PizzaStore have to implement it
	And these individual concrete creator classes would create concrete products(Pizzas in our case)
	*/

	pizza = createPizza(pizzaType);
	if(pizza != NULL)
	{
		// The following piece of code is not likely to change and hence is placed here
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();
		// The insertion opearor for PizzaBase is overloaded to output pizza details
		std::cout<<pizza;
	}
	else
	{
		std::cout<<"Pizza could not be delieverd!\n";		
	}
	
	return pizza;
}
