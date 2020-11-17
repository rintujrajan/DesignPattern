#pragma once

#include "PizzaBase.h"

class PizzaIngredientFactory;
class CheesePizza :
	public PizzaBase
{
	private:
		virtual void prepare();
		virtual void bake();
		PizzaIngredientFactory* localFactory;
	public:
		CheesePizza(PizzaIngredientFactory* factory);
		~CheesePizza();

};

