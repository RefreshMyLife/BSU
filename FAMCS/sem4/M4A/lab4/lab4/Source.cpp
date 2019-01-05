#include "resources.h"


int main(int argc, char argv[]) {
	setlocale(LC_ALL, ".1251");
	ofstream fout("output.txt", ios_base::trunc);
	if (!fout.good())
		throw exception("");
	fout << fixed << setprecision(13);

	const double eps = pow(10, -5);
	double(*method)(int) = nullptr;

	method = leftRectagle;
	fout << "����� ���������������:\n";
	double temp = runge(eps, method, 1, fout);
	fout << "����������� ��������: "<<temp << endl << "�����������: "<<temp - f_exacly();

	method = trapeze;
	fout << "\n\n��������:\n";
	temp = runge(eps, method, 2, fout);
	fout << "����������� ��������: " <<temp << endl << "�����������: " <<temp - f_exacly();
	//fout << runge(eps, method, 2, fout) << endl;

	method = simpson;
	fout << "\n\n��������:\n";
	temp = runge(eps, method, 4, fout);
	fout << "����������� ��������: "<<temp << endl << "�����������: "<<temp - f_exacly();
	//fout << runge(eps, method, 4, fout) << endl;

	temp = 2 * f_t(0);
	fout << "\n\n\n���� n = 0:\n";
	fout << "����������� ��������: " << temp << endl << "�����������: " << temp - f_exacly();

	temp = f_t(-1.0 / sqrt(3)) + f_t(1.0 / sqrt(3));
	fout << "\n\n���� n = 1:\n";
	fout << "����������� ��������: " << temp << endl << "�����������: " << temp - f_exacly();

	temp = 5.0 / 9.0*f_t(-sqrt(3.0 / 5.0)) + 8.0 / 9.0*f_t(0) +	5.0 / 9.0*f_t(sqrt(3.0 / 5.0));
	fout << "\n\n���� n = 2:\n";
	fout << "����������� ��������: " << temp << endl << "�����������: " << temp - f_exacly();

	fout.close();
	return 0;
}


double runge(const double eps, double(*method)(int), int m, ofstream& out) {
	int N = 1;
	double I, I_next, alpha;
	do {
		I = method(N);
		I_next = method(2 * N);
		alpha = (I_next - I) / (pow(h(N), m) - pow(h(2 * N), m));
		N *= 2;
	} while (fabs(I_next - I) / (pow(2, m) - 1) > eps);
	out << "N = " << N << endl;
	return I_next + alpha*pow(h(N), m);
}


double leftRectagle(int N) {
	double sum = 0.0;
	for (int i = 0; i < N; i++)
		sum += f(x(i, N));
	return sum * h(N);
}


double trapeze(int N) {
	double sum = 0.5*(f(x(0, N)) + f(x(N, N)));
	for (int i = 1; i < N; i++)
		sum += f(x(i, N));
	return sum*h(N);
}


double simpson(int N) {
	double sum = 0.0;
	for (int i = 1; i < N; i += 2)
		sum += f(x(i - 1, N)) + 4 * f(x(i, N)) + f(x(i + 1, N));
	return sum*h(N) / 3;
}


double f(double x) {
	if (x == 0.0)
		return 1.0;
	else
		return log(1 + x) / x;
}


double f_t(double t) {
	if (t == -1)
		return 0.5;
	else
		return log(0.5*(3 + t)) / (t + 1);
}



double x(int i, int N) { return h(N)*i; }


double h(int N) { return 1.0 / N; }
