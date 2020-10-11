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
    // Thread safe in C++11- if not use a mutex
    // would be initialized only once
    static ChocolateMakerSingleton* chocolateMakerInstance = new ChocolateMakerSingleton(threadNameSent);

    //mutex used to let only one thread taking control of naming the thread
    unique_lock<mutex> ul(threadNameLock);
    threadNameLockCondition.wait(ul,[](){return isThreadInstanceUnLocked && isNoThreadBlocking;});
    isThreadInstanceUnLocked = false;
    threadName = threadNameSent;
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
            string threadName = getThreadName();
            fillStack.push(threadName);
            statement = "\n" + threadName;
            statement+= ":  Boiler not empty. Wait till it is empty.";
            statement+= " Pushed "+ threadName +" onto fill stack\n";
            print(statement);

            unlockThreadInstanceLock();
            return false;
        }    
    });
    if(isEmpty)
    {
        statement = "\n" + getThreadName();
        statement += ":  1. Boiler Empty. Filling chocolate and milk for 3 seconds!\n";
        print(statement);
        isEmpty = false;
        this_thread::sleep_for(chrono::seconds(3));
    }
    boilLockCondition.notify_one();
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
            string threadName = getThreadName();
            boilStack.push(threadName);
            statement = "\n" + threadName;
            statement+= ":  Cannot proceed with boiling because ";
            if(isEmpty)
            {
                statement+="boiler is empty";
            }
            if(isBolied)
            {
                if(isEmpty) statement+= " and ";
                statement+="mixture is already boiled";
            }
            statement+= ". Pushed " + threadName +" onto boil stack\n";
            print(statement);

            unlockThreadInstanceLock();
            return false;
        }
    });
    if(!isEmpty && !isBolied)
    {
        isBolied = true;
        statement = "\n" + getThreadName();
        statement += ":  2. Boiling chocolate and milk for 10 seconds!\n";
        print(statement);
        this_thread::sleep_for(chrono::seconds(10));
    }
    drainLockCondition.notify_one();
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
            string threadName = getThreadName();
            drainStack.push(threadName);
            statement = "\n" + threadName;
            statement += ": Cannot proceed with draining becasue ";
            if(isEmpty)
            {
                statement+="boiler is empty";
            }
            if(!isBolied)
            {
                if(isEmpty)statement+=" and ";
                statement+="mixture is not boiled";
            }
            statement+= ". Pushed "+ threadName +" onto drain stack\n";
            print(statement);

            unlockThreadInstanceLock();
            return false;
        }
    });
    if(!isEmpty && isBolied)
    {
        isEmpty = true;
        isBolied = false;
        statement = "\n" + getThreadName();
        statement += ": 3. Draining boiled chocolate and milk for 5 seconds!\n";
        print(statement);
        this_thread::sleep_for(chrono::seconds(5));
    }
    fillLockCondition.notify_one();
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
    isThreadInstanceUnLocked = true;
    isNoThreadBlocking = true;
    threadNameLockCondition.notify_one();
}

void ChocolateMakerSingleton::setNoThreadBlockingStatus(bool status)
{
    isNoThreadBlocking = status;;
}
