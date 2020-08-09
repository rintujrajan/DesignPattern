#pragma once
#include "ICondiment.h"

class Mocha :
	public ICondiment
{
private:
	float Mocha::getMochaCost();
	IBeverage* beverage;

public:
	Mocha();
	Mocha(IBeverage* beverage);
	std::string getDescription() override;
	float cost() override;
	virtual void setBeverageSize(IBeverage::BeverageSizes size) override;
	virtual IBeverage::BeverageSizes getBeverageSize() override;
};

