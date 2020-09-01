#pragma once
#include <string>
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

