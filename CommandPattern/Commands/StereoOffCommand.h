#pragma once
#include "ICommand.h"
#include "..\Appliances\Stereo.h"

class StereoOffCommand:public ICommand
{
    Stereo stereo;
public:
    StereoOffCommand() = default;
    StereoOffCommand(Stereo stereo);
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


