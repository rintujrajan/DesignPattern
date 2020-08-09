#include "IBeverage.h"

class DarkRoast : public IBeverage
{
    public:
    DarkRoast();
    std::string getDescription();
	float cost();
	void setBeverageSize(BeverageSizes size);
	BeverageSizes getBeverageSize();

    private:
    BeverageSizes bevarageSize;
    std::string bevarageSizeString;

};