#pragma once
#include "IPizza.h"
#include <string>
class SimplePizzaFactory
{
public:
	IPizza* createPizza(std::string type);
};

