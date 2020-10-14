#pragma once
#include "Appliances/Amplifier.h"
#include "Appliances/RadioTuner.h"
#include "Appliances/DvdPlayer.h"
#include "Appliances/CdPlayer.h"
#include "Appliances/TheaterLights.h"
#include "Appliances/PopcornPopper.h"
#include "Appliances/Projector.h"
#include "Appliances/Screen.h"


class HomeTheaterFacade
{
private:
    Amplifier mAmp;
    RadioTuner mRadiotuner;
    DVDPlayer mDvdPlayer;
    CDPlayer mCdPlayer;
    TheaterLights mTheaterLights;
    PopcornPopper mPopper;
    Projector mProjector;
    Screen mScreen;
public:
    HomeTheaterFacade(Amplifier amp, RadioTuner radiotuner, DVDPlayer dvdPlayer, CDPlayer cdPlayer,
                      TheaterLights lights, PopcornPopper popper, Projector projector, Screen screen);

    void watchMovie(std::string& movie);  
    void stopMovie();
    void listenToCd(std::string& title); 
    void stopCD();  
    void listenToBBCRadio();   
    void stopRadio();            
};

