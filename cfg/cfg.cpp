#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include "handleIO.h"

typedef std::string Pattern; // 句型

std::set<char> N;                       // 非终结符
std::set<char> T;                       // 终结符
std::map<char, std::vector<Pattern>> P; // 生成式的集合
char S;

int main(int argc, char const* argv[])
{
	std::cout << "G = (N, T, P, S)" << std::endl;

	std::cout << "N = {";
	std::string string_N;
	std::getline(std::cin, string_N);
	handleSetString(string_N, N);

	std::cout << "T = {";
	std::string string_T;
	std::getline(std::cin, string_T);
	handleSetString(string_T, T);

	std::cout << "P: (space to end)" << std::endl;
	std::string string_P;
	std::getline(std::cin, string_P);
	while (string_P[0] != ' ')
	{
		handleExpression(string_P, P);
		std::getline(std::cin, string_P);
	}

	std::cout << "S: ";
	std::string string_S;
	std::getline(std::cin, string_S);
	S = string_S[0];



	printSet(N);
	printSet(T);

	for (std::map<char, std::vector<Pattern>>::iterator it = P.begin();it != P.end();it++) {
		std::cout << it->first << " -> ";
		for (std::vector<Pattern>::iterator jt = it->second.begin();jt != it->second.end();jt++) {
			if (jt != it->second.begin()) {
				std::cout << " | ";
			}
			std::cout << *jt;
		}
		std::cout << std::endl;
	}

	std::cout << S << std::endl;
	return 0;
}
