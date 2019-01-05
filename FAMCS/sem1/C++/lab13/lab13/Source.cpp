#include <iostream>

using namespace std;

struct Data
{
	long a;
};

struct List
{
	Data d;
	List *next;
};

void SortList(List* u)
{
	List *p = u;
	while (p->next)
	{
		if (p->next->d.a < p->d.a)
		{
			Data temp = p->d;
			p->d = p->next->d;
			p->next->d = temp;
			p = u;
			continue;
		}
		p = p->next;
	}
	p = u;
	while (p->next)
	{
		if (p->d.a == p->next->d.a)
		{
			List* temp = p->next;
			p->next = p->next->next;
			delete temp;
			continue;
		}
		p = p->next;
	}
}


void PrintList(List *u)
{
	List *p = u;
	//p = u;
	cout << "\n������:" << endl;
	while (p->next)
	{
		cout << endl << p->next->d.a << endl;
		p = p->next;
	}
}


void SpecialDel(List* & u)
{
	List *p = u;
	if (p->next->d.a >= 1000)
	{
		cout << "\n� ������ ��� ������� �����." << endl;
		return;
	}
	while (p->next->d.a < 1000 && p->next->next)
	{
		List* temp = p;
		p = p->next;
		delete temp;
	}
	if (p->next->next == 0 && p->next->d.a < 1000)
	{
		p->d.a = 0;
		cout << "\n� ������ ����������� ������ ������ ���������.\n\n";
	}
	u = p;
}


void Clear(List* &u)	//������� ����� ������
{
	if (u == 0)
		return;
	List *p = u;
	List *t;
	while (p)
	{
		t = p;
		p = p->next;
		delete t;
	}
	u = 0;
}


int main()
{
	setlocale(LC_ALL, ".1251");
	List *u = NULL;
	u = new List;	//������ ��� �������
	List *x;		//��������� �� ��������� �������
	u->next = NULL;
	x = u;

	long num;
	Data m;
	bool flag = false;
	cout << "������� ������ ��������� (����������� � ����������). ���� ������ ��������� - ������� 0:\n";
	try
	{
		while (true)
		{
			cin >> num;
			cin.ignore();
			if (num == 0)
				break;
			flag = true;
			if (num < 100 || num > 9999999 || (num > 999 && num < 1000000))
			{
				cout << "�������, ����������, ������������.\n";
				continue;
			}
			m.a = num;
			x->d.a = m.a;
			x->next = new List;
			x = x->next;
			x->next = NULL;
		}
		if (!flag)
			throw "������ ����.\n";
		SortList(u);
		PrintList(u);

		SpecialDel(u);
		if (u->d.a == 0)
			return 0;
		if (!u->next)
			throw "������ ������";
		PrintList(u);
		Clear(u);
	}
	catch (char* str)
	{
		cout << "\no����� �������� ������ ��� ���������.";
	}

	cout << endl;
	return 0;
}