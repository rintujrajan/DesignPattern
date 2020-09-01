#pragma once
#include "ICommand.h"

class NoCommand:public ICommand
{
public:
    virtual void execute();
    virtual void undoCommand();
    inline std::string getName()
    {
        return "No Command";
    }
};


