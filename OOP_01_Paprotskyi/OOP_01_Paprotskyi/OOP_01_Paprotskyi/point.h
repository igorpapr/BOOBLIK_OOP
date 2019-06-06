#pragma once

#include <iostream>

//*******************************************
//Every point posesses its unique ID.
//In debug mode both constructor and destructor
//report the ID and the coordinates
//of a point created or resp. deleted
//Developed by Ihor Paprotskyi
//on 22.01.2019
//*******************************************

class Point
{
	private:
		static int freeID;
		const int pointID;
		double _x;
		double _y;
	public:
		Point (double x = 0, double y = 0);
		Point (const Point &);
		~Point();
		Point& operator= (const Point &);
		double& x(){return _x;};
		double& y(){return _y;};
		const double& x() const{return _x;};
		const double& y() const{return _y;};
		const int getID() const{return pointID;};
		static int amount(){return freeID;};
};

std::ostream& operator<< (std::ostream&, const Point&);
const Point operator+ (const Point & u, const Point & v);
Point& operator+= (Point &, const Point&);
bool operator== (const Point & u, const Point &v);
bool operator!= (const Point & u, const Point &v);