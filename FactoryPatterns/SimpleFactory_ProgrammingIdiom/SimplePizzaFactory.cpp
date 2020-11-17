#include "SimplePizzaFactory.h"
#include "CheezePizza.h"
#include "PepperoniPizza.h"


IPizza* SimplePizzaFactory::createPizza(std::string type)
{
	IPizza* pizza = NULL;
	std::cout << type+" pizza ordered\n";
	if (type == "Cheeze")
	{
		pizza = new CheezePizza();
	}
	else if (type == "Pepperoni")
	{
		pizza = new CheezePizza();
	}
	else
	{
		std::cout << "Ordered pizza unavailable!\n";
	}
	return pizza;

}
