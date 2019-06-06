/*
* Made by Ihor Paprotskyi, SE, FI-2, 1 group
*/
#include "point.h"

//#define NDEBUG

int Point::freeID = 0;


ostream& operator<<(ostream& os, const Point& u) 
{
	os<<'('<<u.x()<<", "<<u.y()<<')';
	return os;
}

Point::Point(const double x, const double y):
	_x(x), _y(y), pointID(++freeID) 
{
	#ifndef NDEBUG
		cout<<"Point: "<<*this<<" with ID: "<<pointID<<" has been created."<<endl;
	#endif
	return;
}

Point::Point(const Point& u):
	_x(u._x), _y(u._y), pointID(++freeID)
{
	#ifndef NDEBUG
		cout<<"Point: "<<*this<<" with ID: "<<pointID<<" has been copied."<<endl;
	#endif
	return;
}

Point::~Point()
{
	#ifndef NDEBUG
		cout<<"Point: "<<*this<<" with ID: "<<pointID<<" has been removed "<<endl;
	#endif
	return;
}

const Point operator+(const Point& u, const Point& v) 
{
	return Point(u.x()+v.x(), u.y()+v.y());
}

Point& Point::operator= (const Point& p)
{
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

bool operator== (const Point & u, const Point &v)
{
	return (u.x() == v.x()) && (u.y() == v.y());
}

bool operator!= (const Point & u, const Point &v)
{
	return u==v ? false : true;
}