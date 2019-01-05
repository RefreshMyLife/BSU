#include "Bus.h"


int main(int argc, char argv[]) {
	setlocale(LC_ALL, ".1251");
	try {
		vector<Bus> arr = create("input.txt");
		ofstream fout("output.txt", ios_base::trunc);
		if (!fout.is_open())
			throw exception("�������� ���� �� ������");
		fout << "������ ������:";
		print(fout, arr);
		fout << endl <<"******************************************************************\n"<< endl;
		string t;
		while (true) {
			char ch;
			cout << "1 - ������ ��������� ��� ��������� ������ ��������\n"
				<< "2 - ������ ���������, ������� ��������������� ������ 10 ���\n"
				<< "3 - ������ ���������, ������ � ������� ������ 10 000 ��\n"
				<< "0 - ����� �� ���������." << endl << "\n��� �����: ";
			cin >> ch;
			if (ch < '0' || ch > '3') {
				cout << "�������� �����\n\n";
				continue;
			}
			cout << endl;

			switch (ch) {
			case '1':
				cout << "\n������� ����� ��������: ";
				cin.ignore();
				getline(cin, t);
				fout << "\n\n������ ��� ������ ��������: " << t << endl;
				for (auto i : arr)
					if (i.getNumberOfRoute().compare(t) == 0)
						fout << i;
				fout << endl << endl;
				break;
			case '2':
				fout << "\n\n\n������ ���������, ������� ��������������� ������ 10 ���:";
				for (auto i : arr)
					if (i.getReleaseYear() <= 2007)
						fout << i;
				fout << endl << endl;
				break;
			case '3':
				fout << "\n\n\n������ ���������, ������ � ������� ������ 10 000 ��";
				for (auto i : arr)
					if (i.getMileage() > 10000)
						fout << i;
				fout << endl << endl;
				break;
			default:
				throw exception("������ ���������");
				break;
			}
		}
	}
	catch (exception& ex) { cerr << ex.what() << endl; }
	return 0;
}
