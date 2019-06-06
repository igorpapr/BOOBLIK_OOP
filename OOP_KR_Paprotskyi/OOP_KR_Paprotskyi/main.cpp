//Made by Ihor Paprotskyi, SE, 2nd year
//#define NDEBUG //<<<=== UNCOMMENT this to hide all the unnecesary text from the main, asserts won't be working, though
#include <iostream>
#include "Set.h"
#include <cassert>
#include "MultiSet.h"
#include "AIterator.h"
#include "Iterator.h"
using namespace std;

int main()
{
	try
	{
		cout << "========Testing Set<char>========" << endl;
		Set<char> s;
		int k = 1;
		for (char i = 'a'; i <= 'z'; ++i, ++k)
		{
			for (int j = 0; j < k; ++j)
			{
				s.add(i);
			}
			assert(s.quantity_of(i) == 1);
		}
		Iterator<char, Set<char>> sitor(s);
		cout << "\nResult of adding all the chars to the set: " << endl;
		
		sitor.start();
		while (!sitor.stop()) {
			cout << *sitor <<' ';
			++sitor;
		}
		cout << endl;
		sitor.start();
		cout << "\nUsing iterator: "<<endl;
		cout<<"Does the set contain 'a' character? : "<<((find('a',sitor))?"true":"false")<<endl;
		sitor.start();
		cout<<"Does the set contain 'A' character? : " << ((find('A', sitor)) ? "true" : "false") << endl;
		sitor.start();
		cout << "How many 'a' characters does the set consist of? : " << quantity_of('a', sitor) << endl;
		sitor.start();
		cout << "How many 'A' characters does the set consist of? : " << quantity_of('A', sitor) << endl;
		cout << "\nUsing Set method: " << endl;
		cout << "Does the set contain 'a' character? : " << ((s.contains('a')) ? "true" : "false") << endl;
		cout << "Does the set contain 'A' character? : " << ((s.contains('A')) ? "true" : "false") << endl;
		cout << "How many 'a' characters does the set consist of? : " << s.quantity_of('a') << endl;
		cout << "How many 'A' characters does the set consist of? : " << s.quantity_of('A') << endl;
		cout <<"Let's print the set out one more time using the Set method: "<<endl;
		cout << s << endl;
		cout << "\n";
	}
	catch (const Sequence<char>::BadSeq& b)
	{
		b.diagnose();
	}
	cout << "========Testing MultiSet<char>========" << endl;
	try
	{
		MultiSet<char> ms;
		int k = 1;
		for (char i = 'a'; i <= 'z'; ++i, ++k)
		{
			for (int j = 0; j < k; ++j)
			{
				ms.add(i);
			}
			assert(ms.quantity_of(i) == k);
		}
		assert(ms.size() == 351);
		Iterator<char, MultiSet<char>> msitor(ms);
		cout << "Result of adding " << ms.size() << " chars of the alphabet: " << endl;
		msitor.start();
		while (!msitor.stop()) {
			cout << *msitor << ' ';
			++msitor;
		}
		cout <<endl;
		cout << "\nUsing iterator: " << endl;
		cout << "Does the set contain 'a' character? : " << ((find('a', msitor)) ? "true" : "false") << endl;
		msitor.start();
		cout << "Does the set contain 'A' character? : " << ((find('A', msitor)) ? "true" : "false") << endl;
		msitor.start();
		cout << "How many 'a' characters does the multiset consist of? : " << quantity_of('a', msitor) << endl;
		msitor.start();
		cout << "How many 'A' characters does the multiset consist of? : " << quantity_of('A', msitor) << endl;
		cout << "\nUsing MultiSet method: " << endl;
		cout << "Does the set contain 'a' character? : " << ((ms.contains('a')) ? "true" : "false") << endl;
		cout << "Does the set contain 'A' character? : " << ((ms.contains('A')) ? "true" : "false") << endl;
		cout << "How many 'a' characters does the multiset consist of? : " << ms.quantity_of('z') << endl;
		cout << "How many 'A' characters does the multiset consist of? : " << ms.quantity_of('Z') << endl;
		cout << "Let's print the set out one more time using the MultiSet method: " << endl;
		cout << ms << endl;
		cout << "\n";
	}
	catch (const Sequence<char>::BadSeq& b)
	{
		b.diagnose();
	}

	return 0;
}