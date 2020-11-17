#pragma once

#include "SimplePizzaFactory.h"
#include "IPizza.h"

class PizzaStore
{
	SimplePizzaFactory simplePizzaFactory;
public:
	PizzaStore(SimplePizzaFactory simplePizzaFactory);
	IPizza* orderPizza(std::string pizzaType);
};

