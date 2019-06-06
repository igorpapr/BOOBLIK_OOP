//Made by Ihor Paprotskyi, SE, 2nd year
#include "Screen.h"

using namespace std;
const int Screen::maxHeight = 24;
const int Screen::maxWidth = 80; 
const char Screen::_filler = '_';

Screen::Screen(int w, int h, char* s) :
	_width(w > maxWidth ? maxWidth : w),
	_height(h > maxHeight ? maxHeight : h),
	_wContent(new char[_width*_height + 1]),
	_cursor(0)
{
	int screenSize = _height * _width;
	int len = s == 0 ? 0 : strlen(s);
	len = len > screenSize ? screenSize : len;
	_wContent[screenSize] = '\0';
	int k = 0;
	if (s != 0)
	{
		while(k < len)
			_wContent[k++] = *s++;
		
	}
	while(k < screenSize)
		_wContent[k++] = _filler;
}

Screen::~Screen()
{
	delete[] _wContent;
}

const Screen& Screen::home() const 
{ 
	_cursor = 0; 
	return *this; 
}
Screen& Screen::home() 
{ 
	_cursor = 0;
	return *this; 
}

const Screen& Screen::move() const 
{
	if ((++_cursor) >= _width * _height)
		_cursor = 0;
	return *this;
}
Screen& Screen::move()
{
	if ((++_cursor) >= _width * _height)
		_cursor = 0;
	return *this;
}

const Screen& Screen::back() const 
{
	if (--_cursor < 0) 
		_cursor = 0;
	return *this;
}
Screen& Screen::back()
{
	if (--_cursor < 0)
		_cursor = 0;
	return *this;
}

const Screen& Screen::show(ostream& o) const 
{
	int checkpoint = _cursor;
	o << "cursor: " << _cursor << endl;
	home();
	for (int i = 0; i < _height; i++) {
		for (int j = 0; j < _width; j++) {
			showCurrent(o).move();
		}
		o << endl;
	}
	_cursor = checkpoint;
	return *this;
}


const Screen& Screen::show() const
{
	return show(cout);
}
Screen & Screen::show(ostream & o)
{

	int checkpoint = _cursor;
	o << "cursor: " << _cursor << endl;
	home();
	for (int i = 0; i < _height; i++) {
		for (int j = 0; j < _width; j++) {
			showCurrent(o).move();
		}
		o << endl;
	}
	_cursor = checkpoint;
	return *this;
}

Screen& Screen::show()
{
	return show(cout);
}

const Screen & Screen::showCurrent(ostream & o) const
{
	o << get();
	return *this;
}

const Screen& Screen::showCurrent() const
{
	return showCurrent(cout);
}

const Screen& Screen::move(const int x, const int y) const
{

	if ((x < 0) || (y < 0) || (x >= _width) || (y >= _height))
		_cursor = 0;
	else 
		_cursor = _width * y + x;
	return *this;
}
Screen& Screen::move(const int x, const int y)
{
	if ((x < 0) || (y < 0) || (x >= _width) || (y >= _height))
		_cursor = 0;
	else
		_cursor = _width * y + x;
	return *this;
}

const Screen& Screen::clear() const 
{
	for (int i = 0; i < _height * _width; i++)
		*(_wContent + i) = _filler;
	_cursor = 0;
	return *this;
}
Screen& Screen::clear() 
{
	for (int i = 0; i < _height * _width; i++)
		*(_wContent + i) = _filler;
	_cursor = 0;
	return *this;
}

char Screen::get() const
{
	return _wContent[_cursor];
}

Screen& Screen::set(char a)
{
	_wContent[_cursor] = a;
	return *this;
}

ostream& operator<<(ostream& o, const Screen& s)
{
	s.show(o);
	return o;
}

void doActionConst(const Screen & s, ConstAction act, int n)
{
	for (int i = 0; i < n; i++) {
		(s.*act)();
	}
}

void doActionNonConst(Screen & s, NonConstAction act, int n)
{
	for (int i = 0; i < n; i++) {
		(s.*act)();
	}
}