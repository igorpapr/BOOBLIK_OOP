//Made by Ihor Paprotskyi, SE, 2 year
#include "AComplex.h"
#include "TComplex.h"
using namespace std;

//#define NDEBUG

int TComplex::_freeId = 0;

TComplex::TComplex(double ro, double phi) : _ro(ro), _phi(phi), _id(++_freeId)
{
#ifndef NDEBUG
	cout << "TComplex created :" << *this << "\t[T" << _id <<']' << endl;
#endif //!NDEBUG
}

TComplex::TComplex(const TComplex &a) : _ro(a.mod()), _phi(a.arg()), _id(++_freeId)
{
#ifndef NDEBUG
	cout << "TComplex copied :" << *this << "\t[T" << _id <<']'<<endl;
#endif //!NDEBUG
}

TComplex::TComplex(const AComplex &a) : _ro(a.mod()), _phi(a.arg()), _id(++_freeId)
{
#ifndef NDEBUG
	cout << "TComplex created from AComplex :" << *this << "\t[T" << _id <<']'<< endl;
#endif //!NDEBUG
}

TComplex::~TComplex()
{
#ifndef NDEBUG
	cout << "TComplex deleted : " << *this << "\t[T" << _id <<']'<< endl;
#endif //!NDEBUG
}

TComplex &TComplex::operator=(const TComplex &a)
{
	_ro = a.mod();
	_phi = a.arg();
	return *this;
}

double TComplex::re() const
{
	return _ro * cos(_phi);
}

double TComplex::im() const
{
	return _ro * sin(_phi);
}

TComplex& operator+= (TComplex &a, const TComplex &b)
{
	AComplex aACompl(a);
	AComplex bACompl(b);
	aACompl += bACompl;
	a = aACompl;
	return a;
}

TComplex& operator-= (TComplex &a, const TComplex &b)
{
	AComplex aACompl(a);
	AComplex bACompl(b);
	aACompl -= bACompl;
	a = aACompl;
	return a;
}

TComplex& operator*= (TComplex &a, const TComplex &b)
{
	a.mod() *= b.mod();
	a.arg() += b.arg();
	return a;
}

TComplex& operator/= (TComplex &a, const TComplex &b)
{
	a.mod() /= b.mod();
	a.arg() -= b.arg();
	return a;
}


const TComplex operator* (const TComplex &a, const TComplex &b)
{
	TComplex res(a);
	return res *= b;
}

const TComplex operator/ (const TComplex &a, const TComplex &b)
{
	TComplex res(a);
	return res /= b;
}

const TComplex power(const TComplex &a, unsigned int n)
{
	double ro = pow(a.mod(), n);
	double phi = a.arg()*n;
	return TComplex(ro, phi);
}


ostream& operator<<(ostream &out, const TComplex &a)
{
	return out << a.mod() << "(cos(" << a.arg() << ")" << " + isin(" << a.arg() << "))";
}

istream& operator>>(istream &in, TComplex &t)
{
	cout << "Input mod: ";
	in >> t.mod();
	cout << "Input arg: ";
	in >> t.arg();
	return in;
}