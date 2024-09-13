// showMenu����
// main�е���

#include <iostream>
using namespace std;
#include <string>
#define MAX 1000


// ��ϵ�˽ṹ��
struct person
{
	string m_name;
	int m_age;
	int m_gender;	// 1����	2��Ů
	string m_number;
	string m_addr;
};

// ͨѶ¼�ṹ��
struct Addressbooks
{
	// ��ϵ������
	struct person personArray[MAX];
	// ��ϵ�˸���
	int m_size;
};

void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1��������ϵ�� *****" << endl;
	cout << "***** 2��ɾ����ϵ�� *****" << endl;
	cout << "***** 3���޸���ϵ�� *****" << endl;
	cout << "***** 4����ʾ��ϵ�� *****" << endl;
	cout << "***** 5��������ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0���˳�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
}

void addPerson(Addressbooks &abs)
{
	if (abs.m_size == MAX)
	{
		cout << "ͨѶ¼����" << endl;
	}
	else
	{
		// �����ϵ��
		cout << "����������" << endl;
		string name;
		cin >> name;
		abs.personArray[abs.m_size].m_name = name;

		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs.personArray[abs.m_size].m_age = age;

		cout << "�������Ա�1����	2��Ů��" << endl;
		int gender = 0;
		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				abs.personArray[abs.m_size].m_gender = gender;
				break;
			}
			cout << "��������" << endl;
		}
		

		cout << "���������" << endl;
		string num;
		cin >> num;
		abs.personArray[abs.m_size].m_number = num;

		cout << "�������ַ" << endl;
		string addr;
		cin >> addr;
		abs.personArray[abs.m_size].m_addr = addr;
		
		abs.m_size++;
		cout << "��ӳɹ�" << endl;
	}
	system("pause");	// �����������
	system("cls");		// ����

}

void showPerson(Addressbooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "�յ�ͨѶ¼" << endl;
	}
	else
	{
		int i = 0;
		for (i = 0; i <= abs->m_size - 1; i++)
		{
			cout << "������" << abs->personArray[i].m_name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_gender == 1?"��":"Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_age << "\t";
			cout << "���룺" << abs->personArray[i].m_number << "\t";
			cout << "��ַ��" << abs->personArray[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int isExist(Addressbooks &abs, string name)
{
	int i = 0;
	for (i = 0; i <= abs.m_size - 1; i++)
	{
		if (abs.personArray[i].m_name == name)
		{
			return i;
		}
	}
	return -1;
}

void deletePerson(Addressbooks& abs)
{
	cout << "����Ҫɾ������ϵ������" << endl;
	string name;
	cin >> name;

	int ret = 0;
	ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		int i = 0;
		for (i = ret; i <= abs.m_size - 2; i++)
		{
			abs.personArray[i] = abs.personArray[i + 1];
		}

		abs.m_size--;
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(Addressbooks& abs)
{
	cout << "������������ҵ���ϵ������" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		cout << "������" << abs.personArray[ret].m_name << "\t";
		cout << "�Ա�" << (abs.personArray[ret].m_gender == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs.personArray[ret].m_age << "\t";
		cout << "���룺" << abs.personArray[ret].m_number << "\t";
		cout << "��ַ��" << abs.personArray[ret].m_addr << endl;
	}

	system("pause");
	system("cls");

}

void modifyPerson(Addressbooks& abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ������" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		cout << "����������" << endl;
		string name1;
		cin >> name1;
		abs.personArray[ret].m_name = name1;

		cout << "�����Ա�(1����		2��Ů)��" << endl;
		int gender1;
		cin >> gender1;
		abs.personArray[ret].m_gender = gender1;

		cout << "�������䣺" << endl;
		int age1;
		cin >> age1;
		abs.personArray[ret].m_age = age1;

		cout << "���ĺ��룺" << endl;
		string num1;
		cin >> num1;
		abs.personArray[ret].m_number = num1;

		cout << "���ĵ�ַ��" << endl;
		string addr1;
		cin >> addr1;
		abs.personArray[ret].m_addr = addr1;

		cout << "�޸���ϵ�˳ɹ�" << endl;
	}

	system("pause");
	system("cls");
}

void cleanPerson(Addressbooks& abs)
{
	char s;

	while (true)
	{
		cout << "ȷ��Ҫ����𣿣�y/n��" << endl;
		cin >> s;
		if (s == 'y' || s == 'n')
		{
			break;
		}
		cout << "�������" << endl;
	}

	if (s == 'n')
	{
		cout << "���سɹ�" << endl;
	}
	else
	{
		abs.m_size = 0;
		cout << "����ɹ�" << endl;
	}
	system("pause");
	system("cls");
	

}


int main()
{
	Addressbooks abs;
	abs.m_size = 0;
	int select = 0;		// �û�ѡ��

	while (true)
	{
		showMenu();

		cin >> select;

		switch (select)
		{
		case 0:		// �˳�
			cout << "�㽫�˳�����ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		case 1:		// ����
			addPerson(abs);
			break;
		case 2:		// ɾ��
			deletePerson(abs);
			break;
		case 3:		// �޸�
			modifyPerson(abs);
			break;
		case 4:		// ��ʾ
			showPerson(&abs);
			break;
		case 5:		// ����
			findPerson(abs);
			break;
		case 6:		// ���
			cleanPerson(abs);
			break;

		default:
			break;
		}
	}
	

	system("pause");
	return 0;
}