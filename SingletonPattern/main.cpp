#include "ChocolateMakerSingleton.h"
#include "SingletonVariants.h"
#include <iostream>
#include <thread>
#include <string>
using namespace std;

/*

    Definition - The Singleton Pattern ensures a class has only one instance, and provides a global point of access to it

    SF advice:
    A Singleton candidate must satisfy three requirements:
        -controls concurrent access to a shared resource.
        -access to the resource will be requested from multiple, disparate parts of the system.
        -there can be only one object.
    If your proposed Singleton has only one or two of these requirements, a redesign is almost always the correct option.
    For example, a printer spooler is unlikely to be called from more than one place (the Print menu),
    so you can use mutexes to solve the concurrent access problem.
    A simple logger is the most obvious example of a possibly-valid Singleton, but this can change with more complex logging schemes.

    Q: I’ve always been taught that a class should do one thing and one thing only. 
       For a class to do two things is considered bad OO design. Isn’t a Singleton violating this?
    A: You would be referring to the “One Class, One Responsibility” principle, and yes, you are correct, 
       the Singleton is not only responsible for managing its one instance (and providing global access),
       it is also responsible for whatever its main role is in your application. 
       So, certainly it can be argued it is taking on two responsibilities. 
       Nevertheless, it isn’t hard to see that there is utility in a class managing its own instance; 
       it certainly makes the overall design simpler. In addition, many developers are familiar with the Singleton pattern as it is in wide use. 
*/

void makeThreadedChocolate()
{
    std::cout<<"Chocloate Boiler example in a multithreaded env:\n";
    thread t1(
        []()
        {
            ChocolateMakerSingleton::getChocolateMakerInstance("Thread1(fill)").fill();
        });
    thread t2(
        []()
        {
            ChocolateMakerSingleton::getChocolateMakerInstance("Thread2(fill)").fill();
        });
    thread t3(
        []()
        {
            ChocolateMakerSingleton::getChocolateMakerInstance("Thread3(boil)").boil();
        });
    thread t4(
        []()
        {
            ChocolateMakerSingleton::getChocolateMakerInstance("Thread4(boil)").boil();
        });
    thread t5(
        []()
        {
            ChocolateMakerSingleton::getChocolateMakerInstance("Thread5(drain)").drain();
        });  
    thread t6(
        []()
        {
            ChocolateMakerSingleton::getChocolateMakerInstance("Thread6(drain)").drain();
        });  
       
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();


    // const int size = 3;
    // static int j = 1;
    // std::thread bolierThreads[size];

    // for (int i=0; i<size; i++){
    //     std::string threadName;
    //     if(i <= 0)
    //     {
    //         bolierThreads[i] = std::thread([&threadName]()
    //         {
    //             threadName = "Thread" + std::to_string(j) + "(fill)";
    //             ChocolateMakerSingleton::getChocolateMakerInstance(threadName).fill();
    //         });
    //     }
    //     else if(i <= 1)
    //     {
    //         bolierThreads[i] = std::thread([&threadName]()
    //         {
    //             threadName = "Thread" + std::to_string(j) + "(boil)";
    //             ChocolateMakerSingleton::getChocolateMakerInstance(threadName).boil();
    //         });
    //     }
    //     else
    //     {
    //         bolierThreads[i] = std::thread([&threadName]()
    //         {
    //             threadName = "Thread" + std::to_string(j) + "(drain)";
    //             ChocolateMakerSingleton::getChocolateMakerInstance(threadName).drain();
    //         });
    //     }
        
    // }
    // for (int i=0; i<size; i++){
    //     bolierThreads[i].join();
    //     ++j;
    // }
}

void checkStackSingleton()
{
    std::cout<<"\n\nSingletion created on stack used in a multithreaded env:\n";
    const int size = 3;
    std::thread stackThreads[size];

    for (int i=0; i<size; i++){
        stackThreads[i] = std::thread([]()
        {
           SingletonOnStack::getSingletonOnStackInstance().incrementValue();
        });
    }
    for (int i=0; i<size; i++){
        stackThreads[i].join();
    }

    std::cout<< "Value:" << SingletonOnStack::getSingletonOnStackInstance().getValue()<<"\n";
}

void checkHeapSingleton()
{
    std::cout<<"\n\nSingletion created on heap via double locking check used in a multithreaded env:\n";
    const int size = 3;
    std::thread stackThreads[size];

    for (int i=0; i<size; i++){
        stackThreads[i] = std::thread([]()
        {
           SingletonOnHeapUsingDoubleCheckedLocking::getSingletonOnHeapUsingDoubleCheckedLockingInstance().incrementValue();
        });
    }
    for (int i=0; i<size; i++){
        stackThreads[i].join();
    }

    std::cout<< "Value:" << SingletonOnHeapUsingDoubleCheckedLocking::getSingletonOnHeapUsingDoubleCheckedLockingInstance().getValue()<<"\n";
}

int main()
{
    
    makeThreadedChocolate();
    
    checkStackSingleton();

    checkHeapSingleton();

    std::cin.get();
}