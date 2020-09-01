#include "TurkeyAdapter.h"
#include <iostream>

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
    // std::cout<<"Mallard Duck Flying\n";
    for (int i = 0; i < 5; i++)
    {
        turkey->fly();
    }
    
}

void TurkeyAdapter::quack()
{
    // std::cout<<"Mallard Duck quacking - quack quack quack\n";
    turkey->gobble();
}
