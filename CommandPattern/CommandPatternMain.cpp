#include <iostream>
#include "RemoteControl.h"
#include "Commands\LightOnCommand.h"
#include "Commands\LightOffCommand.h"
#include "Commands\CeilingFanOnCommand.h"
#include "Commands\CeilingFanOffCommand.h"
#include "Commands\StereoOnCommand.h"
#include "Commands\StereoOffCommand.h"
#include "Commands\MacroCommand.h"

int main()
{
    RemoteControl rc;

    Light kitchenLight("Kitchen");
    LightOnCommand* lightOnCommand = new LightOnCommand(kitchenLight);
    LightOffCommand* lightOffCommand = new LightOffCommand(kitchenLight);
    rc.setCommand(0, lightOnCommand, lightOffCommand);

    CeilingFan fan("Living Room");
    CeilingFanOnCommand* fanOnCommand = new CeilingFanOnCommand(fan);
    CeilingFanOffCommand* fanOffCommand = new CeilingFanOffCommand(fan);

    Stereo stereo;
    StereoOnCommand* stereoOnCommand = new StereoOnCommand(stereo);
    StereoOffCommand* stereoOffCommand = new StereoOffCommand(stereo);

    std::vector<ICommand*> partyModeOnCommands{lightOnCommand, fanOnCommand, stereoOnCommand};
    ICommand *partyModeOnCommand = new MacroCommand(partyModeOnCommands,"Party Mode");

    std::vector<ICommand*> partyModeOffCommands{lightOffCommand, fanOffCommand, stereoOffCommand};
    ICommand *partyModeOffCommand = new MacroCommand(partyModeOffCommands,"Party Mode");

    rc.setCommand(0, fanOnCommand, fanOffCommand);   
    rc.setCommand(1, lightOnCommand, lightOffCommand);
    rc.setCommand(2, stereoOnCommand, stereoOffCommand);
    rc.setCommand(3, partyModeOnCommand, partyModeOffCommand);
    
    rc.onButtonPushed(0);
    rc.offButtonPushed(0);
    rc.onButtonPushed(1);
    rc.offButtonPushed(1);
    rc.onButtonPushed(2);
    rc.offButtonPushed(2);
    rc.onButtonPushed(3);
    rc.offButtonPushed(3);
    rc.undo();
    std::cin.get();

    delete lightOnCommand;
    delete lightOffCommand;
    delete fanOnCommand;
    delete fanOffCommand;
    delete stereoOnCommand;
    delete stereoOffCommand;
    delete partyModeOffCommand;
    delete partyModeOffCommand;
    for (auto onCommand : partyModeOnCommands)
    {
        delete onCommand;
    }
    for (auto offCommand : partyModeOffCommands)
    {
        delete offCommand;
    }
    return 0;
}