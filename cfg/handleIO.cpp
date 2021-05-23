#include <iostream>
#include <set>
#include <map>
#include <cctype>
#include <vector>

#include "cfg.h"

// Input

void handleSetString(const std::string& rawStr, Set& _Set) {
	for (auto ch : rawStr) {
		if (isalpha(ch)) {
			_Set.insert(ch);
		}
	}
}

void handleExpression(const std::string& rawStr, PMap & _Map) {
	char x = rawStr[0];
	for (size_t i = 1;i < rawStr.length();i++) {
		char ch = rawStr[i];
		if (isalpha(ch) || ch == '#') {
			size_t j;
			for (j = i;j < rawStr.length();j++) {
				ch = rawStr[j];
				if (!(isalpha(ch) || ch == '#')) {
					break;
				}
			}
			_Map[x].insert(rawStr.substr(i, j - i));
			i = j;
		}
	}
}

// Output

void printSet(const Set& _Set) {
	std::cout << "{";
	for (Set::iterator it = _Set.begin();it != _Set.end();it++) {
		if (it != _Set.begin()) {
			std::cout << ", ";
		}
		std::cout << *it;
	}
	std::cout << "}" << std::endl;
}

void printExpressions(PMap & _Map) {
	for (PMap::iterator it = _Map.begin();it != _Map.end();it++) {
		std::cout << it->first << " -> ";
		for (PSet::iterator jt = it->second.begin();jt != it->second.end();jt++) {
			if (jt != it->second.begin()) {
				std::cout << " | ";
			}
			std::cout << *jt;
		}
		std::cout << std::endl;
	}
}