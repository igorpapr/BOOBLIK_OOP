//Made by Ihor Paprotskyi, SE, 2 year
#include "AComplex.h"
#include "TComplex.h"
using namespace std;

//#define NDEBUG

int AComplex::_freeId = 0;

AComplex::AComplex(double re, double im) :
	_re(re), _im(im), _id(++_freeId)
{
#ifndef NDEBUG
	cout << "AComplex created : " << *this << "\t[A"<< _id <<"] "<< endl;
#endif // !NDEBUG
}

AComplex::AComplex(const TComplex &t) :
	_re(t.re()), _im(t.im()), _id(++_freeId)
{
#ifndef NDEBUG
	cout << "AComplex created from TComplex : " << *this << "\t[A" << _id <<']'<< endl;
#endif //!NDEBUG
}

AComplex::AComplex(const AComplex &a) :
	_re(a.re()), _im(a.im()), _id(++_freeId)
{
#ifndef NDEBUG
	cout << "AComplex copied : " << *this << "\t[A" << _id <<']'<< endl;
#endif //!NDEBUG
}

AComplex::~AComplex()
{
#ifndef NDEBUG
	cout << "AComplex deleted : " << *this << "\t[A" << _id <<']'<< endl;
#endif
}

AComplex& AComplex::operator=(const AComplex &a)
{
	_re = a.re();
	_im = a.im();
	return *this;
}

double AComplex::mod() const
{
	return sqrt(_re*_re + _im * _im);
}

double AComplex::arg() const
{
	return atan(_im / _re);
}

const AComplex AComplex::conj() const
{
	return AComplex(_re, -_im);
}

AComplex& operator+= (AComplex &a, const AComplex &b)
{
	a.re() += b.re();
	a.im() += b.im();
	return a;
}

AComplex& operator-= (AComplex &a, const AComplex &b)
{
	a.re() -= b.re();
	a.im() -= b.im();
	return a;
}

AComplex& operator*= (AComplex &a, const AComplex &b)
{
	double tempARe = a.re();
	double tempAIm = a.im();
	a.re() *= b.re();
	a.re() -= tempAIm * b.im();
	a.im() *= b.re();
	a.im() += tempARe * b.im();
	return a;
}

AComplex &operator/=(AComplex &a, const AComplex &b)
{
	double re = a.re();
	double im = a.im();
	a.re() *= b.re();
	a.re() += im * b.im();
	a.re() /= b.re()*b.re() + b.im()*b.im();
	a.im() *= b.re();
	a.im() -= re * b.im();
	a.im() /= (b.re()*b.re() + b.im()*b.im());
	return a;

}

const AComplex operator+(const AComplex &a, const AComplex &b)
{
	AComplex res(a);
	res += b;
	return res;
}

const AComplex operator- (const AComplex &a, const AComplex &b)
{
	AComplex res(a);
	return res -= b;
}

const AComplex operator* (const AComplex &a, const AComplex &b)
{
	AComplex res(a);
	return res *= b;
}

const AComplex operator/(const AComplex &a, const AComplex &b)
{
	AComplex res(a);
	return res /= b;
}

const AComplex power(const AComplex &a, unsigned int n)
{
	TComplex res(a);
	return power(res, n);
}

bool operator== (const AComplex &a, const AComplex &b)
{
	return a.re() == b.re() && a.im() == b.im();
}


bool operator!=(const AComplex &a, const AComplex &b)
{
	return !(a == b);
}

ostream& operator<<(ostream &out, const AComplex &a)
{
	return out << "(" << a.re() << (a.im() >= 0 ? "+" : "") << a.im() << "i)";
}

istream &operator>>(istream &in, AComplex &b)
{
	cout << "Input re: ";
	in >> b.re();
	cout << "Input im: ";
	in >> b.im();
	return in;
}