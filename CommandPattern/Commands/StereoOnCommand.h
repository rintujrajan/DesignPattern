#pragma once
#include "ICommand.h"
#include "..\Appliances\Stereo.h"

class StereoOnCommand:public ICommand
{
    Stereo stereo;
public:
    StereoOnCommand() = default;
    StereoOnCommand(Stereo stereo);
    virtual void execute();
    virtual void undoCommand();
    inline std::string getName()
    {
        return "Stereo";
    }
    inline std::string getCommandObject()
    {
        return stereo.getname();
    }
};


