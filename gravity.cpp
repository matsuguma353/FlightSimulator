#include "gravity.hpp"

using namespace std;
using namespace boost::numeric::ublas;

//次数nまでのストークス係数を取ってくる
void gravity_calc::get_stokes_coef(int n, matrix<double>& N, matrix<double>& M) {
	matrix<double> Cnm(n + 1, n - 1);
	matrix<double> Snm(n + 1, n - 1);

	//行列の初期化
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			Cnm(i, j) = 0;
			Snm(i, j) = 0;
		}
	}

	//csvファイルを開く
	ifstream ifs("egm96.csv");
	if (!ifs) {
		cout << "Cannot open file.\n";
	}
	string line;
	const char delim = ',';
	//一行目を取得(ヘッダ行なので使わない)
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

	N = Cnm;
	M = Snm;
};

void gravity_calc::Legendre(int n, double lat, matrix<double>& L) {
	matrix<double> Pnm(n + 1, n - 1);

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if ((i == 0) && (j == 0)) {
				Pnm(1,0)=
			}
			else {

			}
		}
	}

};

double gravity_calc::geopotential(double S, double L) {
	return 0;
};