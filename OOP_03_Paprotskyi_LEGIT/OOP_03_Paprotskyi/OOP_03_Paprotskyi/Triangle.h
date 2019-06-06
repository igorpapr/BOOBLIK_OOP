#pragma once
#include "Segment.h"
#include "Point.h"
#include <fstream>

//*******************************************
//    Lab task 4
//    Developed by Ihor Paprotskyi
//    at 09.02.2019
//*******************************************
class Point;
class Segment;

class Triangle
{
private:
	static std::ofstream out;
	static int _call;

	mutable Point _a, _b, _c;
	mutable Segment *_ab, *_bc, *_ca;
	mutable Point _base_a, _base_b, _base_c;
	mutable Segment *_height_a, *_height_b, *_height_c;
	
public:
	Triangle(const double x1 = 0, const double y1 = 0,
		const double x2 = 1, const double y2 = 0,
		const double x3 = 0, const double y3 = 1);
	Triangle(const Point &a, const Point& b, const Point& c);
	Triangle(const Point &a, const Segment &_bc);
	
	Triangle(const Triangle&);
	~Triangle();
	Triangle& operator= (const Triangle&);
	
	double perimeter() const;
	double area() const;
	//Apexes
	const Point& apexA() const { return _a; };
	const Point& apexB() const { return _b; };
	const Point& apexC() const { return _c; };
	// Sides
	const Segment& side_a() const;
	const Segment& side_b() const;
	const Segment& side_c() const;
	// Lengths of sides
	double length_a() const;
	double length_b() const;
	double length_c() const;
	// Heights
	const Segment& height_a() const;
	const Segment& height_b() const;
	const Segment& height_c() const;

	// Bases
	const Point& base_a() const { return _base_a; };
	const Point& base_b() const { return _base_b; };
	const Point& base_c() const { return _base_c; };
	
	static int epilog();
};
std::ostream& operator<<(std::ostream &, const Triangle &);