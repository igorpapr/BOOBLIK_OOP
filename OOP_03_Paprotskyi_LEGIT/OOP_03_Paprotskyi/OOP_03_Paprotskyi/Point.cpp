//Made by Ihor Paprotskyi, SE, 1 group

#include "Point.h"
//#define NDEBUG

std::ofstream Point::out("Point.txt");

int Point::freeID = 0;
int Point::_call = 0;


std::ostream& operator<<(std::ostream& os, const Point& u)
{
	os << '(' << u.x() << ", " << u.y() << ')';
	return os;
}

Point::Point(const double x, const double y) :
	_x(x), _y(y), pointID(++freeID)
{
	++_call;
#ifndef NDEBUG
	out << "Point " << pointID << " was created: " << *this << std::endl;
#endif
	return;
}

Point::Point(const Point& u) :
	_x(u._x), _y(u._y), pointID(++freeID)
{
	++_call;
#ifndef NDEBUG
	out << "Point " << pointID << " was copied: " << *this << std::endl;
#endif
	return;
}

Point::~Point()
{
	++_call;
#ifndef NDEBUG
	out << "Point " << pointID << " was deleted: " << *this << std::endl;
#endif
	return;
}

const Point operator+(const Point& u, const Point& v)
{
	return Point(u.x() + v.x(), u.y() + v.y());
}

Point& Point::operator= (const Point& p)
{
	++_call;
	_x = p.x();
	_y = p.y();
	return *this;
}

Point& operator+= (Point& x, const Point& y)
{
	x.x() += y.x();
	x.y() += y.y();
	return x;
}

bool is_equal(const double x, const double y) {
	return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
}

bool operator== (const Point & u, const Point &v)
{
	return (is_equal(u.x(), v.x()) && is_equal(u.y(), v.y()));
}

bool operator!= (const Point & u, const Point &v)
{
	return u == v ? false : true;
}

double Point::distanceTo(const Point& p) const
{
	++_call;
	double xx = _x - p.x();
	double yy = _y - p.y();
	return sqrt(xx*xx + yy * yy);
}

int Point::epilog()
{
	out << "N calls " << _call << " Total amount of created Points " << freeID << std::endl;
	return freeID;
}
