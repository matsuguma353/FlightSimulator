#include "gravity.hpp"

using namespace std;

/*
	line.find_first_not_of(delim, spos)
	文字列line中の、delimと一致しない最初の文字の位置を返す。文字の検索はsposから行う

	string::npos
	findで値が見つからなかったときに返す値
*/

//位数9までのストークス係数を取ってくる
double gravity_calc::get_stokes_coef() {
	double Cnm[10][10] = { 0 };
	double Snm[10][10] = { 0 };

	//csvファイルを開く
	ifstream ifs("egm96.csv");
	string line;
	const string delim = ",";
	//一行目を取得(ヘッダ行なので使わない)
	getline(ifs, line);

	int row;
	int col;

	//行が取得できたらループ続行
	while (getline(ifs, line)) {

		/*
			find_first_not_ofで値が見つからなかったとき、nposが返ってくる。
			文字列をeposの位置から検索して、","と異なる文字が出てくる最初の位置を返す。
			もし","と異なる文字が出てくる最初の位置がない(=文字列に","が含まれない)時はnposが返ってきて、そこでforループが終了する
		*/

		string::size_type epos = 0;
		string::size_type spos = line.find_first_not_of(delim, epos);

		string token = line.substr(spos, (epos = line.find_first_of(delim, spos)) - spos);
		col = stoi(token) - 2;




		for (string::size_type spos, epos = 0; (spos = line.find_first_not_of(delim, epos)) != string::npos;) {
			string token = line.substr(spos, (epos = line.find_first_of(delim, spos)) - spos);

			if (token.length != 1) {

			}

			
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