#pragma once

#include <vector>
#include <string>

#include "DoughBase.h"
#include "SauceBase.h"
#include "CheeseBase.h"
/*
	The clients of the Abstract Factory are the concrete instances of the PizzaBase class.
*/
class PizzaBase
{
protected:
	std::string pizzaName;
	DoughBase* dough;
	SauceBase* sauce;
	CheeseBase* cheese;
public:
	// Prepare is a pure virtual function and this is used in the concrete pizza classes to get the ingredients needed from respective factories
	virtual void prepare() = 0;
	virtual void bake();
	virtual void cut();
	virtual void box();
	// Insertion operator overloaded to output PizzaBase object details
	friend std::ostream& operator <<(std::ostream& out,PizzaBase* pizzaBase);
	virtual ~PizzaBase();
};

