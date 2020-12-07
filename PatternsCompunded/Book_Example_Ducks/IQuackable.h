#ifndef I_QUACKABLE
#define I_QUACKABLE
#include "QuackTracker_Observer\ISubject.h"
/*
    IQuackable is the interface that all classes that have quacking behavior implement.
*/
class IQuackable : public ISubject
{
public:
    virtual void quack() = 0;
    virtual std::string getName() { return "";};
};


#endif