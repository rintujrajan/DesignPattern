#include "IBeverage.h"
#include "Espresso.h"
#include "Mocha.h"
#include "Whip.h"
#include "DarkRoast.h"
#include <iostream>

void PrepareBeverages()
{
	IBeverage* espresso = new Espresso();
	espresso->setBeverageSize(IBeverage::BeverageSizes::Small);
	std::cout << "Beverage : " << espresso->getDescription()
		      << "\nCost     : " << espresso->cost()<<std::endl<<std::endl;

	IBeverage* mochaEspresso = new Mocha(espresso);
	std::cout << "Beverage : " << mochaEspresso->getDescription()
		      << "\nCost     : " << mochaEspresso->cost()<<std::endl<<std::endl;

	IBeverage* whippedMochaEspresso = new Whip(mochaEspresso);
	std::cout << "Beverage : " << whippedMochaEspresso->getDescription()
		      << "\nCost     : " << whippedMochaEspresso->cost()<<std::endl<<std::endl;


	std::cout<<"\n\n**************************\n\n";

	delete mochaEspresso, whippedMochaEspresso;


	IBeverage* darkCoffee = new DarkRoast();
	darkCoffee->setBeverageSize(IBeverage::BeverageSizes::Medium);

	std::cout << "\nBeverage : " << darkCoffee->getDescription()
		      << "\nCost     : " << darkCoffee->cost()<<std::endl<<std::endl;

	IBeverage* doubleMochaWhippedDarkCoffee = 
			new Whip(new Mocha(new Mocha(darkCoffee)));

	std::cout << "\nBeverage : " << doubleMochaWhippedDarkCoffee->getDescription()
		      << "\nCost     : " << doubleMochaWhippedDarkCoffee->cost()<<std::endl<<std::endl;

	delete darkCoffee, doubleMochaWhippedDarkCoffee;	
}
 int main()
 {
	
	PrepareBeverages();
	std::cin.get();
 }