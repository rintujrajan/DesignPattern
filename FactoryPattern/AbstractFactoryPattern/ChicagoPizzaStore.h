#pragma once
#include "PizzaStore.h"
class ChicagoPizzaStore :
	public PizzaStore
{
	PizzaBase* createPizza(std::string pizzaType);
};

