#pragma once

#include "PizzaBase.h"
class ChicagoCheesePizza :
	public PizzaBase
{
	private:
		void bake();
		void cut();
	public:
		ChicagoCheesePizza();
};

