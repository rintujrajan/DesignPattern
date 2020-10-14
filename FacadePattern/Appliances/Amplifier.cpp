#include "Amplifier.h"
#include <iostream>

Amplifier::Amplifier():isDvDPlayerSet(false)
{}

void Amplifier::Amplifier::on()
{
    std::cout<<"Amplifier on\n";
}

void Amplifier::Amplifier::off()
{
    std::cout<<"Amplifier off\n";
}

void Amplifier::setCd(CDPlayer& cdPlayer)
{
    mCdPlayer = cdPlayer;
}

void Amplifier::setDvd(DVDPlayer& dvdPlayer)
{
    mDvdPlayer = dvdPlayer;
    isDvDPlayerSet = true;
}

void Amplifier::setStereoSound()
{
    if(isDvDPlayerSet)
    {
        mDvdPlayer.setTwoChannelAudio();
    }
    else
    {
        std::cout<<"Could not set stereo sound as DVD player is not set\n";
    }
}

void Amplifier::setSurroundSound()
{
    if(isDvDPlayerSet)
    {
        mDvdPlayer.setSurroundAudio();
    }
    else
    {
        std::cout<<"Could not set surround sound as DVD player is not set\n";
    }
}

void Amplifier::setTuner(RadioTuner& radioTuner)
{
    mRadioTuner = radioTuner;
}

void Amplifier::setVolume(int volume)
{
    std::cout<<"Setting volume to "<<volume<<"\n";
}