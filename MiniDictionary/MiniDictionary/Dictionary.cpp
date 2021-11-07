#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <map>
#include <algorithm>
#include <Windows.h>
#include "../MiniDictionary/Dictionary.h"

using namespace std;


std::map<std::string, std::string> LoadDictionary(const std::string& inFileName)
{
    fstream input(inFileName);
    std::string key, value, str;
    std::map<std::string, std::string> dictionary;
    if (input.is_open())
    {
        while (getline(input, str))
        {
            key.append(str, 0, str.find("  "));
            value.append(str, str.find("  ") + 2);
            dictionary.emplace(key, value);
            key.clear();
            value.clear();
        }
        input.close();
    }
    return dictionary;
}

std::string FinishWorkDictionary(const string& outFileName, const map<string, string>& dictionary)
{
    std::string closingWord;
    getline(cin, closingWord);
    if ((closingWord == "Y") || (closingWord == "y"))
    {
        ofstream output(outFileName);
        if (!output.is_open())
        {
            return "��������� �� ���������. ���������� ������� ���� " + outFileName + "\n";
        }
        SaveDictionaryToFile(dictionary, output);
        return "��������� ���������. �� ��������.\n";
    }
    return "��������� �� ���������. �� ��������.\n";
}

void SaveDictionaryToFile(const map<string, string>& dictionary, ostream& output)
{
    std::map<std::string, std::string>::const_iterator word;
    for (word = dictionary.begin(); word != dictionary.end(); word++)
    {
        output << word->first << "  " << word->second << "\n";
    }
}

std::string AddWord(map<string, string>& dictionary, const string& englWord)
{
    string translation;
    getline(cin, translation);
    if (translation.empty())
    {
        return "����� �" + englWord + "� ���������������.\n";
    }
    dictionary[englWord] = translation;
    return "����� �" + englWord + "� ��������� � ������� ��� �" + translation + "�.\n";
}

void WriteTranslation(map<string, string>& dictionary, const string& englWord)
{
    if (dictionary.find(englWord) != dictionary.end())
    {
        cout << dictionary[englWord] << "\n";
    }
    else
    {
        cout << "����������� ����� �" << englWord << "�. ������� ������� ��� ������ ������ ��� ������.\n";
        cout << AddWord(dictionary, englWord);
    }
}

void CheckChangesAndFinishWork(size_t sizeMap, const std::map<std::string, std::string>& dictionary, const std::string& fileName)
{
    std::string closingWord;
    if (sizeMap < dictionary.size())
    {
        cout << "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������.\n";
        cout << FinishWorkDictionary(fileName, dictionary);
    }
    else
    {
        cout << "��� ��������� ��� ���������� � �������. �� ����� ������!\n";
    }
}