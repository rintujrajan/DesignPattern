#pragma once
#include "ICommand.h"
#include "..\Appliances\Light.h"

class Light;
class LightOffCommand:public ICommand
{
    Light light;
public:
    LightOffCommand() = default;
    LightOffCommand(Light light);
    virtual void execute();
    virtual void undoCommand();
    inline std::string getName()
    {
        return "Light";
    }
    inline std::string getCommandObject()
    {
        return light.getname();
    }
};


