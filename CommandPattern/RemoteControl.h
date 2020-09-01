#pragma once
#include "Commands\ICommand.h"

class RemoteControl
{
private:
    ICommand* onCommand[10];
    ICommand* offCommand[10];
    ICommand *lastExecutedCommand;
    RemoteControl(const RemoteControl&) = delete;
    RemoteControl& operator=(const RemoteControl&) = delete;
    RemoteControl(RemoteControl&&) = delete;
    RemoteControl& operator=(RemoteControl&&) = delete;
public:
    RemoteControl();
    ~RemoteControl();
    void setCommand(int slot ,ICommand* onCommand, ICommand* offComand);
    void onButtonPushed(int slot);
    void offButtonPushed(int slot);
    void undo();
    friend std::ostream& operator<<(std::ostream& out, const RemoteControl& rc);
};