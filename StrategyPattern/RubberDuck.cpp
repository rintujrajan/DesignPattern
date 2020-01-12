#include "RubberDuck.h"
#include "NoWingsToFly.h"
#include "Squeaking.h"
#include <iostream>

RubberDuck::RubberDuck()
{
	flyBehavior = new NoWingsToFly();
	quackBehavior = new Squeaking();
}

void RubberDuck::identifyDuck()
{
	std::cout << "Hey there, I am a rubber duck!\n";
}
