#include "Controller.h"
#include "Commands/ICommand.h"
#include <thread>
#include <chrono>

Controller Controller::controllerInstance;

Controller::Controller() : continueLoop(true) {}

Controller &Controller::getControllerInstance()
{
    return controllerInstance;
}

void Controller::executeQueuedCommands()
{
    while (continueLoop)
    {
        while (!commandsQueue.empty())
        {
            commandsQueue.front()->execute();
            commandsQueue.pop();
        }
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}

void Controller::addCommandToBeExecuted(std::unique_ptr<ICommand> command)
{
    commandsQueue.push(std::move(command));
}

void Controller::stopLoop()
{
    continueLoop = false;
}