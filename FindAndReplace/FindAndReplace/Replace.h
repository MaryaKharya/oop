#pragma once

#include <iosfwd>
#include <optional>
#include <string>

std::string ReplaceString(const std::string& searchString, const std::string& str, const std::string& replaceString);
void CopyReplaceString(const std::string& searchString, const std::string& replaceString);