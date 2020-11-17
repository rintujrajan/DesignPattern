#include "PizzaStore.h"

/*
	The Simple Factory isn’t actually a Design Pattern; it’s more of a programming idiom.

	It is used to decopule the code which is not going to change from the code which is likely to change.

	Check PizaStore class comments.

	PizzaStore(orderPizza called) -> SimplePizzaFactory(createPizza called) -> Pizza

*/

int main()
{
	SimplePizzaFactory pizzaFactory;

	PizzaStore aTypicalPizzaStore(pizzaFactory);

	aTypicalPizzaStore.orderPizza("Cheeze");

	aTypicalPizzaStore.orderPizza("Pepperoni");

	aTypicalPizzaStore.orderPizza("Veggie");

	std::cin.get();
}
