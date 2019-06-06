//Made by Ihor Paprotskyi, SE, 2 year
#include "Timer.h"
using namespace std;

int main()
{
	cout << "=======TESTING TIME=======" << endl;
	Time t1 = Time(00, 59, 55);
	cout << t1 << endl;
	Time t2 = t1;

	cout << "==== Assignment====" << endl;
	cout<< t2 << endl;
	for (int i = 0; i < 10; i++) {
		cout << "Prefix increment: " << t2 << endl;
		++t2;
	}
	for (int i = 0; i < 10; i++) {
		cout << "Prefix decrement: " << t2 << endl;
		--t2;
	}
	cout << "====Suffix increment====" << endl;
	cout<< "before: " << t2++ << endl;
	cout << "after: " << t2 << endl;

	cout << "======Suffix decrement======" << endl;
	cout<<"before: " << t2-- << endl;
	cout << "after: " << t2 << endl;
	cout << "Adding time: " << (t1 + t2) << endl;
	cout << "int(): " << static_cast<int>(t1) << endl;
	cout << "double(): " << static_cast<double>(t1) << endl;
	cout << "double(): " << static_cast<double>(Time(100, 0, 0)) << endl << endl << endl;


	cout << "===========TESTING TIMER===========" << endl;
	//INPUT YOUR DATE HERE
	Date d = Date(10, 3, 2019);
	Time t = Time(23, 51, 10);
	Time interval = Time(0, 0, 2);

	try {
		Timer * tr = new Timer(d, t, interval);
		tr->turnOn();
		delete tr;
		tr = nullptr;
	}
	catch (char const * err) {
		cout << err << endl;
	}
	return 0;
}