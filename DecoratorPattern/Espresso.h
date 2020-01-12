#pragma once
#include "IBeverage.h"
class Espresso :
	public IBeverage
{
public:
	Espresso();
	std::string getDescription() override;
	float cost() override;
	virtual void setBeverageSize(IBeverage::BeverageSizes size) override;
	virtual IBeverage::BeverageSizes getBeverageSize() override;
	BeverageSizes beverageSize;
};

