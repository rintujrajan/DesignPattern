#include <iostream>

#include "Ducks\MallardDuck.h"
#include "Ducks\RedheadDuck.h"
#include "Ducks\DuckCall.h"
#include "Ducks\RubberDuck.h"
#include "Geese\Geese.h"
#include "Geese\GeeseAdapter.h"
#include "Decorator\DuckWithQuackCounter.h"
#include "AbstractFactories\DuckFactory.h"
#include "AbstractFactories\DuckFactoryWithQuackCounter.h"
#include "Composite\Flock.h"
#include "QuackTracker_Observer\Quackologist.h"

/*
1. We started with a bunch of Quackables(**Duck Folder):
   a. Two Real ducks - Mallard duck and Redhead Duck
   b. A Rubber Duck
   c. A duck call imitating the quack sound

2. A goose came along and wanted to act like a Quackable too. 
   So we used the Adapter Pattern to adapt the goose to a Quackable.
   Now, you can call quack() on a goose wrapped in the adapter and it will honk!(**Geese Folder)

3. Then, the Quackologists decided they wanted to count quacks. 
   So we used the Decorator Pattern to add a QuackCounter decorator that keeps track of the number of times quack() is called,
   and then delegates the quack to the Quackable it’s wrapping.(**Decorator Folder)

4. But the Quackologists were worried they’d forget to add the QuackCounter decorator.
   So we used the Abstract Factory Pattern to create ducks for them.
   Now, whenever they want a duck, they ask the factory for one, and it hands back a decorated duck. (**AbstractFactories Folder)
   (And don’t forget, they can also use another duck factory if they want an un-decorated duck!)

5. We had management problems keeping track of all those ducks and geese and quackables.
   So we used the Composite Pattern to group quackables into Flocks. The pattern also allows the quackologist to create sub-Flocks to manage duck families.
   We used the Iterator Pattern in our implementation by using iterator over vector collection. (**Composite Folder)

6. The Quackologists also wanted to be notified when any quackable quacked.
   So we used the Observer Pattern to let the Quackologists register as Quackable Observers.
   Now they’re notified every time any Quackable quacks. We used iterator again in this implementation.
   The Quackologists can even use the Observer Pattern with their composites. (QuackTacker_Observer Folder)

Checkout the complete class diagram on pages 536(562) and 537(563)

*/

void simulate(IQuackable *duck)
{
    // depending of the type of IQuackable the corresponding quack get called
    // if it is a flock composiite then the quack from composite class get called
    duck->quack();
}

int main()
{
    // The two factories - DuckFactory & DuckFactoryWithQuackCounter
    // DuckFactoryWithQuackCounter provides new objects of real ducks with a count decorator and no object with no count decorator for non real ducks
    IAbstractDuckFactory* duckFactory = new DuckFactory();
    IAbstractDuckFactory* duckFactoryWithQuackCounter = new DuckFactoryWithQuackCounter();

    Flock* flockOfDucks = new Flock();
    IQuackable* redheadDuckWithQuackCounter = duckFactoryWithQuackCounter->createRedHeadDuck();
    IQuackable* duckCall = duckFactory->createDuckCall();
    IQuackable* rubberDuck = duckFactory->createRubberDuck();
    Geese* geese = new Geese();
    IQuackable* geeseMaskedAsDuck = new GeeseAdapter(geese);
    flockOfDucks->add(redheadDuckWithQuackCounter);
    flockOfDucks->add(duckCall);
    flockOfDucks->add(rubberDuck);
    flockOfDucks->add(geeseMaskedAsDuck);

    Flock* flockOfMallards = new Flock();
    IQuackable* mallardDuck1WithQuackCounter = duckFactoryWithQuackCounter->createMallardDuck();
    IQuackable* mallardDuck2WithQuackCounter = duckFactoryWithQuackCounter->createMallardDuck();
    IQuackable* mallardDuck3WithQuackCounter = duckFactoryWithQuackCounter->createMallardDuck();
    flockOfMallards->add(mallardDuck1WithQuackCounter);
    flockOfMallards->add(mallardDuck2WithQuackCounter);
    flockOfMallards->add(mallardDuck3WithQuackCounter);

    // flockOfDucks contains duck objects created by factories and also a flock of Mallards
    // Hence we have a composite
    flockOfDucks->add(flockOfMallards);

    IObserver* quackologist = new Quackologist();
    flockOfDucks->registerObserver(quackologist); //quackologist registered to entire flockOfDucks 

    simulate(flockOfDucks);

    // Only real ducks quack. checkout DuckCall and RubberDuck creation in DuckFactoryWithQuackCounter
    // Even if we had used DuckFactoryWithQuackCounter the duckCall and RubberDuck would not have been included in the count
    std::cout<< "\n" << DuckWithQuackCounter::getQuackCount()<<" real \"Quacks\" were recorded\n"; 

    std::cin.get();

    delete duckFactoryWithQuackCounter;
    delete duckFactory;
    delete flockOfDucks;
    delete redheadDuckWithQuackCounter;
    delete duckCall;
    delete rubberDuck;
    delete geese;
    delete geeseMaskedAsDuck;
    delete flockOfMallards;
    delete mallardDuck1WithQuackCounter;
    delete mallardDuck2WithQuackCounter;
    delete mallardDuck3WithQuackCounter;
    delete quackologist;
}