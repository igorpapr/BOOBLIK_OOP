//Made by Ihor Paprotskyi, SE, 1 group
#include "Triangle.h"
#include <cassert>

int Triangle::_call = 0;
std::ofstream Triangle::out("Triangle.txt");

Triangle::Triangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3):
	_a(x1, y1), _b(x2, y2), _c(x3, y3),
	_ab(nullptr), _bc(nullptr), _ca(nullptr),
	
	_base_a(0,0),_base_b(0, 0),_base_c(0, 0),//UNCORRECT, HOW TO IMPROVE???

	_height_a(nullptr), _height_b(nullptr), _height_c(nullptr)
{
	++_call;
	assert(area() != 0);
#ifndef NDEBUG
	out << "Created: " << *this << std::endl;
#endif
}

Triangle::Triangle(const Point &a, const Point &b, const Point &c) :
	_a(a), _b(b), _c(c), 
	_ab(nullptr), _bc(nullptr), _ca(nullptr),
	_base_a(0, 0), _base_b(0, 0), _base_c(0, 0),
	_height_a(nullptr), _height_b(nullptr), _height_c(nullptr)
{
	++_call;
	assert(area() != 0);
#ifndef NDEBUG
	out <<"Created: " << *this << std::endl;
#endif
}

Triangle::Triangle(const Point &a, const Segment &bc) :
	_a(a), _b(bc.start()), _c(bc.end()), 
	_ab(nullptr), _bc(nullptr), _ca(nullptr),
	_base_a(0, 0), _base_b(0, 0), _base_c(0, 0),
	_height_a(nullptr), _height_b(nullptr), _height_c(nullptr)
{
	++_call;
	assert(area() != 0);
#ifndef NDEBUG
	out << "Created: " << *this << std::endl;
#endif
}

Triangle::Triangle(const Triangle &t) :
	_a(t.apexA()), _b(t.apexB()), _c(t.apexC()),
	_ab(nullptr), _bc(nullptr), _ca(nullptr), 
	_base_a(t.base_a()), _base_b(t.base_b()), _base_c(t.base_c()),
	_height_a(nullptr), _height_b(nullptr), _height_c(nullptr)
{
	++_call;
#ifndef NDEBUG
	out << "Copied: " << *this << std::endl;
#endif
}

Triangle::~Triangle()
{
	++_call;

	delete _ab;
	delete _bc;
	delete _ca;

	delete _height_a;
	delete _height_b;
	delete _height_c;

	_ab = nullptr;
	_bc = nullptr;
	_ca = nullptr;

	_height_a = nullptr;
	_height_b = nullptr;
	_height_c = nullptr;
}

Triangle &Triangle::operator=(const Triangle &t)
{
	++_call;
	
	//delete this; //UNCORRECT!!! 
	
	//NOW MB CORRECT

	delete _ab;
	delete _bc;
	delete _ca;
	
	delete _height_a;
	delete _height_b;
	delete _height_c;

	_ab = nullptr;
	_bc = nullptr;
	_ca = nullptr;

	_height_a = nullptr;
	_height_b = nullptr;
	_height_c = nullptr;

	_a = t.apexA();
	_b = t.apexB();
	_c = t.apexC();
	
	_base_a = t.base_a();
	_base_b = t.base_b();
	_base_c = t.base_c();
	
	return *this;
}


double Triangle::perimeter() const
{
	++_call;
	return length_a() + length_b() + length_c();
}


double Triangle::area() const
{
	++_call;
	return 0.5 * length_a() * height_a().length();
}


const Segment& Triangle::side_a() const
{
	++_call;
	if (!_bc) {
		_bc = new Segment(_b, _c);
	}
	return *_bc;
}


const Segment& Triangle::side_b() const
{
	++_call;
	if (!_ca) 
	{
		_ca = new Segment(_c, _a);
	}
	return *_ca;
}


const Segment& Triangle::side_c() const
{
	++_call;
	if (!_ab) 
	{
		_ab = new Segment(_a, _b);
	}
	return *_ab;
}

double Triangle::length_a() const
{
	++_call;
	return side_a().length();
}

double Triangle::length_b() const
{
	++_call;
	return side_b().length();
}

double Triangle::length_c() const
{
	++_call;
	return side_c().length();
}

std::ostream &operator<<(std::ostream &os, const Triangle &t)
{
	return os << "Triangle: {" << t.apexA() << ' ' << t.apexB() << ' ' << t.apexC() << "}";
}


//by finding the coefficient and applying it to the line equation
void calculateHeightBase(const Segment *side, const Point &startP, Point& endP)
{
	double fmultiplier_x = side->end().y() - side->start().y();
	double fmultiplier_y = side->start().x() - side->end().x();
	double tempMultiplier = (side->end().y() * side->start().x() - side->start().y() * side->end().x() + startP.x() *
							side->start().y() - side->end().y() * startP.x() +
							side->end().x()*startP.y() - side->start().x()*startP.y())
							/ (fmultiplier_x * fmultiplier_x + fmultiplier_y * fmultiplier_y);
	endP.x() = startP.x() + fmultiplier_x * tempMultiplier;
	endP.y() = startP.y() + fmultiplier_y * tempMultiplier;
}

const Segment& Triangle::height_a() const
{
	++_call;
	if (!_height_a)
	{
		calculateHeightBase(&side_a(), _a, _base_a);
		_height_a = new Segment(_a, _base_a);
	}
	return *_height_a;
}

int Triangle::epilog()
{
	out << "N calls " << _call << std::endl;
	return _call;
}

const Segment& Triangle::height_b() const
{
	++_call;
	if (!_height_b)
	{
		calculateHeightBase(&side_b(), _b, _base_b);
		_height_b = new Segment(_b, _base_b);
	}
	return *_height_b;
}

const Segment& Triangle::height_c() const
{
	++_call;
	if (!_height_c)
	{
		calculateHeightBase(&side_c(), _c, _base_c);
		_height_c = new Segment(_c, _base_c);
	}
	return *_height_c;
}