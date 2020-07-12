// StrategyPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/******************************************************************************
*******************************************************************************
*******************************************************************************
The code for this pattern is based up on the Head First Design patterns book
which is availaible in the root folder of the project

The Strategy Pattern defines a family of algorithms,encapsulates each one, 
and makes them interchangeable. Strategy lets the algorithm vary independently
from clients that use it.

In this code the client(duck and their subclasses) make use of an encapsulateed
family of algotithms for both flying and quacking.

The Fly Behaviour and Quack Behavior along with repsective subclasses are 
encapsulated 

The client(duck) class adds the two Behaviors as in compostion instead of
inheriting them. 

An import design principle - Favour Composition over Inheritance

For a clear picture refer to page 22(34) and 23(35) of the book

*******************************************************************************
*******************************************************************************
*******************************************************************************/

#include "ARealDuck.h"
#include "RubberDuck.h"
#include "FlyWithRocket.h"

using namespace std;

void callDuck(Duck* duck)
{
	duck->identifyDuck();
	duck->performFly();
	duck->performDuckSound();
}

int main()
{
	Duck* duck = new ARealDuck();

	cout << "A real duck's behavior:\n";
	callDuck(duck);

	cout << "\nA rubber duck's behavior:\n";
	duck = new RubberDuck();
	callDuck(duck);

	duck->setFlyBehavior(new FlyWithRocket());
	cout << "\nA rubber duck's behavior after behavior change:\n";
	callDuck(duck);

	return 0;
}