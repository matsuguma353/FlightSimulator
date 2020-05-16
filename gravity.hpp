#pragma once

#include <cmath>
#include <string>
#include <iostream>
#include <fstream>

class gravity_calc {
private:
	double n;
	double m;
public:
	gravity_calc(double _n, double _m) :n(_n), m(_m) {}
	double get_stokes_coef() {};
	double Legendre(double n, double m, double x) {};
	double geopotential(double S, double L) {};
};
