#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
using namespace std;
#define WORKERSNUM 10

#define CEHUA 0
#define MEISHU 1
#define YANFA 2


class Worker
{
public:
	string m_Name;
	int m_Salary;

	Worker(string name, int salary)
	{
		this->m_Name = name;
		this->m_Salary = salary;
	}
	void showWorker()
	{
		cout << "WorkerName:" << this->m_Name << "\tWorkerSalary:" << this->m_Salary << endl;
	}
};

void createWorkers(vector<Worker>& vWorker)
{
	for (int i = 0; i <= WORKERSNUM - 1; i++)
	{
		string name = "Worker_";
		name += to_string(i + 1);
		int salary = rand() % 10001 + 10000;

		Worker w(name, salary);
		vWorker.push_back(w);

	}
}

void showWorkers(vector<Worker>& v)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		it->showWorker();
	}
}

void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		m.insert(pair<int, Worker>(rand() % 3, (*it)));
	}
}

void showWorkersByGroup(multimap<int, Worker>& m)
{
	// find first pos of CEHUA
	multimap<int, Worker>::iterator it = m.find(CEHUA);
	int count = m.count(CEHUA);
	int index = 0;
	cout << "CEHUA:" << endl;
	for (; it != m.end() && index <= count - 1; it++, index++)
	{
		it->second.showWorker();
	}

	// find first pos of MEISHU
	it = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;
	cout << "MEISHU:" << endl;
	for (; it != m.end() && index <= count - 1; it++, index++)
	{
		it->second.showWorker();
	}

	// find first pos of YANFA
	it = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	cout << "YANFA:" << endl;
	for (; it != m.end() && index <= count - 1; it++, index++)
	{
		it->second.showWorker();
	}
}



int main()
{
	srand((unsigned int)time(NULL));
	vector<Worker> vWorker;
	createWorkers(vWorker);
	showWorkers(vWorker);
	
	multimap<int, Worker> m;
	setGroup(vWorker, m);

	cout << endl;
	showWorkersByGroup(m);

	

	system("pause");
	return 0;
}