#include "RemoteControl.h"
#include "Commands\NoCommand.h"
#include <iostream>
#include <iomanip>

RemoteControl::RemoteControl()
{
    ICommand *noCommand = new NoCommand();
    for (int i = 0; i < 10; i++)
    {
        onCommand[i] = noCommand;
        offCommand[i] = noCommand;
    }  
    lastExecutedCommand = noCommand;  
}

RemoteControl::~RemoteControl()
{
   for (int i = 0; i < 10; i++)
    { 
        delete onCommand[i];
        delete offCommand[i];
    }
}

void RemoteControl::setCommand(int slot ,ICommand* onCommand, ICommand* offCommand)
{
    this->onCommand[slot] = onCommand;
    this->offCommand[slot] = offCommand;
    std::cout<<"New On and Off commands added for slot "<< slot << "\n";
    std::cout<<*this;
}

void RemoteControl::onButtonPushed(int slot)
{
    std::cout<<"-----Button On pushed on slot "<< slot << "-----\n";
    this->onCommand[slot]->execute();
    lastExecutedCommand = this->onCommand[slot];
}

void RemoteControl::offButtonPushed(int slot)
{
    std::cout<<"-----Button Off pushed on slot "<< slot << "-----\n";
    this->offCommand[slot]->execute();
    lastExecutedCommand = this->offCommand[slot];
}

void RemoteControl::undo()
{
    std::cout<<"-----Undo last executed command-----\n";
    lastExecutedCommand->undoCommand();
}

std::ostream& operator<<(std::ostream& out, const RemoteControl& rc)
{
    out<<std::left;
    out<<"---------------------------------------------------------------------------\n";
    out<<"Current Remote Control settings:\n";
    out<<std::setw(10)<<"Slot "
        <<std::setw(40)<<"On Command"
        <<std::setw(40)<<"Off Command"<<"\n";
    out<<"---------------------------------------------------------------------------\n";
    std::string onCommandObjectName = std::string();
    std::string offCommandObjectName = std::string();
    for (int i = 0; i < 10; i++)
    {
        onCommandObjectName = rc.onCommand[i]->getCommandObject();
        offCommandObjectName = rc.offCommand[i]->getCommandObject();
        out<<std::setw(10)<<i
            <<std::setw(40)<<rc.onCommand[i]->getName()+ ((onCommandObjectName != "")? "(" + onCommandObjectName + ")" :"" )
            <<std::setw(40)<<rc.offCommand[i]->getName()+ ((offCommandObjectName != "")? "(" + offCommandObjectName + ")" :"" )<<"\n";
        out<<"---------------------------------------------------------------------------\n";
    } 
    return out;
}