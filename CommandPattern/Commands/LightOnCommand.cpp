#include "LightOnCommand.h"

LightOnCommand::LightOnCommand(Light light)
{
    this->light = light;
}

// The command object provides one method, execute(), that encapsulates the actions and can be called to invoke the actions on the Receiver.
void LightOnCommand::execute()
{
    // The actions(on here) and the Receiver(light) are bound together in the command object.
    light.on();
}

void LightOnCommand::undoCommand()
{
    light.off();
}