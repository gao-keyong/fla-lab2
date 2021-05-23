#pragma once

#include <iostream>
#include <set>
#include <map>
#include <vector>

typedef std::string Pattern; // æ‰–Õ

// Input
void handleSetString(const std::string&, std::set<char>&);
void handleExpression(const std::string&, std::map<char, std::vector<Pattern>>&);

// Output
void printSet(const std::set<char>&);
void printExpressions(std::map<char, std::vector<Pattern>>&);