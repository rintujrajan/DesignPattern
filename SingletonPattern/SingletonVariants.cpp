#include "SingletonVariants.h"
#include <mutex>
#include <iostream>

SingletonOnStack::SingletonOnStack():value(0)
{
    std::cout<<"SingletonOnStack Instance created. value:"<<value<<"\n";
}
SingletonOnStack& SingletonOnStack::getSingletonOnStackInstance()
{   
    static SingletonOnStack SingletonOnStackInstance; // Lazy Initialization
    return SingletonOnStackInstance;
}

void SingletonOnStack::incrementValue()
{
    static std::mutex mut;
    std::unique_lock<std::mutex>  lock(mut);
    std::cout<<"value before increment:"<<value<<"\t";
    value++;
    std::cout<<"value after increment:"<<value<<"\n";
}

int SingletonOnStack::getValue()
{
    return value;
}

// Lazy Initialization done when an instance is requested for the first time
SingletonOnHeapUsingDoubleCheckedLocking* SingletonOnHeapUsingDoubleCheckedLocking::singletonOnHeapUsingDoubleCheckedLockingInstance = nullptr;
/* 
   Eager Initialization to aid multi threaded env:
   If your application always creates and uses an instance of the Singleton or,
   the overhead of creation and runtime aspects of the Singleton are not onerous, you may want to create your Singleton eagerly, like this:
   
   SingletonOnHeapUsingDoubleCheckedLocking
    *singletonOnHeapUsingDoubleCheckedLocking::SingletonOnHeapUsingDoubleCheckedLockingInstance = new SingletonOnHeapUsingDoubleCheckedLocking();

    then simply return this when an isntance is requested
*/
SingletonOnHeapUsingDoubleCheckedLocking::SingletonOnHeapUsingDoubleCheckedLocking():value(0)
{
    std::cout<<"SingletonOnHeapUsingDoubleCheckedLocking Instance created. value:"<<value<<"\n";
}
SingletonOnHeapUsingDoubleCheckedLocking& SingletonOnHeapUsingDoubleCheckedLocking::getSingletonOnHeapUsingDoubleCheckedLockingInstance()
{   
    if(singletonOnHeapUsingDoubleCheckedLockingInstance == nullptr)
    {
        static std::mutex lockMutex;
        std::lock_guard<std::mutex> lock(lockMutex);
        if(singletonOnHeapUsingDoubleCheckedLockingInstance == nullptr) //double check
        {
            singletonOnHeapUsingDoubleCheckedLockingInstance = new SingletonOnHeapUsingDoubleCheckedLocking();
        }
    }
    return *singletonOnHeapUsingDoubleCheckedLockingInstance;
}

void SingletonOnHeapUsingDoubleCheckedLocking::incrementValue()
{
    static std::mutex mut;
    std::unique_lock<std::mutex>  lock(mut);
    std::cout<<"value before increment:"<<value<<"\t";
    value++;
    std::cout<<"value after increment:"<<value<<"\n";
}

int SingletonOnHeapUsingDoubleCheckedLocking::getValue()
{
    return value;
}