#pragma once
#include <string>

class PizzaBase;
class PizzaStore
{
	// Pure virtual function which makes the PizzaStore class abstract
	// This is the factory method which has to be implemented by concrete creator classes
	virtual PizzaBase* createPizza(std::string pizzaType) = 0;
public:
	PizzaBase* orderPizza(std::string pizzaType);
};

