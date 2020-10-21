#pragma once
#include "PizzaStore.h"
class NYPizzaStore :
	public PizzaStore
{
	PizzaBase* createPizza(std::string pizzaType);
};

