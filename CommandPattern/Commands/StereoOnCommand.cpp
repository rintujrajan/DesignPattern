#include "StereoOnCommand.h"
#include <iostream>

StereoOnCommand::StereoOnCommand(Stereo stereo)
{
    this->stereo = stereo;
}

void StereoOnCommand::execute()
{
    stereo.playCD();
    std::cout<<stereo;
}

void StereoOnCommand::undoCommand()
{
    stereo.off();
    std::cout<<stereo;
}