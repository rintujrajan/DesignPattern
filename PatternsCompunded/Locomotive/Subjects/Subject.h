#pragma once
#include <memory>
#include <unordered_set>
class IObserver;
class Subject
{
private:
    std::unordered_set<std::shared_ptr<IObserver>> observersSet;

protected:
    // pure virtual function - shall be overriden so that the "this" pointer of the concrete subjects can be passed
    virtual void notifyEachObserver(const std::shared_ptr<IObserver> &observer) = 0;
    virtual void notifyAllObservers(); // has been defined in Subject class itself - shall be called by concrete subjects

public:
    virtual void registerObserver(std::shared_ptr<IObserver> observer); // has been defined in Subject class itself
    virtual void removeObserver(std::shared_ptr<IObserver> observer);   // has been defined in Subject class itself
};