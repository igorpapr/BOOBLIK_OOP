//Made by Ihor Paprotskyi, SE, 2 year
#include "Date.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "\n= = = = = = = Start of program = = = = = = = =" << endl;
	try
	{
		cout << "Default date: " << endl;
		Date::showDefault();
		cout << "Changing default date to new: " << endl;
		Date::setDefault(21, Date::Month(6), 2000);
		Date::showDefault();
		cout << "Return to system default date: " << endl;
		Date::setDefault();
		cout << endl << endl;
		Date d, d1(28, 2, 2015), d2(d1);
		cout << endl << endl;

		cout << "Operands: " << endl;
		cout << "--(" << d1 << ")"<< endl;
		cout << "Result: " << --d1 << endl << endl;
		
		cout << '(' << d1 << ")--"<< endl ;
		d1--;
		cout<< "Result: " << d1 << endl<<endl;
	
		cout << "++(" << d2 << ')' << endl ;
		cout <<"Result: "<< ++d2 << endl << endl;

		cout << '(' << d1 << ")++" << endl;
		d1++;
		cout << "Result: " << d1 << endl << endl;

		Date febrLeap(29, 02, 2020);
		cout << "++(" << febrLeap << ')' << endl;
		cout << "Result: " << ++febrLeap << endl<< endl;

		cout << "Let's change date to custom" << endl;
		febrLeap.setDay(11);
		febrLeap.setMonth(10);
		febrLeap.setYear(2001);
		cout <<"Result:\n"<< febrLeap << endl <<endl;
		
		cout << "Let's create wrong date: " << endl;
		Date wd(483, 321, 2009);

		cout << endl;
	}
	catch (Date::BadDate bd)
	{
		cerr << bd;
	}
	return 0;
}