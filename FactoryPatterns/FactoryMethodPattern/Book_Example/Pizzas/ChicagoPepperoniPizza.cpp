#include "ChicagoPepperoniPizza.h"
#include <iostream>

ChicagoPepperoniPizza::ChicagoPepperoniPizza()
{
	std::cout << "Setting Chicago Pepperoni Pizza Ingredients..\n";
	pizzaName = "Chicago style Pepperoni";
	dough = "Thick Crust Dough";
	sauce = "Chunky Tomato Sauce";
	vecToppings.push_back("Paprika");
	vecToppings.push_back("Shredded Mozzarella Cheese");
	vecToppings.push_back("Bacon");
}
void ChicagoPepperoniPizza::bake()
{
	std::cout << "Baking different from base Pizza template. Baking pizza for 20 mins at 400!\n";
}

void ChicagoPepperoniPizza::cut()
{
	std::cout << "Cutting different from base Pizza template. Cutting pizza into square sizes!\n";
}