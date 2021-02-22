// Replace.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include "Replace.h"


struct Args
{
    std::string inputFileName;
    std::string outputFileName;
    std::string searchString;
    std::string replaceString;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
    if (argc != 5)
    {
        std::cout << "Invalid arguments count\n";
        std::cout << "Usage: Replace.exe <input file name> <output file name> <search string> <replace string>\n";
        return std::nullopt;
    }
    Args args;
    args.inputFileName = argv[1];
    args.outputFileName = argv[2];
    args.searchString = argv[3];
    args.replaceString = argv[4];
    return args;
}


void ReplaceString(std::optional<Args>& args, std::fstream& input, std::ofstream& output)
{
    std::string str;
    while (getline(input, str))
    {
        int count = 0;
        if (args -> searchString != "")
        {
            while (str.find(args -> searchString, count) != std::string::npos)
            {
                str.replace(str.find(args -> searchString, count), args -> searchString.length(), args -> replaceString);
                count = str.find(args -> replaceString, count) + args -> replaceString.length();

            }
        }
        output << str << "\n";
    }
}

int main(int argc, char* argv[])
{
    auto args = ParseArgs(argc, argv);
    if (!args)
    {
        return 1;
    }

    std::fstream input;
    input.open(args -> inputFileName);
    if (!input.is_open()) 
    {
        std::cout << "Failed to open " << args->inputFileName << " for reading\n";
        return 1;
    }

    std::ofstream output;
    output.open(args -> outputFileName);
    if (!output.is_open())
    {
        std::cout << "Failed to open " << args->outputFileName << " for writing\n";
        return 1;
    }

    ReplaceString(args, input, output);


    if (input.bad())
    {
        std::cout << "Failed to read data from input file\n";
        return 1;
    }

    if (!output.flush())
    {
        std::cout << "failed to write data to output file\n";
        return 1;
    }
    return 0;
}

