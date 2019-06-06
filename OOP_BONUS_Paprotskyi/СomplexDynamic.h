#pragma once
//Double dispatch using dynamic cast
//Made by Ihor Paprotskyi, SE, 2nd year

class DynamicComplex;
class DynamicAComplex;

class DynamicComplex
{
public:
	virtual double& re() = 0;
	virtual double& im() = 0;
	virtual const double& re() const = 0;
	virtual const double& im() const = 0;

	virtual DynamicComplex& operator+=(DynamicComplex&) = 0;
};

class DynamicAComplex : public DynamicComplex
{
private:
	double _re, _im;
public:
	DynamicAComplex(double re, double im)
		:_re(re), _im(im) {}
	double& im() { return _im; }
	double& re() { return _re; }
	const double& im() const { return _im; }
	const double& re() const { return _re; }

	DynamicAComplex& operator+=(DynamicComplex& c)
	{
		if (DynamicAComplex* acomplex = dynamic_cast<DynamicAComplex*>(&c))
		{
			re() += acomplex->re();
			im() += acomplex->im();
			return *this;
		}
	};
};
