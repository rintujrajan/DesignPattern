#include "Light.h"
#include <iostream>

Light::Light(const std::string &name)
{
    this->name = name;
}
void Light::on()
{
    std::cout<< name <<" light On\n";
}
void Light::off()
{
    std::cout<< name <<" light Off\n";
}
