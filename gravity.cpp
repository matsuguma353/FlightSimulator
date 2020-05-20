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

	//行列の初期化
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			Pnm(i, j) = 0;
		}
	}

	//row(ルジャンドル陪関数の位数)を固定
	for (int row = 0; row < n + 1; row++) {
		//固定したrowでのルジャンドル陪関数Pnm(i,i),Pnm(i,i+1),Pnm(i,i+2),...を漸化式で計算していく
		for (int col = row; col < n - 2; col++) {
			//通常Pnm(row,row-1)から計算を始めるが、row=0のときPnm(0,-1)はPnmの範囲外なので、row=0のときのみ別で計算する
			if ((row == 0) && (col == 0)) {
				Pnm(row, col) = 1;                                      //Pnm(0, 0)
				Pnm(row, col + 1) = sin(lat) * Pnm(row, col);           //Pnm(0, 1)
			}
			else if (row == 0) {
				Pnm(row, col + 1) = ((2 * col + 1 - row) / (col + 1 - row)) * sin(lat) * Pnm(row, col) - ((col + row) / (col + 1 - row)) * Pnm(row, col - 1);
			}
			else if ((row != 0) && (col == row)) {
				Pnm(row, col) = 0;
				Pnm(row, col + 1) = semifactorial(2 * row - 1) * pow((1 - pow(sin(lat), 2)), row / 2);
			}
			else {
				Pnm(row, col + 1) = ((2 * col + 1 - row) / (col + 1 - row)) * sin(lat) * Pnm(row, col) - ((col + row) / (col + 1 - row)) * Pnm(row, col - 1);
			}
		}
	}

	L = Pnm;
};

double gravity_calc::geopotential(double r, double lat, double lon, int n, matrix<double> N, matrix<double> M) {
	double U = 0;
	//PnmはCnm,Snmと違ってそのときそのときのロケットの位置で変化するので、geopotentialを呼び出した時に計算するようにする
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
	for (int i = 2; i < n; i += 2) {
		n *= n - i;
	}

	return n;
}