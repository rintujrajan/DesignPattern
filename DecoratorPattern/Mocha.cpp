#include "Mocha.h"
#include <iostream>
Mocha::Mocha():beverage(nullptr)
{
	
}

Mocha::Mocha(IBeverage* beverage)
{
	std::cout << "\nAdding Mocha to " << beverage->getDescription();
	this->beverage = beverage;
}
//Mocha::Mocha(std::shared_ptr<IBeverage> beverage)
//{
//	std::cout << "\nAdding Mocha to " << beverage->getDescription();
//	this->beverage = beverage;
//}

std::string Mocha::getDescription()
{
	return beverage->getDescription() + " Mocha";
}

float Mocha::cost()
{
	float cost = 2.5f;
	switch (beverage->getBeverageSize())
	{
	case BeverageSizes::Small:
	{
		cost = cost * 0.5f;
		break;
	}
	case BeverageSizes::Medium:
	{
		cost = cost * 0.7f;
		break;
	}
	case BeverageSizes::Large:
	default:
	{
		cost = cost * 1.0f;
		break;
	}
	}
	return beverage->cost() + cost;
}

void Mocha::setBeverageSize(IBeverage::BeverageSizes size)
{
	beverage->getBeverageSize();
}

IBeverage::BeverageSizes Mocha::getBeverageSize()
{
	return beverage->getBeverageSize();
}
