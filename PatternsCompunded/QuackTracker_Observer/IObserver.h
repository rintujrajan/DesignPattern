#pragma once
/*
    If a class implements IObserver, that means it can observe any IQuackables, and will be notified whenever an IQuackable quacks.
*/
class IQuackable;
class IObserver
{
public:
    virtual void update(IQuackable* duckSubject) = 0;
};


