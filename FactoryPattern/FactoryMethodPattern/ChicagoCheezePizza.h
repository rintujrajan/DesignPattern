#pragma once

#include "PizzaBase.h"
class ChicagoCheezePizza :
	public PizzaBase
{
	private:
		void bake();
		void cut();
	public:
		ChicagoCheezePizza();
};

