#include "gravity.hpp"

using namespace std;
using namespace boost::numeric::ublas;

//����n�܂ł̃X�g�[�N�X�W��������Ă���
void gravity_calc::get_stokes_coef(int n, matrix<double>& N, matrix<double>& M) {
	matrix<double> Cnm(n + 1, n + 1);
	matrix<double> Snm(n + 1, n + 1);

	//�s��̏�����
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			Cnm(i, j) = 0;
			Snm(i, j) = 0;
		}
	}

	//csv�t�@�C�����J��
	ifstream ifs("egm96.csv");
	if (!ifs) {
		cout << "Cannot open file.\n";
	}
	string line;
	const char delim = ',';
	//��s�ڂ��擾(�w�b�_�s�Ȃ̂Ŏg��Ȃ�)
	getline(ifs, line);

	int row = 0;
	int col = 0;

	for (int i = 0; i < n; i = row) {
		getline(ifs, line, delim);
		col = stoi(line);

		getline(ifs, line, delim);
		row = stoi(line);

		getline(ifs, line, delim);
		Cnm(row, col) = stod(line);

		getline(ifs, line, delim);
		Snm(row, col) = stod(line);

		getline(ifs, line);
	}

	N = Cnm;
	M = Snm;
};

void gravity_calc::Legendre(int n, double lat, matrix<double>& L) {
	matrix<double> Pnm(n + 1, n + 1);

	//�s��̏�����
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			Pnm(i, j) = 0;
		}
	}

	//row(���W�����h�����֐��̈ʐ�)���Œ�
	for (int row = 0; row < n + 1; row++) {
		if (row == 0) {
			Pnm(row, 0) = 1;
			Pnm(row, 1) = ((2 * 1 - 0) / (1 - 0)) * sin(lat) * Pnm(row, 0);
			for (int col = row + 2; col < n + 1; col++) {
				Pnm(row, col) = ((2 * col - 1) / (col - row)) * sin(lat) * Pnm(row, col - 1) - ((col + row - 1) / (col - row)) * Pnm(row, col - 2);
			}
		}
		else {
			double m = static_cast<double>(row) / 2;
			Pnm(row, row) = semifactorial(2 * row - 1) * pow(1 - pow(sin(lat), 2), m);
			for (int col = row + 1; col < n + 1; col++) {
				Pnm(row, col) = ((2 * col - 1) / (col - row)) * sin(lat) * Pnm(row, col - 1) - ((col + row - 1) / (col - row)) * Pnm(row, col - 2);
			}
		}
	}

	L = Pnm;
};

double gravity_calc::geopotential(double r, double lat, double lon, int n, matrix<double> N, matrix<double> M) {
	double U = 0;
	//Pnm��Cnm,Snm�ƈ���Ă��̂Ƃ����̂Ƃ��̃��P�b�g�̈ʒu�ŕω�����̂ŁAgeopotential���Ăяo�������Ɍv�Z����悤�ɂ���
	matrix<double> Pnm;

	Legendre(n, lat, Pnm);

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			U = pow(a / r, i) * Pnm(j, i) * (N(j, i) * cos(j * lon) + M(j, i) * sin(j * lon));
		}
	}

	U++;
	U = (GM / r) * U;

	return U;
};

int gravity_calc::semifactorial(int n) {
	int m;
	int i;

	if (n == 0) {
		m = n;

		return m;
	}
	else if ((n % 2) == 0) {
		m = 1;
		for (i = 2; i <= n;i += 2) {
			m = i * m;
		}

		return m;
	}
	else if((n % 2) == 1) {
		m = 1;
		for (int i = 1; i <= n; i += 2) {
			m = i * m;
		}

		return m;
	}
	else {
		cout << "error" << endl;

		return 0;
	}
}