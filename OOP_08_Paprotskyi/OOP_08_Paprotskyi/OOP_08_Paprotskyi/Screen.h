//Made by Ihor Paprotskyi, SE, 2nd year
#pragma once
#include <iostream>
using namespace std;

class Screen
{
public:
	Screen(int w, int h, char* pc = 0);
	~Screen();
	
	const Screen& home() const;
	Screen& home();
	
	const Screen& move() const;
	Screen& move();
	
	const Screen& back() const;
	Screen& back();

	//in order to implement operator<<
	const Screen& show(ostream&) const;
	const Screen& show() const;

	Screen& show(ostream&);
	Screen& show();

	const Screen& showCurrent(ostream&) const;
	const Screen& showCurrent() const;

	const Screen& move(const int, const int) const;
	Screen& move(const int, const int);
	
	const Screen& clear() const;
	Screen& clear();	
	
	char get() const;
	Screen& set(char);

private:
	static const int maxHeight;
	static const int maxWidth;
	static const char _filler;
	int _height;
	int _width;
	char *_wContent;
	mutable int _cursor;
	
	//not implemented
	Screen(const Screen&);
	Screen& operator= (const Screen&);
};

std::ostream& operator<<(std::ostream&, const Screen&);

typedef const Screen& (Screen::* const ConstAction) () const;
typedef Screen& (Screen::* const NonConstAction) ();
void doActionConst(const Screen& s, ConstAction act, const int n);
void doActionNonConst(Screen& s, NonConstAction act, const int n);