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
	// ��һ��
	// 1.��ǩ
	this->startDraw();
	// 2.�������
	this->contest();
	// 3.�������
	this->showWinners();

	// �ڶ���
	this->index++;
	// 1.��ǩ
	this->startDraw();
	// 2.�������
	this->contest();
	// 3.���ս��
	this->showWinners();
	system("cls");
	// 4.�����ļ�
	this->save();

	cout << "�������Բ��������" << endl;
}

void ContestManager::startDraw()
{
	cout << "�� " << this->index << " ��ѡ�����ڳ�ǩ" << endl
		<< "----------------------------------------" << endl
		<< "��ǩ���������ʾ(���°�����Ϊһ��):" << endl;

	if (this->index == 1)
	{
		random_shuffle(this->v1.begin(), this->v1.end());
		for (vector<int>::iterator it = this->v1.begin(); it != this->v1.end(); it++)
		{
			cout << "��ţ�" << (*it) << "\tName:" << this->mSpeakers[*it].name <<endl;
		}
		cout << endl;
	}
	else if (this->index == 2)
	{
		random_shuffle(this->v2.begin(), this->v2.end());
		for (vector<int>::iterator it = this->v2.begin(); it != this->v2.end(); it++)
		{
			cout << "��ţ�" << (*it) << "\tName:" << this->mSpeakers[*it].name << endl;
		}
		cout << endl;
	}
	else
	{
		cout << "�ִγ����ˣ�����2��" << endl;
	}
	system("pause");
}

void ContestManager::contest()
{
	cout << "----------�� " << this->index << " �ֱ�����ʽ��ʼ��-----------" << endl
		<< "��ί��֣�" << endl;

	multimap<double, int,greater<double>> mGroupScore;	// ÿ���˷�һС��
	int num = 0;	// ��¼С������

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
		cout << "�ִγ�����" << endl;
	}



	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{

		deque<double> q;
		//cout << "���Ϊ" << (*it) << "��ѡ�ֵ÷֣�" << endl;
		for (int i = 0; i <= JUDGENUM - 1; i++)
		{
			double score = (rand() % 401 + 600) / 10.0f;
			//cout << score << " ";
			q.push_back(score);
		}
		//cout << endl;
		sort(q.begin(), q.end(), greater<double>());	// �Ӵ�С����ȷ�
		q.pop_back();
		q.pop_front();

		double sum = accumulate(q.begin(), q.end(), 0.0f);
		double avg = sum / (double)q.size();
		this->mSpeakers[*it].score[index - 1] = avg;

		//// ��ӡƽ����
		//cout << "���Ϊ" << (*it) << "��ѡ�֣�" << "Name:" << this->mSpeakers[*it].name
		//	<< "  AverageScoreInThisRound:" << this->mSpeakers[*it].score[index - 1] << endl << endl;

		// �����ӡ
		num++;
		mGroupScore.insert(make_pair(avg, (*it)));
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "��ɼ����£�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = mGroupScore.begin(); it != mGroupScore.end(); it++)
			{
				cout << "���Ϊ" << it->second << "��ѡ�֣�" << "Name:" << this->mSpeakers[it->second].name
			<< "\tAverageScoreInThisRound:" << this->mSpeakers[it->second].score[index - 1] << endl;
			}

			// ȡ��ǰ����
			
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
	cout << "----------�� " << this->index << " �ֱ���������-----------" << endl;
	system("pause");
}

void ContestManager::showWinners()
{
	cout << "-----------�� " << this->index << " �ֵĽ�����Ϊ��------------" << endl;
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
	ifs >> ch;	// ��ʹ�ǿ��ļ���Ҳ��Ҫ����һ�£��򵥶�ȡ����ϵͳ����֪��Ϊ�գ����Լ���ĩβ�и������ַ�
	if (ifs.eof())
	{
		cout << "file exists,but is empty." << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	ifs.putback(ch);	// �ѸղŶ������ַ�Ҫ����
	string data;
	int index = 0;

	while (ifs >> data)
	{
		index++;
		//cout << data << endl;
		// ÿһ����Ϣ�ŵ�������
		vector<string> v;
		int start = 0;
		int pos = -1;
		while (true)
		{
			int pos = data.find(',', start);
			if (pos == -1)
			{
				// û�ҵ�
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
		cout << "��" << it->first << "�����  �ھ���" << it->second[0] << " �÷֣�" << it->second[2]
			<< "   �Ǿ���" << it->second[3] << " �÷֣�" << it->second[5]
			<< "   ������" << it->second[6] << " �÷֣�" << it->second[8] << endl;
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
			cout << "��" << it->first << "�����  �ھ���" << it->second[0] << " �÷֣�" << it->second[2]
				<< "   �Ǿ���" << it->second[3] << " �÷֣�" << it->second[5]
				<< "   ������" << it->second[6] << " �÷֣�" << it->second[8] << endl;
		}
	}
	
	system("pause");
	system("cls");
}


ContestManager::~ContestManager()
{

}