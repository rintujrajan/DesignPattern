#include "NYPepperoniPizza.h"
#include <iostream>

NYPepperoniPizza::NYPepperoniPizza()
{
	std::cout << "Setting NY Pepperoni Pizza Ingredients..\n";
	pizzaName = "NY style Pepperoni";
	dough = "Thin Crust Dough";
	sauce = "Marinara Sauce";
	vecToppings.push_back("Paprika");
	vecToppings.push_back("Grated Reggiano Cheese");
	vecToppings.push_back("Fresh Clams");
}