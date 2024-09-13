// showMenu函数
// main中调用

#include <iostream>
using namespace std;
#include <string>
#define MAX 1000


// 联系人结构体
struct person
{
	string m_name;
	int m_age;
	int m_gender;	// 1：男	2：女
	string m_number;
	string m_addr;
};

// 通讯录结构体
struct Addressbooks
{
	// 联系人数组
	struct person personArray[MAX];
	// 联系人个数
	int m_size;
};

void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1、增加联系人 *****" << endl;
	cout << "***** 2、删除联系人 *****" << endl;
	cout << "***** 3、修改联系人 *****" << endl;
	cout << "***** 4、显示联系人 *****" << endl;
	cout << "***** 5、查找联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

void addPerson(Addressbooks &abs)
{
	if (abs.m_size == MAX)
	{
		cout << "通讯录已满" << endl;
	}
	else
	{
		// 添加联系人
		cout << "请输入姓名" << endl;
		string name;
		cin >> name;
		abs.personArray[abs.m_size].m_name = name;

		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs.personArray[abs.m_size].m_age = age;

		cout << "请输入性别（1：男	2：女）" << endl;
		int gender = 0;
		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				abs.personArray[abs.m_size].m_gender = gender;
				break;
			}
			cout << "输入有误" << endl;
		}
		

		cout << "请输入号码" << endl;
		string num;
		cin >> num;
		abs.personArray[abs.m_size].m_number = num;

		cout << "请输入地址" << endl;
		string addr;
		cin >> addr;
		abs.personArray[abs.m_size].m_addr = addr;
		
		abs.m_size++;
		cout << "添加成功" << endl;
	}
	system("pause");	// 按任意键继续
	system("cls");		// 清屏

}

void showPerson(Addressbooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "空的通讯录" << endl;
	}
	else
	{
		int i = 0;
		for (i = 0; i <= abs->m_size - 1; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_name << "\t";
			cout << "性别：" << (abs->personArray[i].m_gender == 1?"男":"女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_age << "\t";
			cout << "号码：" << abs->personArray[i].m_number << "\t";
			cout << "地址：" << abs->personArray[i].m_addr << endl;
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
	cout << "输入要删除的联系人姓名" << endl;
	string name;
	cin >> name;

	int ret = 0;
	ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		int i = 0;
		for (i = ret; i <= abs.m_size - 2; i++)
		{
			abs.personArray[i] = abs.personArray[i + 1];
		}

		abs.m_size--;
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(Addressbooks& abs)
{
	cout << "请输入你想查找的联系人姓名" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout << "姓名：" << abs.personArray[ret].m_name << "\t";
		cout << "性别：" << (abs.personArray[ret].m_gender == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs.personArray[ret].m_age << "\t";
		cout << "号码：" << abs.personArray[ret].m_number << "\t";
		cout << "地址：" << abs.personArray[ret].m_addr << endl;
	}

	system("pause");
	system("cls");

}

void modifyPerson(Addressbooks& abs)
{
	cout << "请输入想要修改的联系人姓名" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout << "更改姓名：" << endl;
		string name1;
		cin >> name1;
		abs.personArray[ret].m_name = name1;

		cout << "更改性别(1：男		2：女)：" << endl;
		int gender1;
		cin >> gender1;
		abs.personArray[ret].m_gender = gender1;

		cout << "更改年龄：" << endl;
		int age1;
		cin >> age1;
		abs.personArray[ret].m_age = age1;

		cout << "更改号码：" << endl;
		string num1;
		cin >> num1;
		abs.personArray[ret].m_number = num1;

		cout << "更改地址：" << endl;
		string addr1;
		cin >> addr1;
		abs.personArray[ret].m_addr = addr1;

		cout << "修改联系人成功" << endl;
	}

	system("pause");
	system("cls");
}

void cleanPerson(Addressbooks& abs)
{
	char s;

	while (true)
	{
		cout << "确定要清空吗？（y/n）" << endl;
		cin >> s;
		if (s == 'y' || s == 'n')
		{
			break;
		}
		cout << "输入错误" << endl;
	}

	if (s == 'n')
	{
		cout << "撤回成功" << endl;
	}
	else
	{
		abs.m_size = 0;
		cout << "清除成功" << endl;
	}
	system("pause");
	system("cls");
	

}


int main()
{
	Addressbooks abs;
	abs.m_size = 0;
	int select = 0;		// 用户选择

	while (true)
	{
		showMenu();

		cin >> select;

		switch (select)
		{
		case 0:		// 退出
			cout << "你将退出，欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		case 1:		// 增加
			addPerson(abs);
			break;
		case 2:		// 删除
			deletePerson(abs);
			break;
		case 3:		// 修改
			modifyPerson(abs);
			break;
		case 4:		// 显示
			showPerson(&abs);
			break;
		case 5:		// 查找
			findPerson(abs);
			break;
		case 6:		// 清除
			cleanPerson(abs);
			break;

		default:
			break;
		}
	}
	

	system("pause");
	return 0;
}