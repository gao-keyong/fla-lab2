#pragma once

#include <iostream>
#include <set>
#include <map>
#include <vector>

#include "cfg.h"

// Input
void handleSetString(const std::string&, Set&);
void handleExpression(const std::string&, PMap&);

// Output
void printSet(const Set&);
void printExpressions(PMap&);