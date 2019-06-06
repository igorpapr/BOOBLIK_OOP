#pragma once
#include "Point.h"
#include <iostream>
#include <cmath>
#include <fstream>

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
	static int _call;
	static std::ofstream out;

	static int _freeID;
	const int _myId;
	// Start
	const Point& _a;
	// End
	const Point& _b;

public:
	// Constructors:
	Segment(const Point &start, const Point &end);
	// 3) copy
	Segment(const Segment&);
	// destructor
	~Segment();
	// Selectors of points
	const Point& start() const;
	const Point& end() const;
	// Selectors of coordinates
	const double& startX() const { return _a.x(); };
	const double& startY() const { return _a.y(); };
	const double& endX() const { return _b.x(); };
	const double& endY() const { return _b.y(); };	
	// Length of the segment
	double length() const;
	// Distance from point to segment
	double distance(const Point&) const;
	// selector of ID
	const int getID() const { return _myId; };
	static int epilog();

};

std::ostream& operator<<(std::ostream &, const Segment &);