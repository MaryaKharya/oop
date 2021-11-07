// Replace.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <math.h>
#include <limits.h>
#include <cctype>


struct Args
{
    std::string sourceNotation;
    std::string destinationNotation;
    std::string value;
};

struct Error
{
    bool err;
    std::string message;
};

std::optional<Args> ParseArgs(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cout << "Invalid arguments count\n";
        std::cout << "Usage: radix.exe <source notation> <destination notation> <value>\n";
        return std::nullopt;
    }
    Args args;
    args.sourceNotation = argv[1];
    args.destinationNotation = argv[2];
    args.value = argv[3];
    return args;
};

int StringToInt(const std::string& str, int radix, Error& error)
{
    double i = static_cast<double>(str.size());
    int minus = 0;
    int number = 0;
    std::string symbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (str[0] == '-')
    {
        minus = 1;
    }
    for (int l = minus; l < str.size(); l++)
    {
        char ch = str[l];
        --i;
        std::string::size_type indexSymbol = symbols.find(ch);
        if (indexSymbol != std::string::npos)
        {
            if (indexSymbol >= radix)
            {
                error.message = "<value> contains characters that are not related to <sourceNotation> number system\n";
                error.err = false;
                break;
            }
            if (ch != '0')
            {
                if ((minus == 1) && ((pow(-(INT_MIN - number) / symbols.find(ch), 1 / i) >= radix) || ((i == 0) && -(INT_MIN - number) >= indexSymbol)))
                {
                    number += static_cast<int>(-(indexSymbol * pow(radix, i)));
                }
                else if ((minus == 0) && (((i != 0) && (pow((INT_MAX - number) / indexSymbol, 1 / i) >= radix)) || ((i == 0) && ((INT_MAX - number) >= indexSymbol))))
                {
                    number += static_cast<int>(indexSymbol * pow(radix, i));
                }
                else
                {
                    error.err = false;
                    error.message = "Error: overflow\n";
                    break;
                }
            }
        }
        else
        {
            error.message = "Invalid characters are present in <value> argument\n";
            error.err = false;
            break;
        }
    }
    return number;
}

std::string IntToString(int n, int radix, Error& error)
{
    std::string str;
    std::string symbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int rt = 0;
    if (n == 0)
    {
        str = "0";
    }
    while (n != 0)
    {
        rt = n % radix;
        n = n / radix;
        if (rt < 0)
        {
            str = symbols[-rt] + str;
        }
        else
        {
            str = symbols[rt] + str;
        }
    }
    return str;
};

int RadixStringToInt(const std::string& strRadix, bool& wasError)
{
    int radix = 0;
    for (auto ch : strRadix)
    {
        if (isdigit(ch))
        {
            radix = radix * 10 + (ch - '0');
        }
        else
        {
            wasError = false;
            break;
        }
    }
    if ((radix < 2) || ((radix > 36)))
    {
        wasError = false;
    }
    return radix;
}


int main(int argc, char* argv[])
{
    auto args = ParseArgs(argc, argv);
    if (!args)
    {
        return 1;
    }
    Error error;
    std::string numberString;
    int sourceNotation;
    int destinationNotation;
    if ((args->sourceNotation.empty()) || (args->destinationNotation.empty()) || (args->value.empty()))
    {
        std::cout << "There is an empty argument\n";
        return 1;
    }

    sourceNotation = RadixStringToInt(args->sourceNotation, error.err);
    if (!error.err)
    {
        std::cout << "Incorrect entry of the first argument\n";
        return 1;
    }

    destinationNotation = RadixStringToInt(args->destinationNotation, error.err);
    if (!error.err)
    {
        std::cout << "Incorrect entry of the second argument\n";
        return 1;
    }

    int number;
    number = StringToInt(args->value, sourceNotation, error);
     
    if (!error.err)
    {
        std::cout << error.message << "\n";
        return 1;
    }

    numberString = IntToString(number, destinationNotation, error);
    if (args->value[0] == '-')
    {
        numberString = "-" + numberString;
    }
    std::cout << numberString << '\n';
}

