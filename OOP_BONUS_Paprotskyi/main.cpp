//Made by Ihor Paprotskyi, SE, 2nd year
#include <iostream>
#include "ÑomplexDynamic.h"
#include "Complex.h"
using namespace std;


int main()
{
	{
		AComplex a(12, 3), b(1, 1);
		cout << "Start: " << endl;
		cout << "re - " << a.re() << " im - " << a.im() << endl;

		cout << "a.operator+=(b):" << endl;
		a.operator+=(b);
		cout << "re - " << a.re() << " im - " << a.im() << endl;

		cout << "Use of double dispatch: " << endl;
		cout << "Pointer: " << endl;
		Complex *p = &a;
		cout << "re - " << p->re() << " im - " << p->im() << endl;
		*p += *p;
		cout << "re - " << p->re() << " im - " << p->im() << endl;

		cout << "Refference: a += a" << endl;
		Complex &r = a;
		cout << "re - " << r.re() << " im - " << r.im() << endl;
		r += r;
		cout << "re - " << r.re() << " im - " << r.im() << endl;
		cout << "A: re - " << a.re() << " im - " << a.im() << endl;
		cout << "Refference: a += b" << endl;
		Complex &rb = b;
		r += rb;
		cout << "re - " << r.re() << " im - " << r.im() << endl;
	}
	
	cout <<"\n= = = = = = USING DYNAMIC CAST= = = = = = "<<endl;
	DynamicAComplex a(12, 3), b(1, 1);
	cout << "Start: " << endl;
	cout << "re - " << a.re() << " im - " << a.im() << endl;

	cout << "a.operator+=(b):" << endl;
	a.operator+=(b);
	cout << "re - " << a.re() << " im - " << a.im() << endl;

	cout << "Use of double dispatch: " << endl;
	cout << "Pointer: " << endl;
	DynamicComplex *p = &a;
	cout << "re - " << p->re() << " im - " << p->im() << endl;
	*p += *p;
	cout << "re - " << p->re() << " im - " << p->im() << endl;

	cout << "Refference: a += a" << endl;
	DynamicComplex &r = a;
	cout << "re - " << r.re() << " im - " << r.im() << endl;
	r += r;
	cout << "re - " << r.re() << " im - " << r.im() << endl;
	cout << "A: re - " << a.re() << " im - " << a.im() << endl;
	cout << "Refference: a += b" << endl;
	DynamicComplex &rb = b;
	r += rb;
	cout << "re - " << r.re() << " im - " << r.im() << endl;

	return 0;
}