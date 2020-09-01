#include "CeilingFanOffCommand.h"
#include <iostream>

CeilingFanOffCommand::CeilingFanOffCommand(CeilingFan ceilingFan)
{
    this->ceilingFan = ceilingFan;
}
void CeilingFanOffCommand::execute()
{
    ceilingFan.off();
    std::cout<<ceilingFan;
}
void CeilingFanOffCommand::undoCommand()
{
    ceilingFan.medium();
    std::cout<<ceilingFan;
}