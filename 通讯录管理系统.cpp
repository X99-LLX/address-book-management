#include<iostream>
using namespace std;
#include<string>
#define MAX 10
struct person
{
	string name;
	int age;
	int sex;
	string phone;
	string zhuzhi;
};

struct book
{
	person all[MAX];
	int size = 0;
};

void system1() {
	system("pause");
	system("cls");
}

void shoumenu() {
	cout << "**************************"<< endl;
	cout << "*** 欢迎使用通讯录管理 ***" << endl;
	cout << "****** 1.添加联系人 ******" << endl;
	cout << "****** 2.显示联系人 ******" << endl;
	cout << "****** 3.删除联系人 ******" << endl;
	cout << "****** 4.查找联系人 ******" << endl;
	cout << "****** 5.修改联系人 ******" << endl;
	cout << "****** 6.清空联系人 ******" << endl;
	cout << "****** 0.退出联系人 ******" << endl;
	cout << "**************************" << endl;
}

void print_person(book * p,int i) {
	cout << p->all[i].name << "\t" << p->all[i].sex << "\t" << p->all[i].age << "\t" << p->all[i].phone << "\t" << p->all[i].zhuzhi << endl;
}

void printperson(book* book) {
	if (book->size == 0) {
		cout << "当前通讯录为空！" << endl;
	}
	else {
		for (int i = 0; i < book->size; i++) {
			print_person(book,i);
		}
	}
	system1();
}

void message(book* book,int i) {
	cout << "请输入姓名！" << endl;
	cin >> book->all[i].name;
	cout << "请输入性别！" << endl << "1---man" << endl << "2---women" << endl;
	int sex;
	while (1) {
		cin >> sex;
		if (sex == 1 || sex == 2) {
			book->all[i].sex = sex;
			break;
		}
		else {
			cout << "输入有误，请重新输入" << endl;
		}
	}
	cout << "请输入年龄！" << endl;
	cin >> book->all[i].age;
	cout << "请输入电话！" << endl;
	cin >> book->all[i].phone;
	cout << "请输入住址！" << endl;
	cin >> book->all[i].zhuzhi;
}

void addperson(book* book) {
	if (book->size == MAX) {
		cout << "通讯录已满，无法添加" << endl;
	}
	else {
		message(book,book->size);
		cout << "添加成功!" << endl;
		book->size++;
	}
	system1();
}

int findperson(book* book, string na) {
	for (int i = 0; i < book->size; i++) {
		if (book->all[i].name == na) {
			return i;
		}
	}
	return -1;
}

void deleteperson(book* book) {
	cout << "输入你要删除的姓名" << endl;
	string name;
	cin >> name;
	int ret = findperson(book, name);
	if (ret == -1) {
		cout << "查无此人!" << endl;
	}
	else {
		for (int i = ret; i < book->size - 1; i++) {
			book->all[i] = book->all[i + 1];
		}
		cout << "已删除该联系人!" << endl;
		book->size--;
	}
	system1();
}

void Find(book* book) {
	string name;
	cout << "请输入要查找的姓名！" << endl;
	cin >> name;
	int ret = findperson(book, name);
	if (ret == -1) {
		cout << "查无此人!" << endl;
	}
	else {
		print_person(book, ret);
	}
	system1();
}

void alter(book* book) {
	string name;
	cout << "输入您要修改的人的姓名！" << endl;
	cin >> name;
	int ret = findperson(book, name);
	if (ret == -1) {
		cout << "查无此人!" << endl;
	}
	else {
		message(book, ret);
	}
	system1();
}


void deleteall(book* book) {
	cout << "确定清空联系人吗？" << endl << "1---确定" << endl << "2---取消" << endl;
	int i;
	cin >> i;
	if (i == 1) {
		book->size = 0;
		cout << "已清除所有联系人！" << endl;
	}
	else {
		cout << "已取消！" << endl;
	}
	system1();
}

int main() {
	book book1;
	bool a = 1;

		while (a) {
			shoumenu();
			int sel = 0;
			cin >> sel;
			switch (sel)
			{
			case 0:
				a = 0;
				cout << "欢迎下次使用！" << endl;
				break;
			case 1:
				addperson(&book1);
				break;
			case 2:
				printperson(&book1);
				break;
			case 3:
				deleteperson(&book1);
				break;
			case 4:
				Find(&book1);
				break;
			case 5:
				alter(&book1);
				break;
			case 6:
				deleteall(&book1);
				break;
			default:
				cout << "请输入正确的序号！" << endl;
				break;
			}
	}

	system("pause");
}