#include <cmath>
#include <string>
#include <iostream>
#include <fstream>

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

double gravity_calc::get_stokes_coef(double n) {
	double stokes_coef[10][10] = { 0 };

	ifstream ifs("egm96.csv");
	string line;
	const string delim = ",";

	int row = 0;
	int col;
};

double gravity_calc::Legendre(double n, double m, double x) {

};

double gravity_calc::geopotential(double S, double L) {

};