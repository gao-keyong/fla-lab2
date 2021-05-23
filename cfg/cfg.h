#pragma once
#include <set>
#include <map>
#include <vector>
#include <string>

typedef std::set<char> Set;			// ���ż���
typedef std::string Pattern;		// ����
typedef std::set<Pattern> PSet;		// ���͵ļ���
typedef std::map<char, PSet> PMap;	// ����ʽ�ļ���

typedef struct {
	Set N;	// ���ս��
	Set T;	// �ս��
	PMap P; // ����ʽ�ļ���
	char S;	// ��ʼ��
} CFG;