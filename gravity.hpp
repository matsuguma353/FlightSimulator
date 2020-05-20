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
	double a = 6378137;
public:
	void get_stokes_coef(int n, matrix<double>& N, matrix<double>& M);
	void Legendre(int n, double lat, matrix<double>& L);
	double geopotential(double r, double lat, double lon, int n, matrix<double> N, matrix<double> M);
	int semifactorial(int n);
};
