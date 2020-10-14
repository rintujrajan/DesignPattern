#include <iostream>
#include "Projector.h"

void Projector::on()
{
    std::cout<<"Projector on\n";
}

void Projector::off()
{
    std::cout<<"Projector off\n";
}

void Projector::tvMode()
{
    std::cout<<"Projector in TV mode (4x3 aspect ratio)\n";
}

void Projector::wideScreenMode()
{
    std::cout<<"Projector in widescreen mode (16x9 aspect ratio)\n";
}