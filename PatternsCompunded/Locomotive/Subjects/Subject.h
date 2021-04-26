#pragma once
#include <memory>
#include <unordered_set>
class IObserver;
class Subject
{
protected:
    std::unordered_set<std::shared_ptr<IObserver>> observersSet;

protected:
    // pure virtual function - shall be overriden so that the "this" pointer of the concrete subjects can be passed
    virtual void notifyEachObserver() = 0;

public:
    virtual void registerObserver(std::shared_ptr<IObserver> observer); // has been defined in Subject class itself
    virtual void removeObserver(std::shared_ptr<IObserver> observer);   // has been defined in Subject class itself
};