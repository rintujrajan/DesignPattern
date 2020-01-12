#include "PizzaStore.h"

PizzaStore::PizzaStore(SimplePizzaFactory simplePizzaFactory)
{
	this->simplePizzaFactory = simplePizzaFactory;
}

IPizza* PizzaStore::orderPizza(std::string pizzaType)
{
	IPizza* pizza = NULL;
	pizza = simplePizzaFactory.createPizza(pizzaType);
	pizza->prepare();
	pizza->bake();
	pizza->cut();
	pizza->box();
	pizza->clearOrder();
	return pizza;
}
