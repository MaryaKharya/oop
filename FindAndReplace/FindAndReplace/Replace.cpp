#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include "Replace.h"

std::string ReplaceString(const std::string& searchString, const std::string& str, const std::string& replaceString)
{
    std::string strCopy;
    std::string::size_type position = 0;
    std::string::size_type positionSearchStr;
    if (!searchString.empty())
    {
        while ((positionSearchStr = str.find(searchString, position)) != std::string::npos)
        {
            strCopy.append(str, position, positionSearchStr - position).append(replaceString);
            position = positionSearchStr + searchString.length();
        }
    }
    strCopy.append(str, position);
    return strCopy;
}

void CopyReplaceString(const std::string& searchString, const std::string& replaceString)
{
    std::string str;
    while (getline(std::cin, str))
    {
        std::cout << ReplaceString(searchString, str, replaceString) << "\n";
    }
}