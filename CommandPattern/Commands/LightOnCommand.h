#pragma once
#include "ICommand.h"
#include "..\Appliances\Light.h"

class Light;
class LightOnCommand:public ICommand
{
    Light light;
public:
    LightOnCommand() = default;
    LightOnCommand(Light light);
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


