#include <iostream>
#include "HomeTheaterFacade.h"

/*
    Definition:
    The Facade Pattern provides a unified interface to a set of interfaces in a subsytem.
    Facade defines a higherlevel interface that makes the subsystem easier to use.

    We create a class that simplifies and unifies a set of more complex classes that belong to some subsystem.
    The Facade Pattern allows us to avoid tight coupling between clients and subsystems.

    Client: Main Function
    Facade: HomeTheaterFacade - Unified interface for subsystem classes in the appliances folder

    Design Principle:
    Principle of Least Knowledge - talk only to your immediate friends.
    This principle prevents creating designs that have a large number of classes coupled together so that changes 
    in one part of the system cascade to other parts.
    When dependencies are built between many classes, it would lead to building a fragile system 
    that will be costly to maintain and complex for others to understand.

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

    - One can implement more than one facade for a subsystem.

    - An adapter wraps an object to change its interface,
      a decorator wraps an object to add new behaviors and responsibilities, 
      a facade “wraps” a set of objects to simplify.
*/

void separator()
{
    for (int i = 0; i < 70; i++)
    {
        std::cout<<"-";
    }
    std::cout<<"\n";
}

int main()
{
    Amplifier mAmp;
    RadioTuner mRadiotuner;
    DVDPlayer mDvdPlayer;
    CDPlayer mCdPlayer;
    TheaterLights mTheaterLights;
    PopcornPopper mPopper;
    Projector mProjector;
    Screen mScreen;

    HomeTheaterFacade homeTheaterFacade
                (mAmp, mRadiotuner, mDvdPlayer, mCdPlayer, mTheaterLights, mPopper, mProjector, mScreen);

    homeTheaterFacade.watchMovie(std::string("Goodfellas"));
    separator();

    homeTheaterFacade.stopMovie();
    separator();

    homeTheaterFacade.listenToCd(std::string("Greatest hits of Queen"));
    separator();

    homeTheaterFacade.stopCD();
    separator();
    
    homeTheaterFacade.listenToBBCRadio();
    separator();

    homeTheaterFacade.stopRadio();

    std::cin.get();
    return 0;
}