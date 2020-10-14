#pragma once
#include "RadioTuner.h"
#include "DVDPlayer.h"
#include "CDPlayer.h"

class Amplifier
{
private:
    RadioTuner mRadioTuner;
    DVDPlayer mDvdPlayer;
    CDPlayer mCdPlayer;
    bool isDvDPlayerSet;

public:
    Amplifier();
    void on();
    void off();
    void setCd(CDPlayer& cdPlayer);
    void setDvd(DVDPlayer& dvdPlayer);
    void setStereoSound();
    void setSurroundSound();
    void setTuner(RadioTuner& radioTuner);
    void setVolume(int volume);
};

