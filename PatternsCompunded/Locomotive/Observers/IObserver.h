#pragma once
class Subject;
class IObserver
{
private:
    /* data */
public:
    virtual void notify(Subject *subject) = 0;
};
