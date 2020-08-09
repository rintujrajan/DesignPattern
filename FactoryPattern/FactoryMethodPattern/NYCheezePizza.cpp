#include "NYCheezePizza.h"
#include <iostream>

NYCheezePizza::NYCheezePizza()
{
	std::cout << "Setting NY Cheeze Pizza Ingredients..\n";
	pizzaName = "NY style Cheeze";
	dough = "Thin Crust Dough";
	sauce = "Marinara Sauce";
	vecToppings.push_back("Double Grated Reggiano Cheese");
	vecToppings.push_back("Farm fresh mushrooms");
}