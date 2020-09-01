#include "MacroCommand.h"

MacroCommand::MacroCommand(std::vector<ICommand*> savedCommands, std::string commandName)
    :savedCommands(savedCommands),commandName(commandName)
{}

MacroCommand::~MacroCommand()
{
    for (auto command : savedCommands)
    {
        delete command;
    }
    savedCommands.clear();
}

void MacroCommand::execute()
{
    for (auto command : savedCommands)
    {
        command->execute();
    }
}

void MacroCommand::undoCommand()
{
    for (auto command : savedCommands)
    {
        command->undoCommand();
    }
}