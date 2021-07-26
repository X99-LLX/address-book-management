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
	cout << "*** ��ӭʹ��ͨѶ¼���� ***" << endl;
	cout << "****** 1.�����ϵ�� ******" << endl;
	cout << "****** 2.��ʾ��ϵ�� ******" << endl;
	cout << "****** 3.ɾ����ϵ�� ******" << endl;
	cout << "****** 4.������ϵ�� ******" << endl;
	cout << "****** 5.�޸���ϵ�� ******" << endl;
	cout << "****** 6.�����ϵ�� ******" << endl;
	cout << "****** 0.�˳���ϵ�� ******" << endl;
	cout << "**************************" << endl;
}

void print_person(book * p,int i) {
	cout << p->all[i].name << "\t" << p->all[i].sex << "\t" << p->all[i].age << "\t" << p->all[i].phone << "\t" << p->all[i].zhuzhi << endl;
}

void printperson(book* book) {
	if (book->size == 0) {
		cout << "��ǰͨѶ¼Ϊ�գ�" << endl;
	}
	else {
		for (int i = 0; i < book->size; i++) {
			print_person(book,i);
		}
	}
	system1();
}

void message(book* book,int i) {
	cout << "������������" << endl;
	cin >> book->all[i].name;
	cout << "�������Ա�" << endl << "1---man" << endl << "2---women" << endl;
	int sex;
	while (1) {
		cin >> sex;
		if (sex == 1 || sex == 2) {
			book->all[i].sex = sex;
			break;
		}
		else {
			cout << "������������������" << endl;
		}
	}
	cout << "���������䣡" << endl;
	cin >> book->all[i].age;
	cout << "������绰��" << endl;
	cin >> book->all[i].phone;
	cout << "������סַ��" << endl;
	cin >> book->all[i].zhuzhi;
}

void addperson(book* book) {
	if (book->size == MAX) {
		cout << "ͨѶ¼�������޷����" << endl;
	}
	else {
		message(book,book->size);
		cout << "��ӳɹ�!" << endl;
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
	cout << "������Ҫɾ��������" << endl;
	string name;
	cin >> name;
	int ret = findperson(book, name);
	if (ret == -1) {
		cout << "���޴���!" << endl;
	}
	else {
		for (int i = ret; i < book->size - 1; i++) {
			book->all[i] = book->all[i + 1];
		}
		cout << "��ɾ������ϵ��!" << endl;
		book->size--;
	}
	system1();
}

void Find(book* book) {
	string name;
	cout << "������Ҫ���ҵ�������" << endl;
	cin >> name;
	int ret = findperson(book, name);
	if (ret == -1) {
		cout << "���޴���!" << endl;
	}
	else {
		print_person(book, ret);
	}
	system1();
}

void alter(book* book) {
	string name;
	cout << "������Ҫ�޸ĵ��˵�������" << endl;
	cin >> name;
	int ret = findperson(book, name);
	if (ret == -1) {
		cout << "���޴���!" << endl;
	}
	else {
		message(book, ret);
	}
	system1();
}


void deleteall(book* book) {
	cout << "ȷ�������ϵ����" << endl << "1---ȷ��" << endl << "2---ȡ��" << endl;
	int i;
	cin >> i;
	if (i == 1) {
		book->size = 0;
		cout << "�����������ϵ�ˣ�" << endl;
	}
	else {
		cout << "��ȡ����" << endl;
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
				cout << "��ӭ�´�ʹ�ã�" << endl;
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
				cout << "��������ȷ����ţ�" << endl;
				break;
			}
	}

	system("pause");
}