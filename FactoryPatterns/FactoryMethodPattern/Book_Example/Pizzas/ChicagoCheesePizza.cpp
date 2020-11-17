#include "ChicagoCheesePizza.h"
#include <iostream>

ChicagoCheesePizza::ChicagoCheesePizza()
{
	std::cout << "Setting Chicago Cheese Pizza Ingredients..\n";
	pizzaName = "Chicago style Cheese";
	dough = "Thick Crust Dough";
	sauce = "Chunky Tomato Sauce";
	vecToppings.push_back("Double Shredded Mozzarella Cheese");
	vecToppings.push_back("Farm fresh Pepperoni");
}
void ChicagoCheesePizza::bake()
{
	std::cout << "Baking different from base Pizza template. Baking pizza for 15 mins at 400!\n";
}

void ChicagoCheesePizza::cut()
{
	std::cout << "Cutting different from base Pizza template. Cutting pizza into square sizes!\n";
}