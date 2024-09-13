#include <iostream>
#include <string>
#include <list>
#include <ctime>
using namespace std;
#define PERSONNUM 7

class Person
{
public:
	int m_age;
	string m_name;
	int m_height;

	Person(string name, int age, int height);
	void showPerson();
};
Person::Person(string name, int age, int height)
{
	this->m_age = age;
	this->m_height = height;
	this->m_name = name;
}
void Person::showPerson()
{
	cout << "PersonName:" << this->m_name
		<< "\tPersonAge:" << this->m_age
		<< "\tPersonHeight:" << this->m_height << endl;
}




void CreatePerson(list<Person>& l)
{
	string nameSeed = "ABCDEFGHIJK";
	for (int i = 0; i <= PERSONNUM - 1; i++)
	{
		string name = "Person_";
		name += nameSeed[i];
		int age = rand() % 11 + 20;
		int height = rand() % 31 + 170;

		Person p(name, age, height);
		l.push_back(p);
	}
}

void PrintList(list<Person>& l)
{
	for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
	{
		it->showPerson();
	}
}

bool ComparePerson(Person& p1, Person& p2)
{
	// ��������ǰ��������һ��������ߴ����ǰ
	if (p1.m_age == p2.m_age)
	{
		return p1.m_height > p2.m_height;
	}

	return p1.m_age > p2.m_age;
}

int main()
{
	srand((unsigned int)time(NULL));
	list<Person> l;
	CreatePerson(l);
	cout << "--------------before comparing---------------" << endl;
	PrintList(l);

	// list��������������ʣ�a[i]��,���Բ����ñ�׼�㷨����sort
	// ��һ�㲻��������ʵ��������ڲ���װ��һЩ�㷨

	// �Զ������Ͳ���ֱ�ӱȣ�Ҫдcompare����
	l.sort(ComparePerson);
	cout << "--------------after comparing---------------" << endl;
	PrintList(l);
	
	system("pause");
	return 0;
}
