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
	// 年龄大的在前，若年龄一样，则身高大的在前
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

	// list容器不能随机访问（a[i]）,所以不能用标准算法函数sort
	// 但一般不能随机访问的容器，内部封装了一些算法

	// 自定义类型不能直接比，要写compare规则
	l.sort(ComparePerson);
	cout << "--------------after comparing---------------" << endl;
	PrintList(l);
	
	system("pause");
	return 0;
}
