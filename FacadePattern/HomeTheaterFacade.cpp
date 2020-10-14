#include "HomeTheaterFacade.h"
#include <iostream>

HomeTheaterFacade::HomeTheaterFacade(Amplifier amp, RadioTuner radiotuner, DVDPlayer dvdPlayer, CDPlayer cdPlayer,
                                    TheaterLights lights, PopcornPopper popper, Projector projector, Screen screen)
{
    mAmp = amp;
    mRadiotuner = radiotuner;
    mDvdPlayer = dvdPlayer;
    mCdPlayer = cdPlayer;
    mTheaterLights = lights;
    mPopper = popper;
    mProjector = projector;
    mScreen = screen;
}

void HomeTheaterFacade::watchMovie(std::string& movie)
{
    std::cout<< "Get ready to watch the movie "<< movie << "...\n";
    mPopper.on();
    mPopper.pop();
    mTheaterLights.dim();
    mScreen.down();
    mProjector.on();
    mProjector.wideScreenMode();
    mDvdPlayer.on();
    mAmp.on();
    mAmp.setDvd(mDvdPlayer);
    mAmp.setSurroundSound();
    mAmp.setVolume(5);
    mDvdPlayer.play(movie);
}

void HomeTheaterFacade::stopMovie()
{
    std::cout<< "Shutting movie theater down...\n";
    mPopper.off();
    mTheaterLights.on();
    mScreen.up();
    mProjector.off();
    mAmp.off();
    mDvdPlayer.stop();
    mDvdPlayer.eject();
    mDvdPlayer.off();
}

void HomeTheaterFacade::listenToCd(std::string& title)
{
    std::cout<< "Get ready to listen to "<< title << "...\n";
    mCdPlayer.on();
    mAmp.on();
    mAmp.setCd(mCdPlayer);
    mAmp.setVolume(5);
    mCdPlayer.play(title);
} 

void HomeTheaterFacade::stopCD()
{
    std::cout<< "Shutting music playing down...\n";
    mCdPlayer.off();
    mAmp.off();
}

void HomeTheaterFacade::listenToBBCRadio()
{
    std::cout<< "Tuning in to listen to BBC Radio...\n";
    mRadiotuner.on();
    mRadiotuner.setFM();
    mRadiotuner.setFrequency(1245);
    std::cout<<mRadiotuner;
}  

void HomeTheaterFacade::stopRadio()
{
    std::cout<< "Turning off Radio...\n";
    mRadiotuner.off();
}