#include "NYCheesePizza.h"
#include <iostream>

NYCheesePizza::NYCheesePizza()
{
	std::cout << "Setting NY Cheese Pizza Ingredients..\n";
	pizzaName = "NY style Cheese";
	dough = "Thin Crust Dough";
	sauce = "Marinara Sauce";
	vecToppings.push_back("Double Grated Reggiano Cheese");
	vecToppings.push_back("Farm fresh mushrooms");
}