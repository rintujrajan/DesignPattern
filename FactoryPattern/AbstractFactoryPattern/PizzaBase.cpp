#include "PizzaBase.h"
#include <iostream>

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

std::ostream& operator <<(std::ostream& out,PizzaBase* pizzaBase)
{
	out<< "Created Pizza details:\n"
			<< "\tName: "<<pizzaBase->pizzaName<<"\n"
			<< "\tDough: "<<pizzaBase->dough->getName()<<"\n"
			<< "\tSauce: "<<pizzaBase->sauce->getName()<<"\n"
			<< "\tCheese: "<<pizzaBase->cheese->getName()<<"\n";
	return out;
}

PizzaBase::~PizzaBase()
{
	delete dough;
	delete sauce;
	delete cheese;
}