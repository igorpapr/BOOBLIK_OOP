//Made by Ihor Paprotskyi, SE, 1 group
#include "Segment.h"

std::ofstream Segment::out("Segment.txt");
int Segment::_freeID = 0;
int Segment::_call = 0;

std::ostream& operator<<(std::ostream& os, const Segment& u)
{
	os << '[' << u.start() << " <-> " << u.end() << ']';
	return os;
}


//points as parameters
Segment::Segment(const Point& start,const Point& end) :
	_a(start), _b(end), _myId(++_freeID)
{
	++_call;
#ifndef NDEBUG
	out << "Segment " << _myId << " was created: " << *this << std::endl;
#endif
	return;
}

//copy
Segment::Segment(const Segment& u) :
	_a(u._a), _b(u._b), _myId(++_freeID)
{
	++_call;
#ifndef NDEBUG
	out << "Segment " << _myId << " was copied: " << *this << std::endl;
#endif
	return;
}

//destructor
Segment::~Segment()
{
	++_call;
#ifndef NDEBUG
	out << "Segment " << _myId << " was deleted" << std::endl;
#endif
	return;
}

double Segment::length() const
{
	++_call;
	//added a new function distanceTo() in class Point
	return _b.distanceTo(_a);
}

int Segment::epilog()
{
	out << "N calls " << _call << " Total amount of created Segments " << _freeID << std::endl;
	return _freeID;
}

const Point& Segment::start() const
{
	++_call;
	return _a;
}
const Point& Segment::end() const
{
	++_call;
	return _b;
}

double Segment::distance(const Point& p) const
{
	++_call;
	//added a new function distanceTo in class Point 
	double startToP = _a.distanceTo(p);
	double endToP = _b.distanceTo(p);
	double startToEnd = _a.distanceTo(_b);
	if (endToP >= sqrt(startToP * startToP + startToEnd * startToEnd))
	{
		return startToP;
	}
	if (startToP >= sqrt(endToP * endToP + startToEnd * startToEnd))
	{
		return endToP;
	}
	double hf_prm = (startToP + endToP + startToEnd) / 2;
	return 2 * sqrt(hf_prm * (hf_prm - startToP) * (hf_prm - endToP) * (hf_prm - startToEnd)) / startToEnd;
}