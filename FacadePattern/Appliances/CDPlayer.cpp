#include "CDPlayer.h"
#include <iostream>

void CDPlayer::on()
{
    std::cout<<"CD Player on\n";
}

void CDPlayer::off()
{
    std::cout<<"CD Player off\n";
}

void CDPlayer::eject()
{
    std::cout<<"CD Player ejected\n";
}

void CDPlayer::pause()
{
    std::cout<<"CD Player paused\n";
}

void CDPlayer::play(std::string& title)
{
    std::cout<<"CD Player playing "<< title <<"\n";
}

void CDPlayer::stop()
{
    std::cout<<"CD Player stopped\n";
}
