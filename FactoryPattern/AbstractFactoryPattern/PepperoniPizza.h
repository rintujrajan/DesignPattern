#pragma once

#include "PizzaBase.h"
class PizzaIngredientFactory;
class PepperoniPizza :
	public PizzaBase
{
	virtual void prepare();
	virtual void cut();
	PizzaIngredientFactory *localFactory;

	public:
		PepperoniPizza(PizzaIngredientFactory *factory);
		~PepperoniPizza();
};



