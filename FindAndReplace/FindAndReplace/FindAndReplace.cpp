// Replace.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include "Replace.h"


struct Args
{
    std::string searchString;
    std::string replaceString;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << "Invalid arguments count\n";
        std::cout << "Usage: Replace.exe <input file name> <output file name> <search string> <replace string>\n";
        return std::nullopt;
    }
    Args args;
    args.searchString = argv[1];
    args.replaceString = argv[2];
    return args;
}


int main(int argc, char* argv[])
{
    auto args = ParseArgs(argc, argv);
    if (!args)
    {
        return 1;
    }

    CopyReplaceString(args->searchString, args->replaceString);


    return 0;
}
