#include "func.h"

int main()
{
	setlocale(LC_ALL, ".1251");
	C_N a(4, 4);
	C_N b(1, 2);
	//C_N c(1, 2);
	//C_N d;
	try
	{
		Show(a); Show(b);
		cout << "��������:\n\n";
		cout << "��������: "; Show(a + b);
		cout << "���������: "; Show(a - b);
		cout << "���������: "; Show(a*b);
		cout << "�������: "; Show(a / b);
		cout << "������������ �� ������: "; Show(a.srav(b));
		/*
		cout << "������� �����: ";
		cin >> a; 
		cout << a << endl;
		*/
		
	}
	catch (int p)
	{
		switch (p)
		{
		case 1: {cout << "������� �� ����." << endl; cout << "������������ �� ������:"; Show(a.srav(b)); break; }
		default: {cout << "error.\n"; break; }
		}
	}
	return 0;
}