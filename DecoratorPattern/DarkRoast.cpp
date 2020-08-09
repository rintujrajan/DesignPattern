#include "DarkRoast.h"
#include <iostream>

DarkRoast::DarkRoast():bevarageSize(BeverageSizes::Large), bevarageSizeString("Large")
{
    description = "Dark Roast";
	std::cout<< "Created "<< getDescription() << " costing " << cost()<<std::endl; 
}
std::string DarkRoast::getDescription()
{
    return bevarageSizeString + " " +description;
}
float DarkRoast::cost()
{
	float cost = 5.5f;
	switch(getBeverageSize())
	{
		case BeverageSizes::Small:
			cost = cost*0.4;
			break;
		case BeverageSizes::Medium:
			cost = cost*0.75;
			break;
		case BeverageSizes::Large:
			cost = cost*1.0f;
			break;
	}
	return cost;
}
void DarkRoast::setBeverageSize(BeverageSizes size)
{
	if(size!=bevarageSize)
	{
 		bevarageSize = size;
		switch(bevarageSize)
		{
			case BeverageSizes::Small:
				bevarageSizeString = "Small";
				break;
			case BeverageSizes::Medium:
				bevarageSizeString = "Medium";
				break;
			case BeverageSizes::Large:
				bevarageSizeString = "Large";
				break;
		}
		std::cout<<"Changed Bevarage Size to "<<bevarageSizeString<<std::endl;
	}
}
IBeverage::BeverageSizes DarkRoast::getBeverageSize()
{
	return bevarageSize;
}