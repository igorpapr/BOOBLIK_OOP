//Made by Ihor Paprotskyi, SE, 2nd year
#include "Screen.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Creating screen with some filling and changing it's content:" << endl;
	int w = 28, h = 10;
	char str[] = "Ababahalamaga Hello World Hi Ukraine";
	Screen screen(w, h, str);
	screen.show().set('*').move(1, 1).set('=').move(2, 2).set('+').move(3, 3).
		set('-').move(4, 4).set('~').move(5, 5).set('*').move(6, 6).set('*').move(7, 7).set('*').show();
	cout << endl;
	cout << "First 5 symbols: ";
	for (int i = 0; i < 5; i++)
	{
		screen.move(i, 0).showCurrent();
	}
	cout << endl << endl << "Let's draw a big '+'" << endl;
	screen.move(w/2,0).clear();
	for (int i = 0; i < h; ++i)
	{
		screen.move(w/2,i).set('+');
	}
	screen.move(0,h/2);
	for (int j = 0; j < w; ++j)
	{
		screen.move(j, h/2).set('+');	
	}
	cout << screen << endl;
	
	const NonConstAction menuNonConst[] = { &Screen::home, &Screen::move, &Screen::back, &Screen::clear, &Screen::show };
	const ConstAction constMenu[] = { &Screen::home, &Screen::move, &Screen::back, &Screen::show, &Screen::showCurrent };
	int rows = 15;
	int columns = 10;

	cout << "= = = = = = =TESTING MENU FOR CONST CREEN= = = = = = =";
	char content[] = "Content of the screen";
	const Screen constScreen(rows, columns, content);
	int k, n; 
	char repeat; 
	constScreen.show();
	do {
		cout << "your action?(0-home:1-move:2-back:3-show:4-showCurrent): "; 
		cin >> k;
		while (k < 0 || k > 4) 
		{
			cout << "Bad index, please enter correct number: ";
			cin >> k;
		}
		cout << "multiplicity? ";
		cin >> n;
		while (n <= 0)
		{
			cout << "Bad index, please enter correct number: ";
			cin >> n;
		}
		doActionConst(constScreen, constMenu[k], n);
		cout << endl <<"Repeat testing(y/n)?";
		cin >> repeat;
	} while (repeat == 'y');

	cout <<endl<< "= = = = = = =TESTING MENU FOR NON-CONST CREEN= = = = = = =";
	
	Screen nonConstScreen(rows, columns, content);
	nonConstScreen.show();
	do {
		cout << "your action?(0-home, 1-move, 2-back, 3-clear, 4-show, 5-move to, 6-set): ";
		cin >> k;
		while (k < 0 || k > 7)
		{
			cout << "Bad index, please enter correct number: ";
			cin >> k;
		}
		switch (k)
		{
			case 5:
				int x, y;
				cout << "Enter the row (from 0 to "<<rows<<"): ";
				cin >> x;
				while (x < 0 || x > rows)
				{
					cout << "Bad index, please enter correct number: ";
					cin >> x;
				}
				cout << "Enter the column (from 0 to " << columns << "): ";
				cin >> y;
				while (y < 0 || y > columns)
				{
					cout << "Bad index, please enter correct number: ";
					cin >> y;
				}
				nonConstScreen.move(x, y);
				break;
			case 6:
				char character;
				cout << "Enter the character: ";
				cin >> character;
				nonConstScreen.set(character);
				break;
			default:
				cout << "multiplicity? ";
				cin >> n;
				while (n <= 0)
				{
					cout << "Please enter number greater than 0: ";
					cin >> n;
				}
				doActionNonConst(nonConstScreen, menuNonConst[k], n);
		}
		cout << endl << "Repeat testing(y/n)?";
		cin >> repeat;
	} while (repeat == 'y');
	return 0;
}