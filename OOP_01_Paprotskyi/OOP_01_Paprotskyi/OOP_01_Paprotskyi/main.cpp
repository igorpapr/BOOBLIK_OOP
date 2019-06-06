/*
* Made by Ihor Paprotskyi, SE, FI-2, 1 group
*/
#include <iostream>
using namespace std;
#include "point.h"

int main()
{
	Point a(1,2);
	Point b(2,3);
	Point c(4,5);
	cout<<a<<" + "<<b<<" = "<<a + b<<endl;
	cout<<"Amount of Points created: "<<Point::amount()<<endl;
	cout<< a <<" += "<< b;
	a += b;
	cout<<"  ->  "<<a<<", "<<b<<endl;
	cout<<"a"<<a<<" is now equal to c"<<c;
	a = c;
	cout<<": a = "<<a<<" , c = "<<c<<endl;
	cout<<"Is a equal to c? : "<< (a == c)<<endl;
	cout<<"Is a equal to b: "<<b<<" : "<<(a == b)<<endl;
	cout<<"Is a not equal to c: "<<(a != c)<<endl;
	cout<<"Is a not equal to b: "<<(a != b)<<endl;
	cout<<"The ID of Point a: "<<a.getID()<<endl;
	cout<<"The ID of Point b: "<<b.getID()<<endl;
	cout<<"The ID of Point c: "<<c.getID()<<endl;
	return 0;
}