#pragma once

void CopyStreams(std::fstream& input, std::ofstream& output);

void ReplaceString(char* argv[], std::fstream& input, std::ofstream& output);

void ReplaceString(std::string& searchString, std::string& str, size_t& position, std::string& strCopy, std::string& replaceString);
