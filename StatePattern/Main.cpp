#include <iostream>
#include <iomanip>
#include "GumBallMachine.h"

/*

The State pattern is closely related to the concept of a Finite-State Machine.
The code could also be written with a lot of conditional statements(like page 403 (429 / 681)).
The biggest weakness of a state machine based on conditionals reveals itself once we start adding more and more states and state-dependent behaviors to the context class. 
Hence we use the the state design pattern.
Definition:
    a. The State Pattern allows an object to alter its behavior when its internal state changes.
    Because the pattern encapsulates state into separate classes and delegates to the object representing the current state,
    we know that behavior changes along with the internal state.
    The Gumball Machine provides a good example: 
    When the gumball machine is in the NoQuarterState and you insert a quarter, you get different behavior (the machine accepts the quarter),
    than if you insert a quarter when it’s in the HasQuarterState (the machine rejects the quarter).
    b. The object will appear to change its class.
    Think about it from the perspective of a client: if an object you’re using can completely change its behavior,
    then it appears that the object is actually instantiated from another class.
    In reality, however, we are using composition to give the appearance of a class change by simply referencing different state objects.

Components:
1. Context: 
    The Context is the class that can have a number of internal states.
    In our example, the GumballMachine is the Context.
2. State: 
    The State interface defines a common interface for all concrete states; the states all implement the same interface, so they are interchangeable.
    In our example it is the IState abstract class
3. Concrete States:
   ConcreteStates handle requests from the Context. Each ConcreteState provides its own implementation for a request.
   In this way, when the Context changes state, its behavior will change as well.
   In our example the NoQuarterState is a concrete state based on IState. It handles the request from GumBallMachine for each request from it.
   The same is for all the other concrete states - SoldOutState, HasQuarterState and DispenseState.

State can be considered as an extension of Strategy.
Both patterns are based on composition: they change the behavior of the context by delegating some work to helper objects.
Strategy makes these objects completely independent and unaware of each other.
However, State doesn’t restrict dependencies between concrete states, letting them alter the state of the context at will.

*/  

void printDashLine()
{
for (int i = 0; i <80; i++)
{
std::cout<<"-";
}
std::cout<<"\n";
}

int main()
{
GumBallMachine* gumballMachine = new GumBallMachine(4);
std::cout<<gumballMachine;

printDashLine();
std::cout<< "1.\n";
gumballMachine->insertQuarter();
gumballMachine->turnCrank();
std::cout<<gumballMachine;

printDashLine();
std::cout<< "2.\n";
gumballMachine->insertQuarter();
gumballMachine->ejectQuarter();
gumballMachine->turnCrank();
std::cout<<gumballMachine;
   
printDashLine();
std::cout<< "3.\n";
gumballMachine->insertQuarter();
gumballMachine->addGumBalls(10);
gumballMachine->turnCrank();
gumballMachine->insertQuarter();
gumballMachine->turnCrank();
gumballMachine->ejectQuarter();
std::cout<<gumballMachine;

printDashLine();
std::cout<< "4.\n";
gumballMachine->insertQuarter();
gumballMachine->insertQuarter();
gumballMachine->turnCrank();
gumballMachine->insertQuarter();
gumballMachine->turnCrank();
std::cout<<gumballMachine;

printDashLine();
std::cout<< "5.\n";
gumballMachine->addGumBalls(10);
std::cout<<gumballMachine;

std::cin.get();
return 0;
}