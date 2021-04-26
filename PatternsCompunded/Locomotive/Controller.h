#pragma once

#include <queue>
#include <memory>
class ICommand;
class Controller
{
private:
    std::queue<std::unique_ptr<ICommand>> commandsQueue;
    static Controller controllerInstance;
    bool continueLoop;

private:
    Controller();

public:
    void executeQueuedCommands();
    static Controller &getControllerInstance();
    void addCommandToBeExecuted(std::unique_ptr<ICommand> command);
    void stopLoop();
};
