#define CATCH_CONFIG_MAIN
#include <iostream>
#include <sstream>
#include "../../catch2/catch.hpp"
#include "../FindAndReplace/Replace.h"

SCENARIO("replace empty string")
{
	std::string searchString = "";
	std::string str = "Hello, world";
	std::string replaceString = "sa";
	REQUIRE(ReplaceString("", str, replaceString) == str);
}

SCENARIO("replace non empty string")
{
	std::string searchString = "l";
	std::string str = "Hello, world\n";
	std::string replaceString = "mm";
	REQUIRE(ReplaceString("l", str, replaceString) == "Hemmmmo wormmd\n");
}

SCENARIO("replace string on duplicate substring")
{
	std::string searchString = "2345";
	std::string str = "12342345";
	std::string replaceString = "0 90";
	REQUIRE(ReplaceString("", str, replaceString) == str);
}
