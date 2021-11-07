// TVControl.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include "../TVControl/CTVSet.h"
#include "../TVControl/Control.h"
#include "Control.h"

using namespace std;


int main()
{
    CTVSet tv;
    std::string str;
    TVControl remoteControl(cin, cout, tv);
    while (!cin.eof() && !cin.fail())
    {
        remoteControl.ProcessCommand();
    }
}


