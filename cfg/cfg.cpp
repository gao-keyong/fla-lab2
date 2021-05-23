#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

#include "handleIO.h"
#include "cfg.h"

int main(int argc, char const* argv[])
{
	CFG G;
	std::cout << "G = (N, T, P, S)" << std::endl;

	std::cout << "N = {";
	std::string string_N;
	std::getline(std::cin, string_N);
	handleSetString(string_N, G.N);

	std::cout << "T = {";
	std::string string_T;
	std::getline(std::cin, string_T);
	handleSetString(string_T, G.T);

	std::cout << "P: (space to end)" << std::endl;
	std::string string_P;
	std::getline(std::cin, string_P);
	while (string_P[0] != ' ')
	{
		handleExpression(string_P, G.P);
		std::getline(std::cin, string_P);
	}

	std::cout << "S: ";
	std::string string_S;
	std::getline(std::cin, string_S);
	G.S = string_S[0];

	printSet(G.N);
	printSet(G.T);

	printExpressions(G.P);

	std::cout << G.S << std::endl;
	return 0;
}
