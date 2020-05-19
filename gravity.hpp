#pragma once

#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <boost/numeric/ublas/matrix.hpp>

using namespace boost::numeric::ublas;

class gravity_calc {
private:
	double GM = 398600.4415;
public:
	void get_stokes_coef(int n, matrix<double>& N, matrix<double>& M);
	double Legendre(int n, int m, double x);
	double geopotential(double S, double L);
};
