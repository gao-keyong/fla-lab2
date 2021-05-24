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

void printExpressions(const PMap & _Map) {
	for (auto pMap:_Map) {
		std::cout << pMap.first << " -> ";
		for (PSet::iterator it = pMap.second.begin();it != pMap.second.end();it++) {
			if (it != pMap.second.begin()) {
				std::cout << " | ";
			}
			std::cout << *it;
		}
		std::cout << std::endl;
	}
}

void printCFG(const CFG& cfg) {
	std::cout << "N = ";
	printSet(cfg.N);

	std::cout << "T = ";
	printSet(cfg.T);

	std::cout << "P:" << std::endl;
	printExpressions(cfg.P);
	std::cout <<"S: "<< cfg.S << std::endl;
}