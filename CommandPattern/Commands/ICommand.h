#pragma once
#include <string>
/*
    Command declares an interface for all commands. 
    As you already know, a command is invoked through its execute() method, which asks a receiver to perform an action.
*/
class ICommand
{
public:
    virtual void execute() = 0;
    virtual std::string getName() = 0;
    virtual std::string getCommandObject()
    {
        return std::string();
    }
    virtual void undoCommand() = 0;
};

