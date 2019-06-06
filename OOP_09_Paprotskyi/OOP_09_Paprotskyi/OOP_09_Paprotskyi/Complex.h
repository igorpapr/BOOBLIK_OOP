#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class  Complex
{
private:
	double _re, _im;

public:
	Complex(double re = 0, double im = 0);
	Complex(const Complex & z) : _re(z._re), _im(z._im) {};
	~Complex() {};

	double re() const { return _re; }
	double im() const { return _im; }

	double& re() { return _re; }
	double& im() { return _im; }

	double mod() const { return sqrt(_re*_re + _im * _im); }
	double arg() const { return atan2(_im, _re); }

	const Complex& conj() { _im = -_im; return *this; }

	Complex& operator= (const Complex&);
};

ostream& operator<<(ostream &, const Complex &);

Complex& operator+=(Complex& a, const Complex& b);
Complex& operator*=(Complex& a, const Complex& b);

const Complex  operator+ (const Complex&, const Complex&);
const Complex  operator* (const Complex&, const Complex&);

bool operator== (const Complex&, const Complex&);
bool operator!= (const Complex&, const Complex&);