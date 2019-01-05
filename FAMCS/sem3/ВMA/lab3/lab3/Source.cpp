#include "resources.h"

int main(int argc, char argv[]) {
	setlocale(LC_ALL, ".1251");
	const int n = 10;
	try {
		ifstream fin("input.txt");
		pair<matrix<double>, vector<double>> buff = create(n, fin);
		matrix<double> A(buff.first);
		vector<double> xSource(buff.second);
		fin.close();

		ofstream fout("output.txt", ios_base::trunc);
		fout << "������� A:" << endl;
		print(A, fout);
		fout << "\n\n������ x:" << endl;
		print(xSource, fout);
		vector<double> f = prod(A, xSource);
		fout << "\n\n\n������ ������ ����� f:" << endl;
		print(f, fout);
		fout << "\n\n\n�������� A ����� �� � �����������������:" << endl;
		print(A = prod(trans(A), buff.first), fout);
		fout << "\n\n��������� ������ �����:" << endl;
		print(f = prod(trans(buff.first), f), fout);
		matrix<double> B(identity_matrix<double>(n) - A / norm_1(A));
		fout << "\n\n������� �:" << endl;
		print(B, fout);
		vector<double> g(f / norm_1(A));
		fout << "\n\n������ g:" << endl;
		print(g, fout);

		fout << "\n\n����� �:\n" << norm_1(B) << endl;

		double eps = pow(10, -7);
		vector<double> xNext(g.size()), x(g);
		/*size_t k = 0;
		while (true) {
			k++;
			xNext = prod(B, x) + g;
			if (norm_1(xNext - x) <= eps)
				break;
			x = xNext;
		}
		fout << "\n\n������ x:" << endl;
		printf(xNext, fout);
		fout << "\n\n������ x(��������):" << endl;
		print(xSource, fout);
		fout << "\n\n��������� ��������:\n	" << k << endl;
*/
		fout << "\n\n!!����� ����������!!\n\n";
		for (size_t i(0); i < B.size1(); i++) {
			for (size_t j(0); j < B.size2(); j++)
				if (i == j)
					B(i, j) = 0;
				else
					B(i, j) = -A(i, j) / A(i, i);
			g(i) = f(i) / A(i, i);
		}
		fout << 'q' << separator << 'k' << endl;
		for (double q = 0.1; q < 2.0; q += 0.1)
			fout << q << separator << relaxation_method(B, g, q, eps) << endl;
		fout << "\n�������� q:\n" << 'q' << separator << 'k' << endl;
		for (double q = 1.8; q < 2.0; q += 0.01)
			fout << q << separator << relaxation_method(B, g, q, eps) << endl;
		double q = 1.0;
		x = g;
		while (true) {
			for (size_t i(0); i < x.size(); i++) {
				double temp = 0.0;
				for (size_t j(0); j < i; j++)
					temp += B(i, j)*xNext(j);
				for (size_t j(i + 1); j < x.size(); j++)
					temp += B(i, j)*x(j);
				xNext(i) = (1.0 - q)*x(i) + q*(temp + g(i));
			}
			if (norm_1(xNext - x) <= q*eps)
				break;
			x = xNext;
		}
		fout << "\n\n������ x:" << endl;
		printf(xNext, fout);
		fout << "\n\n������ x(��������):" << endl;
		print(xSource, fout);
		fout.close();
	}
	catch (exception& e) { cerr << e.what() << endl; }
	return 0;
}


size_t relaxation_method(matrix<double> B, vector<double> g, const double q, const double eps) {
	vector<double> x(g), xNext(g.size());
	for (size_t k = 1;; k++) {
		for (size_t i(0); i < x.size(); i++) {
			double temp = 0.0;
			for (size_t j(0); j < i; j++)
				temp += B(i, j)*xNext(j);
			for (size_t j(i + 1); j < x.size(); j++)
				temp += B(i, j)*x(j);
			xNext(i) = (1.0 - q)*x(i) + q*(temp + g(i));
		}
		if (norm_1(xNext - x) <= q*eps)
			return k;
		x = xNext;
	}
}
