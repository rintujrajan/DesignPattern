#pragma once
#include <string>
class IBeverage
{
public:
	std::string description;
	enum class BeverageSizes
	{
		Small = 1,
		Medium = 2,
		Large = 3
	};

	virtual std::string getDescription() = 0;
	virtual float cost() = 0;
	virtual void setBeverageSize(BeverageSizes size) = 0;
	virtual BeverageSizes getBeverageSize() = 0;
};

