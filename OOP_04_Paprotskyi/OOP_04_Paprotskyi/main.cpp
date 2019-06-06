//Made by Ihor Paprotskyi, SE, 2 year
#include <iostream>
#include "TComplex.h"
#include "AComplex.h"
using namespace std;

int main()
{
	const double PI = 3.1415926535897932;

	cout<<"= = = = = =Creating complex instances= = = = = ="<<endl;
	AComplex a(1.11, 2.22);
	AComplex a1(1.5, 3.14);	

	TComplex t(1.11, 2.22);
	TComplex t1(1.5, 3.14);
	
	cout << "\n= = = = = =Copying and Assignment= = = = = =" << endl;
	AComplex a2(a);
	AComplex a3 = a1;

	TComplex t2(t);
	TComplex t3 = t1;
	
	cout << "\n= = = = = =Creating AComplex from AComplex and vice versa= = = = = =" << endl;
	TComplex t4(a);
	AComplex a4(t);

	cout << "\n\n= = = = = =Addition= = = = = =" << endl;
	cout << "- - - - - -A to A- - - - - -" << endl;
	cout << a << " + " << a1 << " = " << (a + a1) << endl;
	cout << "\n- - - - - -A to T- - - - - -" << endl;
	cout << a << " + " << t << " = " << (a + t) << endl;
	cout << "\n- - - - - -T to A- - - - - -" <<endl;
	cout << t << " + " << a << " = " << (t + a) << endl;
	cout << "\n- - - - - -T to T- - - - - -" << endl;
	cout << t << " + " << t1 << " = " << (t + t1) << endl;

	cout << "\n\n= = = = = =Subtraction= = = = = =" << endl;
	cout << "- - - - - -A from A- - - - - -" << endl;
	cout << a << " - " << a1 << " = " << (a - a1) << endl;
	cout << "\n- - - - - -A from T- - - - - -" << endl;
	cout << a << " - " << t << " = " << (a - t) << endl;
	cout << "\n- - - - - -T from A- - - - - -" << endl;
	cout << t << " - " << a << " = " << (t - a) << endl;
	cout << "\n- - - - - -T from T- - - - - -" << endl;
	cout << t << " - " << t1 << " = " << (t - t1) << endl;

	cout << "\n\n= = = = = =Multiplication= = = = = =" << endl;
	cout << "- - - - - -A by A- - - - - -" << endl;
	cout << a << " * " << a1 << " = " << (a * a1) << endl;
	cout << "\n- - - - - -A by T- - - - - -" << endl;
	cout << a << " * " << t << " = " << (a * t) << endl;
	cout << "\n- - - - - -T by A- - - - - -" << endl;
	cout << t << " * " << a << " = " << (t * a) << endl;
	cout << "\n- - - - - -T by T- - - - - -" << endl;
	cout << t << " * " << t1 << " = " << (t * t1) << endl;

	cout << "\n\n= = = = = =Division= = = = = =" << endl;
	cout << "- - - - - -A by A- - - - - -" << endl;
	cout << a << " / " << a1 << " = " << (a / a1) << endl;
	cout << "\n- - - - - -A by T- - - - - -" << endl;
	cout << a << " / " << t << " = " << (a / t) << endl;
	cout << "\n- - - - - -T by A- - - - - -" << endl;
	cout << t << " / " << a << " = " << (t / a) << endl;
	cout << "\n- - - - - -T by T- - - - - -" << endl;
	cout << t << " / " << t1 << " = " << (t / t1) << endl;


	cout << "\n\n= = = = = =Addition + Assignment= = = = = =" << endl;
	cout << (a += a1) << endl;
	cout << "\n= = = = = =Subtraction + Assignment= = = = = =" << endl;
	cout << (a -= t1) << endl;
	cout << "\n= = = = = =Multiplication + Assignment= = = = = =" << endl;
	cout << (t1 *= a) << endl;
	cout << "\n= = = = = =Division + Assignment= = = = = =" << endl;
	cout << (t1 / t) << endl;

	cout <<"\n\n= = = = = = =Operators of equality and inequality= = = = = = ="<< endl;
	TComplex tt1(1.123213123, PI / 4); //first test
	AComplex aa1(tt1);

	AComplex aa2(1, 1); //second test
	AComplex aa3(aa2);

	TComplex tt2(1, 1); //third test
	TComplex tt3(tt1);

	cout << endl;
	cout << aa1 << " == " << tt1 << ": " << ((aa1 == tt1) ? "EQUAL" : "NOT EQUAL") << endl;
	cout << endl;
	cout << aa2 << " == " << aa3 << ": " << ((aa2 == aa3) ? "EQUAL" : "NOT EQUAL") << endl <<endl;
	cout << endl;
	cout << tt1 << " != " << tt2 << ": " << ((tt1 != tt2) ? "NOT EQUAL" : "EQUAL") << endl;
	cout << endl;
	cout << tt1 << " != " << tt3 << ": " << ((tt1 != tt3) ? "NOT EQUAL" : "EQUAL") << endl;

	cout << "= = = = = =POWER= = = = = =" << endl;
	AComplex aaa(2, 2);
	TComplex ttt(2, PI);
	cout << endl;
	cout <<"RESULT \t\t\t"<< aaa << " pow 2 = " << power(aaa, 2) << endl;
	cout <<"RESULT \t\t\t"<< ttt << " pow 3 = " << power(ttt, 3) << endl;

	cout <<"\n\n= = = = = = NOW WE SHOULD TEST INPUT= = = = = =" << endl;
	AComplex i;
	cin >> i;
	cout << "RESULT: "<< i << endl;
	TComplex j;
	cin >> j;
	cout << "RESULT: " << j << endl;
	cout << "\n= = = = = = = = = = = =DESTRUCTORS= = = = = = = = = = = =" << endl;

	return 0;
}