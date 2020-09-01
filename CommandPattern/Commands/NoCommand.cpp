#include "NoCommand.h"
#include <iostream>

void NoCommand::execute()
{
    std::cout<<"No command to execute!\n";
}

void NoCommand::undoCommand()
{
    std::cout<<"No command to undo!\n";
}