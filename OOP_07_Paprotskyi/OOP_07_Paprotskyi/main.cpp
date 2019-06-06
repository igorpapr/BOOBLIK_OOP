//Made by Ihor Paprotskyi, SE, 2 year
#include "String.h"
#include <iostream>
using namespace std;

int main()
{
	try{
		cout << "\n= = = = =Constructors= = = = =" << endl;
		{
			String s("ha");
		
			string stl_s("STL");
			String ss(stl_s);
		
			String sc('c');
			String scpy(s);
			String smult(scpy, 4);
		}
		cout << "\n= = = = Assignment = = = =" << endl;
		{
			String s("old str");
			string stl("My stl str");
			s = stl;
			String sa("s to assign");
			s = sa;
			s = "String from char arr";
			char c = 'a';
			s = c;
		}
		cout << "\n= = = =Getters, empty(), clear()= = = =" << endl;
		{
			String s("My string");
			cout << "STL_string(): " << s.STL_string() << endl;
			cout << "c_str():" << s.c_str() << endl;
			cout << "length():" << s.length() << endl;
			cout <<(s.empty() ? "IT IS EMPTY" : "IT ISN'T EMPTY")<< endl;
			cout << "Let's clear it" << endl;
			s.clear();
			cout <<(s.empty() ? "NOW IT IS EMPTY" : "NOW IT ISN'T EMPTY") << endl;
		}
		cout<<"\n= = = = Operator []= = = ="<<endl;
		{
			String s("Old string");
			cout << "Changing some letters..." << endl;
			s[0] = 'N';
			s[1] = 'e';
			s[2] = 'w';
			cout << "Result: " << s <<endl;
			const String ss(s);
			cout <<"Using const operator[] ==> const "<<ss<<"[1]:"<<ss[1]<<endl;
		}
		cout<<"\n- - - - Operators == AND != - - - -"<<endl;
		{
			String s("hello");
			String s1("hello");
			String s2("ho");
			cout << s <<(s == s1? " Equals " : " Not equals ") <<s1<<endl;
			cout <<s<<(s == s2 ? " Equals " : " Not equals ") <<s2<<endl;
			cout << s << (s != s1 ? " Not equals " : " Equals ") << s1 << endl;
			cout << s << (s != s2 ? " Not equals " : " Equals ") << s2 << endl;
		}
		cout << "\n- - - - <, <=, >, >= - - - -" << endl;
		{
			String a('a');
			String a1('a');
			String b('b');
			String ca("ca");
			String ac("ac");

			cout << "a < b :" << (a < b) << endl;
			cout << "a >= a :" << (a >= a1) << endl;
			cout << "ca <= a :" << (ca <= a) << endl;
			cout << "ac > a :" << (ac > a) << endl;
		}
		cout << "\n= = = =Addition= = = =" << endl;
		{
			String s("Hello");
			String s1(" World");
			cout <<"+: "<< s + s1 << endl;
			s += s1;
			cout << "+=: " <<s<< endl;
			cout <<"String += char*: "<<(s+="+charArr")<< endl;
			string stl("+stl");
			cout << "String += string: " << (s += stl) << endl;
			cout <<"String += String: "<<(s+=String("+String"))<< endl;
		}
	}
	catch (String::BadString e)
	{
		e.diagnose();
	}
	cout << "\n= = = = = = = = = =Exception: construct with nullptr= = = = = = = = = =" << endl;
	try
	{
		char * np = 0;
		String s_exception(np);
	}
	catch (String::BadString e)
	{
		e.diagnose();
	}
	cout << "\n= = = = = = = = = =Exception: Assigning nullptr= = = = = = = = = =" << endl;
	try
	{
		char * p = 0;
		String s("s");
		s = p;
	}
	catch (String::BadString e)
	{
		e.diagnose();
	}
	cout << "\n= = = = = = = = = =Exception: Index out of range= = = = = = = = = =" << endl;
	try
	{
		String s("String");
		s[100];
	}
	catch (String::BadString e)
	{
		e.diagnose();
	}
	return 0;
}