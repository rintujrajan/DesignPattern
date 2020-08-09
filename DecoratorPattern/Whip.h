#pragma once
#include "ICondiment.h"

class Whip :
	public ICondiment
{
private:
	float getWhipCost();
	IBeverage* beverage;
public:
	Whip();
	Whip(IBeverage* beverage);
	std::string getDescription() override;
	float cost() override;
	virtual void setBeverageSize(IBeverage::BeverageSizes size) override;
	virtual IBeverage::BeverageSizes getBeverageSize() override;
};

