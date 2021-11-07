#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include "../TVControl/CTVSet.h"
#include "Control.h"

using namespace std;

TVControl::TVControl(istream& input, ostream& output, CTVSet& tv)
    : m_tv(tv)
    , m_input(input)
    , m_output(output)
{
}

void TVControl::ProcessCommand()
{
    std::string command;
    getline(m_input, command);
    if (command == "TurnOn")
    {
        TurnOn();
        return;
    }
    if (command == "TurnOff")
    {
        TurnOff();
        return;
    }
    if (command == "Info")
    {
        GetInfo();
        return;
    }
    if (command == "SelectPreviousChannel")
    {
        SelectPreviousChannel();
        return;
    }
    if (command.find("SelectChannel") != string::npos)
    {
        SelectChannel(command);
        return;
    }
     m_output << "Command is not recognized\n";
}
void TVControl::TurnOn()
{
    m_tv.TurnOn();
    m_output << "TV is on\n";
}

void TVControl::TurnOff()
{
    m_tv.TurnOff();
    m_output << "TV is off\n";
}

void TVControl::GetInfo()
{
    if (m_tv.GetTurnStatus())
    {
        m_output << "TV is on\nChannel number is " << m_tv.GetChannel() << "\n";
    }
    else
    {
        m_output << "TV is off\n";
    }
}

void TVControl::SelectPreviousChannel()
{
    m_tv.SelectPreviousChannel();
    if (m_tv.GetTurnStatus())
    {
        m_output << "Channel number is " << m_tv.GetChannel() << "\n";
        return;
    }
    m_output << "TV is off\n";
}

void TVControl::SelectChannel(std::string& command)
{
    int channel = IntToString(command);
    if (channel == -1)
    {
        m_output << "Channel number contains invalid characters\n";
        return;
    }
    m_tv.SelectChannel(channel);
    if (m_tv.GetTurnStatus())
    {
        m_output << "Channel number is " << m_tv.GetChannel() << "\n";
        return;
    }
    m_output << "TV is off\n";
}


int TVControl::IntToString(const std::string& str)
{
    int channel = 0;
    std::string digits = "0123456789";
    for (size_t i = str.find(" ") + 1; i < str.length(); i++)
    {
        if ((str[i] < '0') || (str[i] > '9'))
        {
            return -1;
        }
        channel = channel * 10 + digits.find(str[i]);
    }
    return channel;
}
/*std::string ControlTV(const std::string& command, CTVSet& tv)
{
    if (command == "TurnOn")
    {
        return TurnOnTv(tv);
    }
    if (command == "TurnOff")
    {
        return TurnOffTv(tv);
    }
    if (command == "Info")
    {
        return GetInfoTv(tv);
    }
    if (command == "SelectPreviousChannel")
    {
        return SelectPreviousChannelOnTv(tv);
    }
    if (command.find("SelectChannel") != string::npos)
    {
        return SelectChannelOnTv(command, tv);
    }
    return "Command is not recognized\n";
}

std::string TurnOnTv(CTVSet& tv)
{
    tv.TurnOn();
    return "TV is on\n";
}

std::string TurnOffTv(CTVSet& tv)
{
    tv.TurnOff();
    return "TV is off\n";
}

std::string GetInfoTv(CTVSet& tv)
{
    if (tv.GetTurnStatus())
    {
        return "TV is on\nChannel number is " + to_string(tv.GetChannel()) + "\n";
    }
    return "TV is off\n";
}

std::string SelectPreviousChannelOnTv(CTVSet& tv)
{
    tv.SelectPreviousChannel();
    if (tv.GetTurnStatus())
    {
        return"Channel number is " + to_string(tv.GetChannel()) + "\n";
    }
    return "TV is off\n";
}

std::string SelectChannelOnTv(const std::string& command, CTVSet& tv)
{
    int channel = IntToString(command);
    if (channel == -1)
    {
        return "Channel number contains invalid characters\n";
    }
    tv.SelectChannel(channel);
    if (tv.GetTurnStatus())
    {
        return"Channel number is " + to_string(tv.GetChannel()) + "\n";
    }
    return "TV is off\n";
}

int IntToString(const std::string& str)
{
    int channel = 0;
    std::string digits = "0123456789";
    for (size_t i = str.find(" ") + 1; i < str.length(); i++)
    {
        if ((str[i] < '0') || (str[i] > '9'))
        {
            return -1;
        }
        channel = channel * 10 + digits.find(str[i]);
    }
    return channel;
}*/