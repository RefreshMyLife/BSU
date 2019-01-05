/*�������������� ����� ������ ����������� ���������� � ���������.������� 2 ��������� �����,
� ������������� � ���������, ����� ����������, ����������� � ���������, ����������... � ��������� ������.*/

#include <iostream>
using namespace std;
double del(int, int);

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, ".1251");
	int a, b;		//����� � �� B
	cout << "������� A: "; cin >> a;
	cout << "������� B: "; cin >> b;
	cout << "A/B = " << del(a, b) << endl;
	return 0;
}


double del(int _a, int _b) {
	double a = _a, b = _b;
	double c = 3.0, temp;	//c - ��������� �����
	double E = 0.1;		//��������
	double D = 0.05;	//����������

	/*forever{
		double temp = b*c - a;
	if (abs(temp) < E)
		break;
	if (b*c > a)
		c -= D;
	else
		c += D;
	}*/

	_asm {
		fld		a	//st(6) : ��� ��������� (b*c)
		fld		D	//st(5)
		fld		E	//st(4)
		fld		a	//st(3)
		fld		b	//st(2)
		fld		c	//st(1) : ��� ��������� ���������� '�'
		fld		c	//st(0) : ��� �������� ��������� (b*c - a)
		mov		ebx, _b

		_forever :
		mov		ecx, 0
			fsub	st(0), st(0)

			_while :
			fadd	st(0), st(1)
			inc		ecx
			cmp		ecx, ebx
			jne		_while

			fsub	st(0), st(3)	//st(0) : b*c - a
			fabs	//������ st(0)

			fcom	st(4)	//���������� s(0) � E
			fstsw	ax
			sahf
			jb		_endForever	//���� s(0) < E

			fxch	st(6)
			mov		ecx, 0
			fsub	st(0), st(0)

			while_ :
		fadd	st(0), st(1)
			inc		ecx
			cmp		ecx, ebx
			jne		while_

			fcom	st(3)
			fstsw	ax
			sahf
			ja		Rezult1	//���� s(0) > s(3)
			jb		Rezult2	//���� s(0) < s(3)		
			jnb		Rezult2 //���� s(0) == s(3)

			Rezult1 :
		fxch	st(6)
			fxch	st(1)
			fsub	st(0), st(5)
			fxch	st(1)
			jmp		_forever
			Rezult2 :
		fxch	st(6)
			fxch	st(1)
			fadd	st(0), st(5)
			fxch	st(1)
			jmp		_forever

			_endForever :
		fxch	st(1)
			fxch	st(6)
			fstp	temp
			fstp	temp
			fstp	temp
			fstp	temp
			fstp	temp
			fstp	temp
			fstp	temp
	}
	return temp;
}