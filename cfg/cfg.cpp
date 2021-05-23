#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

#include "handleIO.h"
#include "cfg.h"

inline bool isN(const char ch) {
	return isupper(ch) || ch == '$';
}

int main(int argc, char const* argv[])
{
	// 输入文法G
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
	std::cout << std::endl;

	// 消除空生成式
	CFG G1;
	std::set<char> Ntmp;
	for (PMap::iterator it = G.P.begin();it != G.P.end();it++) {
		for (auto pattern : it->second) {
			if (pattern == "#") {
				Ntmp.insert(it->first);
			}
		}
	}
	if (!Ntmp.empty()) {
		bool changed = true;
		while (changed) {
			changed = false;
			for (PMap::iterator it = G.P.begin();it != G.P.end();it++) {
				for (auto pattern : it->second) {
					bool empty_generable = true;
					for (auto ch : pattern) {
						if (isupper(ch)) {
							if (Ntmp.find(ch) == Ntmp.end()) {
								empty_generable = false;
								break;
							}
						}
						else {
							empty_generable = false;
							break;
						}
					}
					if (empty_generable) {
						if (Ntmp.find(it->first) == Ntmp.end()) {
							changed = true;
							Ntmp.insert(it->first);
						}
					}
				}
			}
		}
	}

	for (PMap::iterator it = G.P.begin();it != G.P.end();it++) {
		for (auto pattern : it->second) {
			std::vector<int> YIndex;
			for (size_t i = 0;i < pattern.length();i++) {
				if (Ntmp.find(pattern[i]) != Ntmp.end()) {
					YIndex.push_back(i);
				}
			}
			if (YIndex.empty()) {
				if (pattern[0] != '#') {
					G1.P[it->first].insert(pattern);
				}
			}
			else {
				for (int bits = 0;bits < 1 << YIndex.size();bits++) {
					std::string beta = pattern.substr(0, YIndex[0]);
					for (int i = 0, bit = bits;i < YIndex.size();i++, bit >>= 1) {
						if (bit & 1) {
							beta += pattern[YIndex[i]];
						}
						if (i + 1 < YIndex.size()) beta += pattern.substr(YIndex[i] + 1, YIndex[i + 1]);
						else beta += pattern.substr(YIndex[i] + 1);
					}
					if (!beta.empty()) {
						G1.P[it->first].insert(beta);
					}
				}
			}
		}
	}

	G1.N = G.N;
	G1.T = G.T;
	if (Ntmp.find(G.S) != Ntmp.end()) {
		G1.P['$'].insert("#");
		G1.P['$'].insert("S");
		G1.N.insert('$');
		G1.S = '$';
	}

	//printSet(G1.N);
	//printSet(G1.T);

	//printExpressions(G1.P);

	//std::cout << G1.S << std::endl << std::endl;

	// 消除单生成式

	CFG G2(G1);

	bool single_exist = true;
	while (single_exist) {
		single_exist = false;
		for (PMap::iterator it = G2.P.begin();it != G2.P.end();it++) {
			std::vector<char> BSymbol;
			char A = it->first;
			PSet& B = it->second;
			for (PSet::iterator jt = B.begin();jt != B.end();jt++) {
				Pattern pattern = *jt;
				if (pattern.size() == 1 && isN(pattern[0])) {
					BSymbol.push_back(pattern[0]);
				}
			}
			if (!BSymbol.empty()) {
				single_exist = true;
				for (auto symbol : BSymbol) {
					B.erase(Pattern(1,symbol));
					B.insert(G2.P[symbol].begin(), G2.P[symbol].end());
				}
			}
		}
	}
	printSet(G2.N);
	printSet(G2.T);

	printExpressions(G2.P);

	std::cout << G2.S << std::endl;

	// 消除无用符号



	return 0;
}
