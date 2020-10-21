#include <iostream>
#include "PizzaStores\NYPizzaStore.h"
#include "PizzaStores\ChicagoPizzaStore.h"
/*
	The difference between the factory method pattern example and the current example is two fold
	1. In Factory Method pattern, ingredients used in the concrete Pizza/Product classes were hard coded, 
		and hence for each PizzaStore there had to separate concrete Pizzas/Products even though they were of same type
		E.g. NYPizzaStore for Cheese Pizza has NYCheesePizza class ChicagoPizzaStore for Cheese Pizza has ChicagoCheesePizza class
		In current example each concrete Pizza/Product class has a factory which it utilizes to get the concrete products to make the pizza
	2.The PizzaStore concrete creator classes make use of corresponding Concrete Ingredient Factory
	    and pass it onto the concrete Pizza/Product constructors.

	The Factory Method used inheritance for object creation while the Abstract Factory uses composition

*/

int main()
{

	/*
		Each Pizza Store is like a client which decides which factory to use to procure ingredients.
		The NYPizzaStore creates a NY Ingredient Factory to procure NY specific ingredients. Check NYPizzaStore.cpp 
	*/
	PizzaStore* newYorkPizzaStoreInstance = new NYPizzaStore();
	newYorkPizzaStoreInstance->orderPizza("Cheese");

	std::cout<<"\n***************\n\n";

	PizzaStore* chicagoPizzaStoreInstance = new ChicagoPizzaStore();
	chicagoPizzaStoreInstance->orderPizza("Pepperoni");

	std::cin.get();

	delete newYorkPizzaStoreInstance;
	delete chicagoPizzaStoreInstance;
}
