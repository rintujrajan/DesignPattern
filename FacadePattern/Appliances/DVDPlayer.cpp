#include "DVDPlayer.h"
#include <iostream>

void DVDPlayer::on()
{
    std::cout<<"DVD Player on\n";
}

void DVDPlayer::off()
{
    std::cout<<"DVD Player off\n";
}

void DVDPlayer::eject()
{
    std::cout<<"DVD Player ejected\n";
}

void DVDPlayer::pause()
{
    std::cout<<"DVD Player paused\n";
}

void DVDPlayer::play(std::string& movie)
{
    std::cout<<"DVD Player playing "<< movie <<"\n";
}

void DVDPlayer::stop()
{
    std::cout<<"DVD Player stopped\n";
}

void DVDPlayer::setSurroundAudio()
{
    std::cout<<"DVD Player playing surround sound on (5 speakers, 1 subwoofer)\n";
}

void DVDPlayer::setTwoChannelAudio()
{
    std::cout<<"DVD Player playing sound via Two Channels(2 speakers)\n";
}