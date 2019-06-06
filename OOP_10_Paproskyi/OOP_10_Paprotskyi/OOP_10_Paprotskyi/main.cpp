#include "Sequence.h"
#include "Complex.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "= = = =Testing empty sequence of ints= = = =" << endl;
	try
	{
		Sequence<int> s1;
		cout << s1 << endl;
		s1.add(1);
		s1.add(2);
		s1.add(3);
		s1.add(4);
		s1.add(5);
		s1.add(6);
		cout <<"\nNow the sequence is: "<< endl;
		cout << s1 << endl;
		cout <<"Does the sequence contain 5?: "<<(s1.contains(5)?"true":"false")<< endl;
		cout <<"Does the sequence contain 7?: " << (s1.contains(7) ? "true" : "false") << endl;
		cout << "\nDeleting from the end:" << endl;
		s1.cut();
		cout << "Now the sequence is: " << endl;
		cout << s1 << endl;
		cout << "\nInserting:" << endl;
		s1.insert(34,5);
		cout << "Now the sequence is: " << endl;
		cout << s1 << endl;
		cout << "\nDeleting 3th index:" << endl;
		s1.remove(3);
		cout << "Now the sequence is: " << endl;
		cout <<"Let's clear it: "<< endl;
		s1.clear();
		cout << "Now the sequence is: " << endl;
		cout << s1 << endl;
		cout << "The last element is: " << endl;
		cout << s1.last() << endl;
	}
	catch (const Sequence<int>::BadSeq& b)
	{
		b.diagnose();
	}

	cout << "= = = =Testing sequence of Complex= = = =" << endl;
	try
	{
		Sequence<Complex> sc(20);
		Complex c(3,2);
		Complex c1(2, 5);
		Complex c2(6,7);

		sc.add(c);
		sc.add(c1);
		sc.add(c2);
	
		cout <<"Let's remove one: "<<endl;
		sc.cut();
		cout << sc <<endl<<endl;

		cout << "Does the sequence contain 3+2i?: " << (sc.contains(Complex(3,2)) ? "true" : "false") << endl;
		cout << "Does the sequence contain 7+0i?: " << (sc.contains(Complex(7)) ? "true" : "false") << endl;
		cout << endl;
	}
	catch (const Sequence<int>::BadSeq& b)
	{
		b.diagnose();
	}

	cout << "Error:" << endl;
	try
	{
		Sequence<int> sc(20);
		sc[100];

	}
	catch (const Sequence<int>::BadSeq& b)
	{
		b.diagnose();
	}

	return 0;
}