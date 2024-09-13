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


	vector<int> v1; // 第一轮选手编号
	vector<int> v2; // 第二轮选手编号
	vector<int> vVictory; // 前三名编号
	map<int, Speaker> mSpeakers; // 编号，选手
	map<int, vector<string>> m_Record; // 往届记录
	int index;	// 比赛轮次
	bool fileIsEmpty;
};