#pragma once
#include"IBeverage.h"
class ICondiment:public IBeverage
{
public:
	virtual std::string getDescription() = 0;
	virtual float cost() = 0;
	virtual void setBeverageSize(BeverageSizes size) = 0;
	virtual BeverageSizes getBeverageSize() = 0;
};
