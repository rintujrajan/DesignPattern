#include "LightOffCommand.h"

LightOffCommand::LightOffCommand(Light light)
{
    this->light = light;
}
void LightOffCommand::execute()
{
    light.off();
}

void LightOffCommand::undoCommand()
{
    light.on();
}