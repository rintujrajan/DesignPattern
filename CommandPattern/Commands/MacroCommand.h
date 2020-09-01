#pragma once
#include "ICommand.h"
#include <vector>
class MacroCommand: public ICommand
{
private:
    std::vector<ICommand*> savedCommands;
    std::string commandName;

public:
    MacroCommand() = default;
    MacroCommand(std::vector<ICommand*> savedCommands, std::string commandName);
    virtual void execute();
    virtual void undoCommand();
    inline std::string getName()
    {
        return commandName;
    }
    ~MacroCommand();
};

