#include "ContestManagement.h"

ContestManager::ContestManager()
{
	this->initManager();
	this->createSpeakers();
	this->loadRecord();
}

void ContestManager::initManager()
{
	this->index = 1;
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->mSpeakers.clear();
}

void ContestManager::createSpeakers()
{
	for (int i = 0; i <= SPEAKERNUM - 1; i++)
	{
		string name = "Speaker_";
		name += to_string(i + 1);

		Speaker s;
		s.name = name;
		for (int j = 0; j <= 1; j++)
		{
			s.score[j] = 0.0;
		}

		this->v1.push_back(10001 + i);
		this->mSpeakers.insert(make_pair(10001 + i, s));
	}
}


void ContestManager::showMenu()
{
	cout <<"*********************************************" << endl
		<< "**** welcome to use SpeechContestManager ****" << endl
		<< "********  1.begin the SpeechContest  ********" << endl
		<< "********  2.check the Contest log  **********" << endl
		<< "********  3.clean the Contest log  **********" << endl
		<< "********  0.exit the ContestManager  ********" << endl
		<< "*********************************************" << endl;

}

void ContestManager::exitSystem()
{
	cout << "you will exit the Contest manager system." << endl;
	system("pause");
	exit(0);
}

void ContestManager::startContest()
{
	// 第一轮
	// 1.抽签
	this->startDraw();
	// 2.比赛打分
	this->contest();
	// 3.晋级结果
	this->showWinners();

	// 第二轮
	this->index++;
	// 1.抽签
	this->startDraw();
	// 2.比赛打分
	this->contest();
	// 3.最终结果
	this->showWinners();
	system("cls");
	// 4.保存文件
	this->save();

	cout << "本届比赛圆满结束！" << endl;
}

void ContestManager::startDraw()
{
	cout << "第 " << this->index << " 轮选手正在抽签" << endl
		<< "----------------------------------------" << endl
		<< "抽签结果如下所示(上下半区各为一组):" << endl;

	if (this->index == 1)
	{
		random_shuffle(this->v1.begin(), this->v1.end());
		for (vector<int>::iterator it = this->v1.begin(); it != this->v1.end(); it++)
		{
			cout << "编号：" << (*it) << "\tName:" << this->mSpeakers[*it].name <<endl;
		}
		cout << endl;
	}
	else if (this->index == 2)
	{
		random_shuffle(this->v2.begin(), this->v2.end());
		for (vector<int>::iterator it = this->v2.begin(); it != this->v2.end(); it++)
		{
			cout << "编号：" << (*it) << "\tName:" << this->mSpeakers[*it].name << endl;
		}
		cout << endl;
	}
	else
	{
		cout << "轮次出错了（超出2）" << endl;
	}
	system("pause");
}

void ContestManager::contest()
{
	cout << "----------第 " << this->index << " 轮比赛正式开始！-----------" << endl
		<< "评委打分：" << endl;

	multimap<double, int,greater<double>> mGroupScore;	// 每六人分一小组
	int num = 0;	// 记录小组人数

	vector<int> v_Src;
	if (this->index == 1)
	{
		v_Src = v1;
	}
	else if (this->index == 2)
	{
		v_Src = v2;
	}
	else
	{
		cout << "轮次出错了" << endl;
	}



	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{

		deque<double> q;
		//cout << "编号为" << (*it) << "的选手得分：" << endl;
		for (int i = 0; i <= JUDGENUM - 1; i++)
		{
			double score = (rand() % 401 + 600) / 10.0f;
			//cout << score << " ";
			q.push_back(score);
		}
		//cout << endl;
		sort(q.begin(), q.end(), greater<double>());	// 从大到小排序比分
		q.pop_back();
		q.pop_front();

		double sum = accumulate(q.begin(), q.end(), 0.0f);
		double avg = sum / (double)q.size();
		this->mSpeakers[*it].score[index - 1] = avg;

		//// 打印平均分
		//cout << "编号为" << (*it) << "的选手，" << "Name:" << this->mSpeakers[*it].name
		//	<< "  AverageScoreInThisRound:" << this->mSpeakers[*it].score[index - 1] << endl << endl;

		// 分组打印
		num++;
		mGroupScore.insert(make_pair(avg, (*it)));
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "组成绩如下：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = mGroupScore.begin(); it != mGroupScore.end(); it++)
			{
				cout << "编号为" << it->second << "的选手，" << "Name:" << this->mSpeakers[it->second].name
			<< "\tAverageScoreInThisRound:" << this->mSpeakers[it->second].score[index - 1] << endl;
			}

			// 取出前三名
			
				int count = 0;
				for (multimap<double, int, greater<double>>::iterator it = mGroupScore.begin(); it != mGroupScore.end() && count <= 2; it++, count++)
				{
					if (this->index == 1)
					{
						this->v2.push_back(it->second);

					}
					else
					{
						this->vVictory.push_back(it->second);
					}
				}
			


			mGroupScore.clear();
			cout << endl;
		}

		

	}
	cout << "----------第 " << this->index << " 轮比赛结束！-----------" << endl;
	system("pause");
}

