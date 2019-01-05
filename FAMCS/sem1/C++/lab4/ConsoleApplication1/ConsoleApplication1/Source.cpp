/* ������������ ������������ ������. ��� ���������� ������� ������������� ��� �������: ���� � 
���������� � ���������� ���������� �������.
� ��������� ������ ����� ����������� ������� ������ ������� ���������, �������� ������ 
������������ �������� �������.  
- ����������� ������������� �������, ����������� � ��� ������ ���, ����� ����� ��������� 
� ������� ���������� ������� ����������.
- ����� � ��� ����� ������� �� ��������, �� ���������� ������������� ���������. */

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");
	int m = 0, n = 0, k = 0;	// ���������� �������� ��������
	while (!(n > 0)){
		cout << "������� ���������� ����� � �������: ";
		cin >> n;
		if (n < 1)
			cout << "error" << endl;
		continue;
	}
	while (!(m > 0)){
		cout << "������� ���������� �������� � �������: ";
		cin >> m;
		if (m < 1)
			cout << "error" << endl;
		continue;
	}
	if ((n == 1) && (m == 1))
		cout << "\n������ ������� �� ������ ��������\n";
	else{
		// ��������� ������

		int **mas; // ���������� "��������� �� ��������� �� integer
		int i, j, a, b;
		mas = new int *[n]; // ������ ��� ������ ���������� �� ������
		for (i = 0; i < n; i++) // ���� ��� ��������� ������ ��� ������ ������
			mas[i] = new int[m]; // ������� �������� ������� ���������� �� ������ ������������� �����
		// ������ ������� ������,����������� ��� ������ �� m ����� �����

		while (!((k >= 1) && (k <= 2))){
			cout << "\n���� ������ ��������� ������ ����, �� ������� 1. ���� ������ ��������� ������ ���������� ������� - ������� 2: ";
			cin >> k;
			if ((k < 1) || (k>2))
				cout << "error" << endl;
			continue;
		}

		if (k == 1){
			cout << "\n������� �������� �������:\n";
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					cin >> mas[i][j];
		}
		if (k == 2){
			cout << "������� ������� ���������� ��������� �����:\n";
			cin >> a;
			cin >> b;
			cout << endl;
			if (a == b){
				for (i = 0; i < n; i++)
					for (j = 0; j < m; j++)
						mas[i][j] = a;
			}
			if (a != b){
				if (a > b){
					int temp = a;
					a = b;
					b = temp;
				}
				srand(time(NULL));
				for (i = 0; i < n; i++)
					for (j = 0; j < m; j++)
						mas[i][j] = a + rand() % (b - a + 1);
			}
			for (i = 0; i < n; i++){
				for (j = 0; j < m; j++){
					cout << "\t" << mas[i][j];
				}
				cout << endl;
			}
		}
		// ��������� � �������

		for (i = 0; i < n - 1; i++){
			for (int z = i + 1; z < n; z++){
				int sum = 0, sumNext = 0;
				for (j = 0; j < m; j++){
					sum += mas[i][j];
					sumNext += mas[z][j];
				}
				if (sum > sumNext){
					for (j = 0; j < m; j++){
						int temp = mas[i][j];
						mas[i][j] = mas[z][j];
						mas[z][j] = temp;
					}
				}
			}
		}
		cout << "\n��������������� �������:\n";
		for (i = 0; i < n; i++){
			for (j = 0; j < m; j++){
				cout << "\t" << mas[i][j];
			}
			cout << endl;
		}

		bool flag = false;
		for (i = 0; i < m; i++){
			flag = false;
			for (j = 0; j < n; j++){
				if (mas[j][i] < 0){
					flag = true;
					break;
				}
			}
			if (!flag){
				cout << "\n������� " << (i + 1) << " �� �������� ������������� ���������\n";
				break;
			}
		}
		if (flag){
			cout << "\n������� �� ����� �������� ��� ������������� ���������\n";
		}

		for (int i = 0; i < n; i++)
			delete[] mas[i];
		delete[] mas;
	}
	return 0;
}