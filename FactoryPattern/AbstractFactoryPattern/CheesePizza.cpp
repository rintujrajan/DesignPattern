#include "CheesePizza.h"

#include <iostream>
#include "PizzaIngredientFactory.h"

CheesePizza::CheesePizza(PizzaIngredientFactory* factory)
{
	localFactory = factory;
	pizzaName = "Cheeze Pizza with ingredients from " + factory->getName();
}

void CheesePizza::prepare()
{
	dough = localFactory->createDough();
	sauce =  localFactory->createSauce();
	cheese = localFactory->createCheese();
}

void CheesePizza::bake()
{
	std::cout << "Baking different from base Pizza template. Baking pizza for 15 mins at 400!\n";
}

CheesePizza::~CheesePizza()
{
	delete localFactory;
}