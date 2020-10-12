#pragma once

/*
    The Target is the Duck class. This is what the client invokes method on
*/
class IDuck
{

public:
    virtual void fly() = 0;
    virtual void quack() = 0;
};

