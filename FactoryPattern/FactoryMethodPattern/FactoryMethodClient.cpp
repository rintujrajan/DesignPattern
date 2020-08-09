#include "NYPizzaStore.h"
#include "ChicagoPizzaStore.h"
#include <iostream>

/*
	All factory patterns encapsulate object creation. 
	The Factory Method Pattern encapsulates object creation by letting subclasses decide what objects to create.

	The Factory method pattern has a factory method as its corner stone.
	
	Creator classes:
	There is an abstract creator class which contains an abstract factory method which is to be implemented
	by concrete creator classes to create concrete products(objects).
		In our current example:
		Abstract Creator - PizzaStore
		Concrete Creators - NYPizzaStore, ChicagoPizzaStore
		Abstract Factory Method - createPizza

	Product classes:	
	Parallelly there would be an abstract product class and concrete product classes derived from it. 
	The abstract product class pointer is used in the abstract creator class,
	and later in concrete creator classes the concrete products/objects are created

	This pattern depends on inheritance rather than composition to create concrete products/objects 
	PizzaStore class's "createPizza" abstract factory method is implemented in the concrete creator subclasses like NYPizzaStore

	The client code in this file used the derived concrete instances to order various pizza types
	
	Check out pages 143(169) and 144(170) to see Creator classes and Product classes visualized
	 

*/

int main()
{

	PizzaStore* newYorkPizzaStoreInstance = new NYPizzaStore();
	newYorkPizzaStoreInstance->orderPizza("Cheeze");

	std::cout<<"\n***************\n\n";

	PizzaStore* chicagoPizzaStoreInstance = new ChicagoPizzaStore();
	chicagoPizzaStoreInstance->orderPizza("Pepperoni");

	std::cin.get();

	delete newYorkPizzaStoreInstance;
	delete chicagoPizzaStoreInstance;
}
