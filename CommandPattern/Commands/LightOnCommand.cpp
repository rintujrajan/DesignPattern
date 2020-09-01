#include "LightOnCommand.h"

LightOnCommand::LightOnCommand(Light light)
{
    this->light = light;
}
void LightOnCommand::execute()
{
    light.on();
}

void LightOnCommand::undoCommand()
{
    light.off();
}