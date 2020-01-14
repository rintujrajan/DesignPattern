// FactoryPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PizzaStore.h"


int main()
{
	SimplePizzaFactory pizzaFactory;

	PizzaStore aTypicalPizzaStore(pizzaFactory);

	aTypicalPizzaStore.orderPizza("Cheeze");

	aTypicalPizzaStore.orderPizza("Pepperoni");

	aTypicalPizzaStore.orderPizza("Veggie");
}
