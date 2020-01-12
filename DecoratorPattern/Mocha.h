#pragma once
#include "ICondiment.h"
#include<memory>

class Mocha :
	public ICondiment
{
public:
	Mocha();
	Mocha(IBeverage* beverage);
	//Mocha(std::shared_ptr<IBeverage> beverage);
	std::string getDescription() override;
	float cost() override;
	virtual void setBeverageSize(IBeverage::BeverageSizes size) override;
	virtual IBeverage::BeverageSizes getBeverageSize() override;
	//std::shared_ptr<IBeverage> beverage;
	IBeverage* beverage;
};

