#pragma once
#include <set>
#include <map>
#include <vector>
#include <string>

typedef std::string Pattern; // ����

typedef struct {
	std::set<char> N;                       // ���ս��
	std::set<char> T;                       // �ս��
	std::map<char, std::vector<Pattern>> P; // ����ʽ�ļ���
	char S;									// ��ʼ��
} CFG;