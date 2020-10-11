#include <iostream>
#include "RemoteControl.h"
#include "Commands\LightOnCommand.h"
#include "Commands\LightOffCommand.h"
#include "Commands\CeilingFanOnCommand.h"
#include "Commands\CeilingFanOffCommand.h"
#include "Commands\StereoOnCommand.h"
#include "Commands\StereoOffCommand.h"
#include "Commands\MacroCommand.h"

/*

    The Command Pattern encapsulates a request as an object, thereby letting you parameterize other objects with different requests
    , queue or log requests, and support undoable operations

    A command object encapsulates a request by binding together a set of actions on a specific receiver.
    To achieve this, it packages the actions and the receiver up into an object that exposes just one method, execute().
    When called, execute() causes the actions to be invoked on the receiver.
    From the outside, no other objects really know what actions get performed on what receiver;
    they just know that if they call the execute() method, their request will be serviced.

    Trace the three steps in the main function to see how a command is invoked.

    Checkout the class diagram on 219 (245 / 681)

    Commands may also be used to implement logging and transactional systems. E.g. from SF:
    In one of our projects, we have the following requirement:
        1.Create a record in DB.
        2.Call a service to update a related record.
        3.Call another service to log a ticket.
    To perform this in a transactional manner, each operation is implemented as a command with undo operation.
    At the end of each step, the command is pushed onto a stack.
    If the operation fails at some step, then we pop the commands from the stack and call undo operation on each of the command popped out.
    The undo operation of each step is defined in that command implementation to reverse the earlier command.execute().

*/

int main() // The Client is responsible for creating a ConcreteCommand and setting its Receiver.
{
    /* 
        The remote is our Invoker; it will be passed a command object that can be used to make requests.
        The Invoker holds a command and at some point asks the command to carry out a request by calling its execute() method
    */
    RemoteControl rc;

    // We create a Light object, this will be the Receiver of the request
    Light kitchenLight("Kitchen");

    /*
        Step 1: The client creates a command object
        The client(main function) is responsible for creating the command object.
        The command object consists of a set of actions on a receiver.

        The Command Pattern decouples an object, making a request from the one that knows how to perform it.
        A Command object is at the center of this decoupling and encapsulates a receiver with an action (or set of actions) .
    */
    LightOnCommand* lightOnCommand = new LightOnCommand(kitchenLight); // Step 1 - create a command and pass the Receiver to it
    LightOffCommand* lightOffCommand = new LightOffCommand(kitchenLight); // Step 1

    /*
        Step 2: The client does a setCommand() to store the command object in the invoker 
        The client(main function) calls setCommand() on an Invoker object(Remote Control) and passes it the command object,
        where it gets stored until it is needed.
    */
    rc.setCommand(0, lightOnCommand, lightOffCommand);  // Step 2 - pass the command to the Invoker

    CeilingFan fan("Living Room");
    CeilingFanOnCommand* fanOnCommand = new CeilingFanOnCommand(fan); // Step 1
    CeilingFanOffCommand* fanOffCommand = new CeilingFanOffCommand(fan); // Step 1

    Stereo stereo;
    StereoOnCommand* stereoOnCommand = new StereoOnCommand(stereo); // Step 1
    StereoOffCommand* stereoOffCommand = new StereoOffCommand(stereo); // Step 1

    // Macro Commands are a simple extension of Command that allow multiple commands to be invoked. 
    std::vector<ICommand*> partyModeOnCommands{lightOnCommand, fanOnCommand, stereoOnCommand};
    ICommand *partyModeOnCommand = new MacroCommand(partyModeOnCommands,"Party Mode");  // Step 1

    std::vector<ICommand*> partyModeOffCommands{lightOffCommand, fanOffCommand, stereoOffCommand};
    ICommand *partyModeOffCommand = new MacroCommand(partyModeOffCommands,"Party Mode"); // Step 1

    rc.setCommand(0, fanOnCommand, fanOffCommand);  // Step 2   
    rc.setCommand(1, lightOnCommand, lightOffCommand);  // Step 2
    rc.setCommand(2, stereoOnCommand, stereoOffCommand);  // Step 2
    rc.setCommand(3, partyModeOnCommand, partyModeOffCommand);  // Step 2
    
    // Step 3: The client asks the invoker to execute the command.
    // we simulate the button being pressed
    rc.onButtonPushed(0);   // Step 3
    rc.offButtonPushed(0);   // Step 3
    rc.onButtonPushed(1);   // Step 3
    rc.offButtonPushed(1);   // Step 3
    rc.onButtonPushed(2);   // Step 3
    rc.offButtonPushed(2);   // Step 3
    rc.onButtonPushed(3);   // Step 3
    rc.offButtonPushed(3);   // Step 3
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