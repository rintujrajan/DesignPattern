#pragma once
#include "ICommand.h"
#include "..\Appliances\CeilingFan.h"

class CeilingFanOffCommand:public ICommand
{
    CeilingFan ceilingFan;
public:
    CeilingFanOffCommand() = default;
    CeilingFanOffCommand(CeilingFan ceilingFan);
    virtual void execute();
    virtual void undoCommand();
    inline std::string getName()
    {
        return "Ceiling Fan";
    }
    inline std::string getCommandObject()
    {
        return ceilingFan.getname();
    }
};


