#include "WildTukey.h"
#include <iostream>

/*
    The WildTurkey class doesn’t have the same interface as the Duck.
    In other words, Turkeys don’t have quack() methods, etc.

    Thanks to the Adapter(TurkeyAdapter), the WildTurkey(Adaptee) will get calls that the client makes on the Duck interface.
*/

void WildTurkey::fly()
{
    std::cout<<"Wild Turkey Flying\n";
}

void WildTurkey::gobble()
{
    std::cout<<"Wild Turkey gobbling - gobble gobble\n";
}
