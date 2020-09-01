#include "CeilingFanOnCommand.h"
#include <iostream>

CeilingFanOnCommand::CeilingFanOnCommand(CeilingFan ceilingFan)
{
    this->ceilingFan = ceilingFan;
}
void CeilingFanOnCommand::execute()
{
    ceilingFan.medium();
    std::cout<<ceilingFan;
}
void CeilingFanOnCommand::undoCommand()
{
    ceilingFan.off();
    std::cout<<ceilingFan;
}