#include "ARealDuck.h"
#include "FlyWithWings.h"
#include "RealQuacking.h"
#include <iostream>

ARealDuck::ARealDuck()
{
	flyBehavior = new FlyWithWings();
	quackBehavior = new RealQuacking();
}

void ARealDuck::identifyDuck()
{
	std::cout << "Hey I am a real duck!\n";
}
