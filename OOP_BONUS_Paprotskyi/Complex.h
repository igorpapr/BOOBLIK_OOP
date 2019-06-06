//Made by Ihor Paprotskyi, SE, 2nd year
//Multiple dispatch
#pragma once

class AComplex;

class Complex
{
public:
	virtual double& re() = 0;
	virtual double& im() = 0;
	virtual const double& re() const = 0;
	virtual const double& im() const = 0;

	virtual Complex& operator+=(const Complex&) = 0; //dispatcher function
	
	virtual void add_assign(AComplex&) const = 0;

};

class AComplex: public Complex
{
private:
	double _re, _im;
public:
	AComplex(double re, double im)
		:_re(re), _im(im){}
	double& im(){return _im;}
	double& re(){return _re;}
	const double& im() const{return _im;}
	const double& re() const{return _re;}


	virtual AComplex& operator+=(const Complex& c) //dispatcher function
	{
		c.add_assign(*this);
		return *this;
	};

	virtual void add_assign(AComplex& c) const
	{
		c._re += re();
		c._im += im();
		return;
	};

};