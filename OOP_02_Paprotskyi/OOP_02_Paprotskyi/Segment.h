#pragma once
#include "Point.h"
#include <iostream>
#include <cmath>
//*******************************************
//Every segment posesses its unique ID.
//In debug mode both constructor and destructor
//report the ID and the coordinates
//of a segment created or resp. deleted
//Developed by Ihor Paprotskyi
//on 02.02.2019
//*******************************************
class Segment
{
private:
	static int _freeID;
	const int _myId;
	// Start
	Point _a;
	// End
	Point _b;
public:
	// Constructors:
	// 1) using coordinates
	explicit Segment(const double x1 = 0, const double y1 = 0,
		const double x2 = 0, const double y2 = 0);
	// 2) using points
	Segment(const Point &start, const Point &end);
	// 3) copy
	Segment(const Segment&);
	// destructor
	~Segment();
	//=
	Segment& operator=(const Segment&);
	// Selectors of points
	const Point& start() const { return _a; };
	const Point& end() const { return _b; };
	// Selectors-modificators of points
	Point& start() { return _a; };
	Point& end() { return _b; };
	// Selectors of coordinates
	const double& startX() const { return _a.x(); };
	const double& startY() const { return _a.y(); };
	const double& endX() const { return _b.x(); };
	const double& endY() const { return _b.y(); };
	// Selectors-modificators of coordinates
	double& startX() { return _a.x(); };
	double& startY() { return _a.y(); };
	double& endX() { return _b.x(); };
	double& endY() { return _b.y(); };
	// Length of the segment
	double length() const;
	// Distance from point to segment
	double distance(const Point&) const;
	// selector of ID
	const int getID() const { return _myId; };
};

std::ostream& operator<<(std::ostream &, const Segment &);