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
	������line���́Adelim�ƈ�v���Ȃ��ŏ��̕����̈ʒu��Ԃ��B�����̌�����spos����s��

	string::npos
	find�Œl��������Ȃ������Ƃ��ɕԂ��l
*/

double gravity_calc::get_stokes_coef(double n) {
	double stokes_coef[10][10] = { 0 };

	ifstream ifs("egm96.csv");
	string line;
	const string delim = ",";
	//��s�ڂ��擾(�w�b�_�s�Ȃ̂Ŏg��Ȃ�)
	getline(ifs, line);

	int row = 0;
	int col;

	//�s���擾�ł����烋�[�v���s
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