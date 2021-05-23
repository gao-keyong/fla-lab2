#include <iostream>
#include <set>
#include <map>
#include <cctype>
#include <vector>

typedef std::string Pattern; // æ‰–Õ

// Input

void handleSetString(const std::string& rawStr, std::set<char>& _Set) {
	for (auto ch : rawStr) {
		if (isalpha(ch)) {
			_Set.insert(ch);
		}
	}
}

void handleExpression(const std::string& rawStr, std::map<char, std::vector<Pattern>>& _Map) {
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
			_Map[x].push_back(rawStr.substr(i, j - i));
			i = j;
		}
	}
}

// Output

void printSet(const std::set<char>& _Set) {
	std::cout << "{";
	for (std::set<char>::iterator it = _Set.begin();it != _Set.end();it++) {
		if (it != _Set.begin()) {
			std::cout << ", ";
		}
		std::cout << *it;
	}
	std::cout << "}" << std::endl;
}

void printExpressions(std::map<char, std::vector<Pattern>>& _Map) {
	for (std::map<char, std::vector<Pattern>>::iterator it = _Map.begin();it != _Map.end();it++) {
		std::cout << it->first << " -> ";
		for (std::vector<Pattern>::iterator jt = it->second.begin();jt != it->second.end();jt++) {
			if (jt != it->second.begin()) {
				std::cout << " | ";
			}
			std::cout << *jt;
		}
		std::cout << std::endl;
	}
}