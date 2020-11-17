#include "PepperoniPizza.h"
#include "..\AbstractFactories\PizzaIngredientFactory.h"
#include <iostream>

PepperoniPizza::PepperoniPizza(PizzaIngredientFactory *factory)
{
	localFactory = factory;
	pizzaName = "Pepperoni Pizza with ingredients from " + factory->getName();
}

void PepperoniPizza::prepare()
{
	dough =  localFactory->createDough();
	sauce = localFactory->createSauce();
	cheese = localFactory->createCheese();
}

void PepperoniPizza::cut()
{
	std::cout << "Cutting different from base Pizza template. Cutting pizza into square sizes!\n";
}

PepperoniPizza::~PepperoniPizza()
{
	delete localFactory;
}
