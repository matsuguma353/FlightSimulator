#include "gravity.hpp"

using namespace std;

/*
	line.find_first_not_of(delim, spos)
	������line���́Adelim�ƈ�v���Ȃ��ŏ��̕����̈ʒu��Ԃ��B�����̌�����spos����s��

	string::npos
	find�Œl��������Ȃ������Ƃ��ɕԂ��l
*/

//�ʐ�9�܂ł̃X�g�[�N�X�W��������Ă���
double gravity_calc::get_stokes_coef() {
	double Cnm[10][10] = { 0 };
	double Snm[10][10] = { 0 };

	//csv�t�@�C�����J��
	ifstream ifs("egm96.csv");
	string line;
	const string delim = ",";
	//��s�ڂ��擾(�w�b�_�s�Ȃ̂Ŏg��Ȃ�)
	getline(ifs, line);

	int row;
	int col;

	//�s���擾�ł����烋�[�v���s
	while (getline(ifs, line)) {

		/*
			find_first_not_of�Œl��������Ȃ������Ƃ��Anpos���Ԃ��Ă���B
			�������epos�̈ʒu���猟�����āA","�ƈقȂ镶�����o�Ă���ŏ��̈ʒu��Ԃ��B
			����","�ƈقȂ镶�����o�Ă���ŏ��̈ʒu���Ȃ�(=�������","���܂܂�Ȃ�)����npos���Ԃ��Ă��āA������for���[�v���I������
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