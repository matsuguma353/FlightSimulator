#include <cmath>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class gravity_calc {
private:
	double n;
	double m;
public:
	gravity_calc(double _n, double _m) :n(_n), m(_m) {};
	double get_stokes_coef(double n);
	double Legendre(double n, double m, double x);
	double geopotential(double S, double L);
};

/*
	line.find_first_not_of(delim, spos)
	文字列line中の、delimと一致しない最初の文字の位置を返す。文字の検索はsposから行う

	string::npos
	findで値が見つからなかったときに返す値
*/

double gravity_calc::get_stokes_coef(double n) {
	double stokes_coef[10][10] = { 0 };

	ifstream ifs("egm96.csv");
	string line;
	const string delim = ",";
	//一行目を取得(ヘッダ行なので使わない)
	getline(ifs, line);

	int row = 0;
	int col;

	//行が取得できたらループ続行
	while (getline(ifs, line)) {
		col = 0;
		for (string::size_type spos, epos = 0; (spos = line.find_first_not_of(delim, epos)) != string::npos;) {

		}

	}

	return 0;
};

double gravity_calc::Legendre(double n, double m, double x) {
	return 0;
};

double gravity_calc::geopotential(double S, double L) {
	return 0;
};