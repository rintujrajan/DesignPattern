#pragma once

#include "ICommand.h"

class UploadSpeedCommand : public ICommand
{
private:
    int speed;

private:
    void execute() override;

public:
    UploadSpeedCommand(/* args */);
    ~UploadSpeedCommand();
    void setSpeed(int speed);
};
