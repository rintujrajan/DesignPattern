#include "Espresso.h"

Espresso::Espresso()
{
	description = "Espresso";
}

std::string Espresso::getDescription()
{
	std::string size;
	switch (getBeverageSize())
	{
	case BeverageSizes::Small:
	{
		size="Small";
		break;
	}
	case BeverageSizes::Medium:
	{
		size = "Medium";
		break;
	}
	case BeverageSizes::Large:
	{
		size = "Large";
		break;
	}
	}
	return size+R"( )"+description;
}

float Espresso::cost()
{
	float cost = 10.5f;
	switch (getBeverageSize())
	{
	case BeverageSizes::Small:
	{
		cost = cost*0.5f;
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

void Espresso::setBeverageSize(IBeverage::BeverageSizes size)
{
	beverageSize = size;
}

IBeverage::BeverageSizes Espresso::getBeverageSize()
{
	return beverageSize;
}
