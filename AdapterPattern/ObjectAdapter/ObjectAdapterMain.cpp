#include <iostream>
#include "MallardDuck.h"
#include "WildTukey.h"
#include "TurkeyAdapter.h"

/*
    The Adapter Pattern converts the interface of a class into another interface the clients expect.
    Adapter lets classes work together that couldn’t otherwise because of incompatible interfaces.

    This pattern allows us to use a client with an incompatible interface by creating an Adapter that does the conversion.
    This acts to decouple the client from the implemented interface, and if we expect the interface to change over time,
    the adapter encapsulates that change so that the client doesn’t have to be modified
    each time it needs to operate against a different interface.

    Terms used:
    Client  
        - testDuck function
        - The Client(testDuck) is implemented against the target interface
    Target
        - IDuck - Duck Interface
        - The Target is the Duck class. This is what the client invokes method on
    Adapter 
        - TurkeyAdapter 
        - The Adapter implements the target interface and holds an instance of the Adaptee(composition)
        - The Adapter implements the Duck interface(IDuck),
          but when it gets a method call it turns around and delegates the calls to a Turkey(Adaptee)
    Adaptee 
        - WildTurkey

    Note that the Client and Adaptee are decoupled – neither knows about the other.

    Adapter v/s Facade
    Each changes an interface, the adapter to convert and the facade to unify and simplify

    - When you need to use an existing class and its interface is not the one you need, use an adapter.
    - When you need to simplify and unify a large interface or complex set of interfaces, use a facade.

    - An adapter changes an interface into one a client expects.
    - A facade decouples a client from a complex subsystem.

    - Implementing an adapter may require little work or a great deal of work depending on the size
      and complexity of the target interface.
    - Implementing a facade requires that we compose the facade with its subsystem
      and use delegation to perform the work of the facade.

    - There are two forms of the Adapter Pattern: object and class adapters.
      Class adapters require multiple inheritance.

    - One can implement more than one facade for a subsystem.

    - An adapter wraps an object to change its interface,
      a decorator wraps an object to add new behaviors and responsibilities, 
      a facade “wraps” a set of objects to simplify.

*/

/*
    The Client(testDuck) is implemented against the target interface
*/
void testDuck(IDuck* duck)
{
    // Client thinks it’s talking to a Duck 
    duck->fly();
    duck->quack();
}
int main()
{
    IDuck* mallardDuck = new MallardDuck();
    testDuck(mallardDuck);

    std::cout<<"\n\n";

    ITurkey* wildTurkey = new WildTurkey();
    // The adapter translates the request into one or more calls on the adaptee using the adaptee interface.
    TurkeyAdapter* wildTurkeyAdapter = new TurkeyAdapter(wildTurkey);
    // The client receives the results of the call and never knows there is an adapter doing the translation.
    testDuck(wildTurkeyAdapter);

    std::cin.get();

    delete mallardDuck;
    delete wildTurkey;
    delete wildTurkeyAdapter;
    return 0;
}