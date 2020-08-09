#include "ChicagoCheezePizza.h"
#include <iostream>

ChicagoCheezePizza::ChicagoCheezePizza()
{
	std::cout << "Setting Chicago Cheeze Pizza Ingredients..\n";
	pizzaName = "Chicago style Cheeze";
	dough = "Thick Crust Dough";
	sauce = "Chunky Tomato Sauce";
	vecToppings.push_back("Double Shredded Mozzarella Cheese");
	vecToppings.push_back("Farm fresh Pepperoni");
}
void ChicagoCheezePizza::bake()
{
	std::cout << "Baking different from base Pizza template. Baking pizza for 15 mins at 400!\n";
}

void ChicagoCheezePizza::cut()
{
	std::cout << "Cutting different from base Pizza template. Cutting pizza into square sizes!\n";
}