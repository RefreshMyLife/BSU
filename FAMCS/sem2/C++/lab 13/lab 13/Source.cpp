#include "ex.h"

int main(){
	setlocale(LC_ALL, ".1251");
	_map a;
	try{
		ofstream fout("output.txt", ios_base::trunc);
		if (!fout)
			throw ex("output.txt", fout);
		_read(a, "input.txt");
		f2(a);
		f3(a);
		f4(a);
		f5(a);
		f6(a, "����");
		f7(a);
		f8(a);
		cout << "�� ������� �������� � ����." << endl;
	}
	catch (exception& e){ cout << e.what() << endl; }
	return 0;
}