void ContestManager::showWinners()
{
	cout << "-----------第 " << this->index << " 轮的晋级者为：------------" << endl;
	vector<int> v_src;

	if (this->index == 1)
	{
		v_src = this->v2;
	}
	else
	{
		v_src = this->vVictory;
	}

	for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++)
	{
		cout << "ID:" << (*it) << "\tName:" << this->mSpeakers[*it].name
			<< "\t Score:" << this->mSpeakers[*it].score[this->index - 1] << endl;
	}
	system("pause");
}

void ContestManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out | ios::app);

	for (vector<int>::iterator it = this->vVictory.begin(); it != this->vVictory.end(); it++)
	{
		ofs  << this->mSpeakers[*it].name << "," << (*it) << "," << this->mSpeakers[*it].score[1] << ",";

	}
	ofs << endl;
	ofs.close();

	cout << "log is saved successfully!" << endl;
	fileIsEmpty = false;

}

void ContestManager::loadRecord()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "file is not exist." << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	char ch = ' ';
	ifs >> ch;	// 即使是空文件，也需要操作一下（简单读取），系统才能知道为空，可以假设末尾有个隐藏字符
	if (ifs.eof())
	{
		cout << "file exists,but is empty." << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	ifs.putback(ch);	// 把刚才读出的字符要回来
	string data;
	int index = 0;

	while (ifs >> data)
	{
		index++;
		//cout << data << endl;
		// 每一届信息放到容器中
		vector<string> v;
		int start = 0;
		int pos = -1;
		while (true)
		{
			int pos = data.find(',', start);
			if (pos == -1)
			{
				// 没找到
				break;
			}
			v.push_back(data.substr(start, pos - start));
			start = pos+1;
		}
		this->m_Record.insert(make_pair(index, v));
		v.clear();
	}
	ifs.close();

	/*for (map<int, vector<string>>::iterator it = this->m_Record.begin(); it != this->m_Record.end(); it++)
	{
		cout << "第" << it->first << "届比赛  冠军：" << it->second[0] << " 得分：" << it->second[2]
			<< "   亚军：" << it->second[3] << " 得分：" << it->second[5]
			<< "   季军：" << it->second[6] << " 得分：" << it->second[8] << endl;
	}*/
}

void ContestManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "file is not exist or empty." << endl;
	}
	else
	{
		for (map<int, vector<string>>::iterator it = this->m_Record.begin(); it != this->m_Record.end(); it++)
		{
			cout << "第" << it->first << "届比赛  冠军：" << it->second[0] << " 得分：" << it->second[2]
				<< "   亚军：" << it->second[3] << " 得分：" << it->second[5]
				<< "   季军：" << it->second[6] << " 得分：" << it->second[8] << endl;
		}
	}
	
	system("pause");
	system("cls");
}


ContestManager::~ContestManager()
{

}