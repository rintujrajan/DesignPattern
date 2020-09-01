#include "StereoOffCommand.h"
#include <iostream>

StereoOffCommand::StereoOffCommand(Stereo stereo)
{
    this->stereo = stereo;
}

void StereoOffCommand::execute()
{
    stereo.off();
    std::cout<<stereo;
}

void StereoOffCommand::undoCommand()
{
    stereo.playCD();
    std::cout<<stereo;
}