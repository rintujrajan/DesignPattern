#include "UploadSpeedCommand.h"
#include <iostream>

UploadSpeedCommand::UploadSpeedCommand(/* args */)
{
}

UploadSpeedCommand::~UploadSpeedCommand()
{
}

void UploadSpeedCommand::setSpeed(int speed)
{
    this->speed = speed;
}

void UploadSpeedCommand::execute()
{
    std::cout << "Uploaded speed : " << speed << "\n";
}