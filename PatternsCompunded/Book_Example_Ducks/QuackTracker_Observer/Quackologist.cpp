#include "Quackologist.h"
#include <iostream>
#include "../IQuackable.h"

void Quackologist::update(IQuackable* duckSubject)
{
    std::cout<<"Quackologist : "<<duckSubject->getName()<<" just performed quack!\n";
}