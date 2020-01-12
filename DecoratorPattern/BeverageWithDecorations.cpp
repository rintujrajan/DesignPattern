#include "IBeverage.h"
#include "Espresso.h"
#include "Mocha.h"
#include <memory>
#include <iostream>

int main()
{
	IBeverage* espresso = new Espresso();
	espresso->setBeverageSize(IBeverage::BeverageSizes::Small);
	//std::shared_ptr<IBeverage> espresso(new Espresso);
	std::cout << "Beverage : " << espresso->getDescription()
		      << "\nCost     : " << espresso->cost();

	IBeverage* mocha = new Mocha(espresso);

	//std::shared_ptr<IBeverage> mocha(new Mocha(espresso));
	std::cout << "\nBeverage : " << mocha->getDescription()
		      << "\nCost     : " << mocha->cost();
}
