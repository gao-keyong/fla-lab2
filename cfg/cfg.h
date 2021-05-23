#pragma once
#include <set>
#include <map>
#include <vector>
#include <string>

typedef std::set<char> Set;			// 符号集合
typedef std::string Pattern;		// 句型
typedef std::set<Pattern> PSet;		// 句型的集合
typedef std::map<char, PSet> PMap;	// 生成式的集合

typedef struct {
	Set N;	// 非终结符
	Set T;	// 终结符
	PMap P; // 生成式的集合
	char S;	// 起始符
} CFG;