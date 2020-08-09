#include "Mocha.h"
#include <iostream>
Mocha::Mocha():beverage(nullptr)
{
	
}

Mocha::Mocha(IBeverage* beverage)
{
	this->beverage = beverage;
	std::cout << "Adding Mocha to " << beverage->getDescription() << " costing " << getMochaCost() <<std::endl; 
}

std::string Mocha::getDescription()
{
	return beverage->getDescription() + " Mocha";
}

float Mocha::cost()
{
	return beverage->cost() + getMochaCost();
}

void Mocha::setBeverageSize(IBeverage::BeverageSizes size)
{
	beverage->getBeverageSize();
}

IBeverage::BeverageSizes Mocha::getBeverageSize()
{
	return beverage->getBeverageSize();
}

float Mocha::getMochaCost()
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
	return cost;
}