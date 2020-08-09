#include "Whip.h"
#include <iostream>

Whip::Whip():beverage(nullptr)
{
	
}

Whip::Whip(IBeverage* beverage)
{
	this->beverage = beverage;
	std::cout << "Adding Whip to " << beverage->getDescription() << " costing " << getWhipCost() <<std::endl; 
}

std::string Whip::getDescription()
{
	return beverage->getDescription() + " Whip";
}

float Whip::cost()
{
	return beverage->cost() + getWhipCost();
}

void Whip::setBeverageSize(IBeverage::BeverageSizes size)
{
	beverage->getBeverageSize();
}

IBeverage::BeverageSizes Whip::getBeverageSize()
{
	return beverage->getBeverageSize();
}

float Whip::getWhipCost()
{
	float cost = 0.5f;
	switch (beverage->getBeverageSize())
	{
		case BeverageSizes::Small:
		{
			cost = cost * 0.25f;
			break;
		}
		case BeverageSizes::Medium:
		{
			cost = cost * 0.5f;
			break;
		}
		case BeverageSizes::Large:
		default:
		{
			cost = cost * 0.75f;
			break;
		}
	}
	return cost;
}
