#pragma once

#include <vector>
#include <string>

class PizzaBase
{
protected:
	std::string pizzaName;
	std::string dough;
	std::string sauce;
	std::vector<std::string> vecToppings;
public:
	virtual void prepare();
	virtual void bake();
	virtual void cut();
	virtual void box();
};

