#include "ChocolateMakerSingleton.h"
#include <iostream>
#include <thread>
using namespace std;

int main()
{
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
    std::cin.get();
}