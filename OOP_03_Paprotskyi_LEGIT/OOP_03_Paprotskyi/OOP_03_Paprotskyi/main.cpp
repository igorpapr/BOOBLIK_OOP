//Made by Ihor Paprotskyi, SE, 1 group
#include "Triangle.h"

#include <iostream>
using namespace std;

int main()
{
	cout << "= = = = = = = = = = Creating triangle using coordinates = = = = = = = = = =" << endl;
	Triangle t(1,1,1,2,2,1);
	cout << "= = = Computing it's heights = = = " << endl;
	cout <<"Height_a: " <<t.height_a() <<", it's length: "<<t.height_a().length()<< endl;
	cout <<"Height_b: " << t.height_b() << ", it's length: " << t.height_b().length() << endl;
	cout <<"Height_c: " << t.height_c() << ", it's length: " << t.height_c().length() << endl;
	cout << "= = = = = = = = = = Creating three points and triangle using them = = = = = = = = = =" << endl;
	Point a(0,0);
	Point b(0, 3);
	Point c(3, 0);
	Triangle abc(a, b, c);
	cout <<"The length of side_a "<<abc.side_a()<<" is: "<< abc.length_a() << endl;
	cout << "The length of side_b " << abc.side_b() << " is: " << abc.length_b() << endl;
	cout << "The length of side_c " << abc.side_c() << " is: " << abc.length_c() << endl;
	

	abc = t;


	cout << "= = = = = = = = = = = = = = = = = = = =" << endl;
	cout << abc << endl;
	cout <<"Perimeter: "<<abc.perimeter() << endl;
	cout << "The area of " << abc << " is: " << abc.area() << endl;
	cout << "= = = = = = = = = = Copying the previous triangle = = = = = = = = = =" << endl;
	Triangle abcCopy = abc;
	cout << abcCopy << endl;
	cout << "= = = = = = = = = = Calls = = = = = = = = = =" << endl;
	cout << "Points: " << Point::epilog() << endl;
	cout << "Segments: " << Segment::epilog() << endl;
	cout << "Triangles: " << Triangle::epilog() << endl;
	return 0;
}