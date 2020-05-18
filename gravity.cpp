#include "gravity.hpp"

using namespace std;
using namespace boost::numeric::ublas;

//�ʐ�n�܂ł̃X�g�[�N�X�W��������Ă���
matrix<double> gravity_calc::get_stokes_coef(int n) {
	matrix<double> Cnm(n + 1, n - 1);
	matrix<double> Snm(n + 1, n - 1);

	//�s��̏�����
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n - 1; j++) {
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
		Cnm(row, col - 2) = stod(line);

		getline(ifs, line, delim);
		Snm(row, col - 2) = stod(line);

		getline(ifs, line);
	}

	return Cnm, Snm;
};

double gravity_calc::Legendre(int n, int m, double x) {
	return 0;
};

double gravity_calc::geopotential(double S, double L) {
	return 0;
};