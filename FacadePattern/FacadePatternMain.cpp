#include <iostream>
#include "HomeTheaterFacade.h"

void separator()
{
    for (int i = 0; i < 70; i++)
    {
        std::cout<<"-";
    }
    std::cout<<"\n";
}

int main()
{
    Amplifier mAmp;
    RadioTuner mRadiotuner;
    DVDPlayer mDvdPlayer;
    CDPlayer mCdPlayer;
    TheaterLights mTheaterLights;
    PopcornPopper mPopper;
    Projector mProjector;
    Screen mScreen;

    HomeTheaterFacade homeTheaterFacade
                (mAmp, mRadiotuner, mDvdPlayer, mCdPlayer, mTheaterLights, mPopper, mProjector, mScreen);

    homeTheaterFacade.watchMovie(std::string("Goodfellas"));
    separator();

    homeTheaterFacade.stopMovie();
    separator();

    homeTheaterFacade.listenToCd(std::string("Greatest hits of Queen"));
    separator();

    homeTheaterFacade.stopCD();
    separator();
    
    homeTheaterFacade.listenToBBCRadio();
    separator();

    homeTheaterFacade.stopRadio();

    std::cin.get();
    return 0;
}