#include "func.h"

int main()
{
	setlocale(LC_ALL, ".1251");
	C_N a(5, 2);
	C_N b(1, 2);
	try
	{
		Show(a); Show(b);
		cout << "��������:\n\n";
		cout << "��������: "; Show(a.plus(b));
		cout << "���������: "; Show(a.minus(b));
		cout << "���������: "; Show(a.umn(b));
		cout << "�������: "; Show(a.del(b));
		cout << "������������ �� ������: "; Show(a.srav(b));
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