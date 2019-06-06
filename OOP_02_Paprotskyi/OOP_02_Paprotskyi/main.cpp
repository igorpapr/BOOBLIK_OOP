//Made by Ihor Paprotskyi, SE, 1 group
#include "Segment.h"
#include "Point.h"
#include <iostream>
using namespace std;

int main()
{
	Point p1(0, 1);
	Point p2(6.5, 1);
	Segment s1(p1, p2);

	Segment s2 = s1;
	
	cout << "\n= = = = = = = = = = = = = = = = = =" << endl;

	double x0(1);
	double y0(0);

	double x1(0);
	double y1(1);

	Segment s(x0, y0, x1, y1);
	
	cout << "The length of " << s << " is: " << s.length() << endl;

	cout << "\n= = = = = = = = = = = = = = = = = =" << endl;

	s.startX() = 1.5;
	s.startY() = 1.0;
	s.endX() = 5.0;
	s.endY() = 1.0;
	cout << "The length of " << s << " is: " << s.length() << endl;

	cout << "\n= = = = = = = = = = = = = = = = = =" << endl;

	Point p(3, 1);
	Point p3(3, 3.5);
	cout <<"The distance from "<<p<<" to "<<s<<" is: "<<s.distance(p) << endl;
	cout << "The distance from " << p1 << " to " << s << " is: " << s.distance(p1) << endl;
	cout << "The distance from " << p2 << " to " << s << " is: " << s.distance(p2) << endl;
	cout << "The distance from " << p3 << " to " << s << " is: " << s.distance(p3) << endl;

	cout << "\n= = = = = = =DESTRUCTORS= = = = = = =" << endl;
	return 0;
}