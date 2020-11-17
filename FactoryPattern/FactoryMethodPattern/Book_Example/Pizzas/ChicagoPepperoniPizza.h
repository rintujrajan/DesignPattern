#pragma once

#include "PizzaBase.h"

class ChicagoPepperoniPizza :
	public PizzaBase
{
	private:
		void bake();
		void cut();
	public:
		ChicagoPepperoniPizza();
};

