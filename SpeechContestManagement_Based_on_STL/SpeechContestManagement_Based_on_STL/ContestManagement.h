#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include "speaker.h"
using namespace std;
#define SPEAKERNUM 12
#define JUDGENUM 10
#define FILENAME "WinnersLog.csv"


class ContestManager
{
public:
	ContestManager();
	~ContestManager();
	void showMenu();
	void initManager();
	void createSpeakers();
	void loadRecord();

	void showRecord();

	void startContest();
	void startDraw();
	void contest();
	void showWinners();
	void save();


	void exitSystem();


	vector<int> v1; // ��һ��ѡ�ֱ��
	vector<int> v2; // �ڶ���ѡ�ֱ��
	vector<int> vVictory; // ǰ�������
	map<int, Speaker> mSpeakers; // ��ţ�ѡ��
	map<int, vector<string>> m_Record; // �����¼
	int index;	// �����ִ�
	bool fileIsEmpty;
};