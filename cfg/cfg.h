#pragma once
#include <set>
#include <map>
#include <vector>
#include <string>

typedef std::string Pattern; // 句型

typedef struct {
	std::set<char> N;                       // 非终结符
	std::set<char> T;                       // 终结符
	std::map<char, std::vector<Pattern>> P; // 生成式的集合
	char S;									// 起始符
} CFG;