#include "ChocolateMakerSingleton.h"
#include <iostream>

using namespace std;

string ChocolateMakerSingleton::threadName;
mutex ChocolateMakerSingleton::threadNameLock;
condition_variable ChocolateMakerSingleton::threadNameLockCondition;
bool ChocolateMakerSingleton::isThreadInstanceUnLocked  = true;
bool ChocolateMakerSingleton::isNoThreadBlocking  = true;

ChocolateMakerSingleton::ChocolateMakerSingleton(std::string threadNameSent):isEmpty(true), isBolied(false)
{
    print("Private constructor called by "+ threadNameSent +"\n");
    unlockThreadInstanceLock();
}

ChocolateMakerSingleton::~ChocolateMakerSingleton()
{
    print("Destructor called.\n");
}

ChocolateMakerSingleton& ChocolateMakerSingleton::getChocolateMakerInstance(string threadNameSent)
{
    static ChocolateMakerSingleton* chocolateMakerInstance = new ChocolateMakerSingleton(threadNameSent);

    unique_lock<mutex> ul(threadNameLock);
    threadNameLockCondition.wait(ul,[](){return isThreadInstanceUnLocked && isNoThreadBlocking;});
    isThreadInstanceUnLocked = false;
    threadName = threadNameSent;
    // cout<<threadNameSent<<" has locked\n";
    return *chocolateMakerInstance;
}

void ChocolateMakerSingleton::fill()
{
    unique_lock<mutex> ul(fillLock);
    
    string statement = "";
    fillLockCondition.wait(ul, [&statement, this]
    {
        if(isEmpty)
        {
            if(!fillStack.empty())
            {
                setNoThreadBlockingStatus(false);
                print("Changing filling thread to: "+fillStack.top()+"\n");
                setThreadName(fillStack.top());
                fillStack.pop();
            }
            return true;
        }
        else
        {
            statement = getThreadName();
            statement+= ": Boiler not empty. Wait till it is empty.\n";
            print(statement);
            
            fillStack.push(getThreadName());
            print("Pushed "+ getThreadName()+" onto fill stack\n");

            unlockThreadInstanceLock();
            return false;
        }    
    });
    if(isEmpty)
    {
        statement = getThreadName();
        statement += ": 1. Boiler Empty. Filling chocolate and milk for 3 seconds!\n";
        print(statement);
        isEmpty = false;
        this_thread::sleep_for(chrono::seconds(3));
    }
    boilLockCondition.notify_all();
    unlockThreadInstanceLock();
}

void ChocolateMakerSingleton::boil()
{
    string statement = "";
    unique_lock<mutex> ul(boilLock);
    boilLockCondition.wait(ul, [&statement, this]
    {
        if(!isEmpty && !isBolied)
        {
            if(!boilStack.empty())
            {
                setNoThreadBlockingStatus(false);
                print("Changing boiling thread to: "+boilStack.top()+"\n");
                setThreadName(boilStack.top());
                boilStack.pop();
            }
            return true;
        }
        else
        {
            statement = getThreadName();
            statement+= ": Cannot proceed with boiling becasue ";
            if(isEmpty)
            {
                statement+="boiler is empty\n";
            }
            if(isBolied)
            {
                statement+="mixture is already boiled\n";
            }
            print(statement);
            
            boilStack.push(getThreadName());
            print("Pushed "+ getThreadName()+" onto boil stack\n");

            unlockThreadInstanceLock();
            return false;
        }
    });
    if(!isEmpty && !isBolied)
    {
        isBolied = true;
        statement = getThreadName();
        statement += ": 2. Boiling chocolate and milk for 10 seconds!\n";
        print(statement);
        this_thread::sleep_for(chrono::seconds(10));
    }
    drainLockCondition.notify_all();
    unlockThreadInstanceLock();
}

void ChocolateMakerSingleton::drain()
{
    string statement = "";
    unique_lock<mutex> ul(drainLock);
    drainLockCondition.wait(ul,[&statement, this]
    {
        if(!isEmpty && isBolied)
        {
            if(!drainStack.empty())
            {
                setNoThreadBlockingStatus(false);
                print("Changing draining thread to: "+drainStack.top()+"\n");
                setThreadName(drainStack.top());
                drainStack.pop();
            }
            return true;
        }
        else
        {
            statement = getThreadName();
            statement += ": Cannot proceed with draining becasue ";
            if(isEmpty)
            {
                statement+="boiler is empty";
            }
            if(!isBolied)
            {
                statement+="\tmixture is not boiled\n";
            }
            print(statement);
            drainStack.push(getThreadName());
            print("Pushed "+ getThreadName()+" onto drain stack\n");
            unlockThreadInstanceLock();
            return false;
        }
    });
    if(!isEmpty && isBolied)
    {
        isEmpty = true;
        isBolied = false;
        statement = getThreadName();
        statement += ": 3. Draining boiled chocolate and milk!\n";
        print(statement);
        this_thread::sleep_for(chrono::seconds(5));
    }
    fillLockCondition.notify_all();
    unlockThreadInstanceLock();
} 

std::string ChocolateMakerSingleton::getThreadName()
{
    return threadName;
}
void ChocolateMakerSingleton::setThreadName(std::string updatedThreadName)
{
    threadName = updatedThreadName;
}

void ChocolateMakerSingleton::print(std::string statement)
{
    lock_guard<mutex> lockPrinting(printLock);
    cout<<statement;
}

void ChocolateMakerSingleton::unlockThreadInstanceLock()
{
    // print(threadName+" relinquishing control\n");
    // ChocolateMakerSingleton::getChocolateMakerInstance(threadName, true).print(threadName+" relinquishing control\n");
    // cout<<threadName<<" relinquishing control\n";
    isThreadInstanceUnLocked = true;
    isNoThreadBlocking = true;
    threadNameLockCondition.notify_all();
}

void ChocolateMakerSingleton::setNoThreadBlockingStatus(bool status)
{
    isNoThreadBlocking = status;;
}
