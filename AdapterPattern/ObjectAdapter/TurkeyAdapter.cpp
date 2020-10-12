#include "TurkeyAdapter.h"
#include <iostream>

/*
    The Adapter implements the Duck interface(IDuck),
    but when it gets a method call it turns around and delegates the calls to a Turkey(Adaptee)
*/
TurkeyAdapter::TurkeyAdapter(ITurkey* turkey)
{
    this->turkey = turkey;
}

TurkeyAdapter::~TurkeyAdapter()
{
    delete turkey;
}
void TurkeyAdapter::fly()
{
    std::cout<<"Client calling fly and the adaptor would translate the request \n";
    for (int i = 0; i < 5; i++)
    {
        // Thanks to the Adapter(TurkeyAdapter), the WildTurkey(Adaptee) will get calls that the client makes on the Duck interface.
        turkey->fly();
    }
}

void TurkeyAdapter::quack()
{
    std::cout<<"Client calling quack and the adaptor would translate the request \n";
    // Thanks to the Adapter(TurkeyAdapter), the WildTurkey(Adaptee) will get calls that the client makes on the Duck interface.
    turkey->gobble();
}
