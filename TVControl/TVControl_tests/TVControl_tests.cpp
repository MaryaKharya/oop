// TVControl_tests.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>
#include <map>
#include "../../catch2/catch.hpp"
#include "../TVControl/CTVSet.h"
#include "../TVControl/Control.h"
#include <assert.h>

using namespace std;

SCENARIO("creat TV")
{
	CTVSet tv;
	CHECK(tv.GetTurnStatus() == false);
	CHECK(tv.GetChannel() == 0);
}

SCENARIO("first turn on TV")
{
	CTVSet tv;
	tv.TurnOn();
	CHECK(tv.GetTurnStatus() == true);
	CHECK(tv.GetChannel() == 1);
}

SCENARIO("turn off TV")
{
	CTVSet tv;
	tv.TurnOn();
	tv.TurnOff();
	CHECK(tv.GetTurnStatus() == false);
	CHECK(tv.GetChannel() == 0);
}

SCENARIO("select channel with TV off")
{
	CTVSet tv;
	tv.SelectChannel(3);
	CHECK(tv.GetChannel() == 0);
}

SCENARIO("select channel with TV on")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectChannel(3);
	CHECK(tv.GetChannel() == 3);
	tv.SelectChannel(1);
	CHECK(tv.GetChannel() == 1);
	tv.SelectChannel(99);
	CHECK(tv.GetChannel() == 99);
	tv.SelectChannel(100);
	CHECK(tv.GetChannel() == 99);
	tv.SelectChannel(0);
	CHECK(tv.GetChannel() == 99);
}

SCENARIO("select previous channel with TV off")
{
	CTVSet tv;
	tv.SelectChannel(3);
	tv.SelectPreviousChannel();
	CHECK(tv.GetChannel() == 0);
}

SCENARIO("select previous channel with TV on")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectChannel(3);
	tv.SelectChannel(99);
	tv.SelectPreviousChannel();
	CHECK(tv.GetChannel() == 3);
	tv.SelectPreviousChannel();
	CHECK(tv.GetChannel() == 99);
	tv.SelectPreviousChannel();
	CHECK(tv.GetChannel() == 3);
}

SCENARIO("get channel number")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectChannel(80);
	tv.TurnOff();
	CHECK(tv.GetChannel() == 0);
	tv.TurnOn();
	CHECK(tv.GetChannel() == 80);
}

SCENARIO("get channel number with select previous channel")
{
	CTVSet tv;
	tv.TurnOn();
	tv.SelectPreviousChannel();
	tv.TurnOff();
	CHECK(tv.GetChannel() == 0);
	tv.TurnOn();
	CHECK(tv.GetChannel() == 1);
}

/*SCENARIO("set channel name with TV on")
{
	CTVSet tv;
	tv.SetChannelName(26, "Disney");
	CHECK(tv.GetChannel() == 0);
}*/

SCENARIO("control TV")
{
	CTVSet tv;
	WHEN("enter TurnOn")
	{
		std::string str = "TurnOn";
		THEN("TV turns on")
		{
			CHECK(ControlTV(str, tv) == "TV is on\n");
		}
	}
	WHEN("enter TurnOff")
	{
		std::string str = "TurnOff";
		THEN("TV turns off")
		{
			CHECK(ControlTV(str, tv) == "TV is off\n");
		}
	}
	WHEN("enter Info when TV is off")
	{
		std::string str = "Info";
		THEN("TV is off")
		{
			CHECK(ControlTV(str, tv) == "TV is off\n");
		}
	}
	WHEN("enter Info when TV is on")
	{
		tv.TurnOn();
		std::string str = "Info";
		THEN("TV is on and channel number is 1")
		{
			CHECK(ControlTV(str, tv) == "TV is on\nChannel number is 1\n");
		}
	}

	WHEN("enter SelectChannel 3 when TV is off")
	{
		std::string str = "SelectChannel 3";
		THEN("TV is off")
		{
			CHECK(ControlTV(str, tv) == "TV is off\n");
		}
	}

	WHEN("enter SelectChannel 3ji when TV is off")
	{
		std::string str = "SelectChannel 3ji";
		THEN("Channel number contains invalid characters")
		{
			CHECK(ControlTV(str, tv) == "Channel number contains invalid characters\n");
		}
	}

	WHEN("enter some unknown command")
	{
		std::string str = "Select 3";
		THEN("the program report an invalid command")
		{
			CHECK(ControlTV(str, tv) == "Command is not recognized\n");
		}
	}

	WHEN("select previous channel with 1 channel")
	{
		tv.TurnOn();
		std::string str = "SelectPreviousChannel";
		THEN("channel number is 1")
		{
			CHECK(ControlTV(str, tv) == "Channel number is 1\n");
		}
	}
}

SCENARIO("convert number to string")
{
	CTVSet tv;
	WHEN("select channel without digits")
	{
		std::string str = "SelectChannel";
		THEN("channel number is -1")
		{
			CHECK(IntToString(str) == -1);
		}
	}
	WHEN("select channel with digit and letters")
	{
		std::string str = "SelectChannel 5t";
		THEN("channel number is -1")
		{
			CHECK(IntToString(str) == -1);
		}
	}

	WHEN("select channel with digits")
	{
		std::string str = "SelectChannel 112";
		THEN("channel number is 122")
		{
			CHECK(IntToString(str) == 112);
		}
	}
}


