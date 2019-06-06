//Made by Ihor Paprotskyi, SE, 1 group
#include "Segment.h"

int Segment::_freeID = 0;

std::ostream& operator<<(std::ostream& os, const Segment& u)
{
	os << '[' << u.start() << " <-> " << u.end() << ']';
	return os;
}


//coordinates as parameters
Segment::Segment(const double x1, const double y1,
	const double x2, const double y2):
	_a(x1, y1), _b(x2, y2), _myId(++_freeID)
{
#ifndef NDEBUG
	std::cout << "Segment " << _myId << " was created: " << *this << std::endl;
#endif
	return;
}


//points as parameters
Segment::Segment(const Point& start, const Point& end):
	_a(start), _b(end), _myId(++_freeID)
{
#ifndef NDEBUG
	std::cout << "Segment " << _myId << " was created: " << *this << std::endl;
#endif
	return;
}

//copy
Segment::Segment(const Segment& u):
	_a(u._a), _b(u._b), _myId(++_freeID)
{
#ifndef NDEBUG
	std::cout << "Segment " << _myId << " was copied: " << *this << std::endl;
#endif
	return;
}

//destructor
Segment::~Segment()
{
#ifndef NDEBUG
	std::cout << "Segment " << _myId << " was deleted"<<std::endl;
#endif
	return;
}

Segment& Segment::operator=(const Segment& x)
{
	_a = x._a;
	_b = x._b;
	return *this;
}

double Segment::length() const
{
	//added a new function distanceTo() in class Point
	return _b.distanceTo(_a);
}


double Segment::distance(const Point& p) const
{
	//added a new function distanceTo in class Point 
	double startToP = _a.distanceTo(p);
	double endToP = _b.distanceTo(p);
	double startToEnd = _a.distanceTo(_b);
	if (startToP >= sqrt(endToP * endToP + startToEnd * startToEnd)) {
		return endToP;
	}
	if (endToP >= sqrt(startToP * startToP + startToEnd * startToEnd)) {
		return startToP;
	}
	double hf_prm = (startToP + endToP + startToEnd) / 2;
	return 2 * sqrt(hf_prm * (hf_prm - startToP) * (hf_prm - endToP) * (hf_prm - startToEnd)) / startToEnd;
}