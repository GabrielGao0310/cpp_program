#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#define PERSONNUM 5
#define JUDGESNUM 10

class Person
{
public:
	string m_name;
	int score;

	Person(string name, int score)
	{
		this->m_name = name;
		this->score = score;
	}
};

void createPerson(vector<Person>& v)
{
	for (int i = 0; i <= PERSONNUM - 1; i++)
	{
		string nameSeed = "ABCDEFGHIJK";
		string name = "Person_";
		name += nameSeed[i];

		int score = 0;
		Person p(name, score);

		v.push_back(p);
	}
}

// give a score for every person.
void setScore(vector<Person>& v)
{
	// for each person
	for (int i = 0; i <= v.size() - 1; i++)
	{
		deque<int> d;
		// for each judge
		for (int j = 0; j <= JUDGESNUM - 1; j++)
		{
			int s = rand() % 41 + 60;
			d.push_back(s);
		}

		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();

		int sum = 0;
		for (int k = 0; k <= d.size() - 1; k++)
		{
			sum += d[k];
		}
		int score = sum / d.size();

		v[i].score = score;
	}
}

void showScore(const vector<Person>& v)
{
	for (vector<Person>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "PlayerName:" << it->m_name << "\tPlayerScore:" << it->score << endl;
	}
}


int main()
{
	srand((unsigned int)time(NULL));

	vector<Person> v;
	createPerson(v);
	setScore(v);
	
	showScore(v);

	system("pause");
	return 0;
}