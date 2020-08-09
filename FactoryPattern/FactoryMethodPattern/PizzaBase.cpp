#include "PizzaBase.h"
#include <iostream>

void PizzaBase::prepare()
{
	std::cout << "Preparing "<< pizzaName 
			<< " Pizza having: \n"
			<< "\t"<< dough<<"\n"
			<< "\t"<< sauce << "\n"
			<< "\tTopping(s) of:\n";
	for (auto &&toping : vecToppings)
	{
		std::cout << "\t\t" << toping<<"\n";
	}
	std::cout <<std::endl;
}
void PizzaBase::bake()
{
	std::cout << "Baking pizza for 25 mins at 350!\n";
}

void PizzaBase::cut()
{
	std::cout << "Cutting pizza into diagonal sizes!\n";
}

void PizzaBase::box()
{
	std::cout << "Boxing pizza in official Pizza Store box!\n";
}