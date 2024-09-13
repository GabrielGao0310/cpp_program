#include <iostream>
#include <algorithm>
using namespace std;
#include "ContestManagement.h"


//// test func
//void printSpeaker(pair<const int, Speaker>& p)
//{
//	cout << "SpeakerId:" << p.first << "\tSpeakerName:" << p.second.name 
//		<< "\tSpeakerScore:" << p.second.score[0] << endl;
//}

int main()
{
	ContestManager cm;
	int select = 0;

	//// test
	//for_each(cm.mSpeakers.begin(), cm.mSpeakers.end(), printSpeaker);
	
	while (true)
	{
		cm.showMenu();
		cout << "Please input your selection:" << endl;
		cin >> select;

		switch (select)
		{
		case 1:			// begin the contest
			cm.startContest();
			break;
		case 2:			// check contest log
			cm.showRecord();
			break;
		case 3:			// clean contest log
			break;
		case 0:			// exit manager system
			cm.exitSystem();
			break;
		default:
			cout << "input is illegal!" << endl;
			system("pause");
			system("cls");
			break;
		}

	}

	system("pause");
	return 0;
}