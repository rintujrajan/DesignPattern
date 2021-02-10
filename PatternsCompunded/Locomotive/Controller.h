#pragma once

#include <queue>
#include <memory>
class ICommand;
class Controller
{
private:
    std::queue<std::unique_ptr<ICommand>> commandsQueue;
    static Controller controllerInstance;

private:
    Controller() = default;

public:
    void executeQueuedCommands();
    static Controller &getControllerInstance();
    void addCommandToBeExecuted(std::unique_ptr<ICommand> command);
};
