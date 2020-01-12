#include "Duck.h"

void Duck::performFly()
{
	flyBehavior->fly();
}

void Duck::performDuckSound()
{
	quackBehavior->quack();
}

void Duck::setFlyBehavior(IFlyBehavior* newFlyBehavior)
{
	flyBehavior = newFlyBehavior;
}

