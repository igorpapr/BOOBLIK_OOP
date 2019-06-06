//Made by Ihor Paprotskyi, SE, 2 year
#include "String.h"

//warning C4996: 'strcpy': This function or variable may be unsafe. Consider using strcpy_s instead. 
//that's why we'll use this one
void copyon(char* target, const char* source, size_t len)
{
	for (size_t i = 0; i < len; ++i)
		target[i] = source[i];
	target[len] = '\0';
}

String::String():
	_len(0),_allocator(new char[1])
{
	_allocator[0] = '\0';
#ifndef NDEBUG
	cout << "Empty string created "<< *this << endl;
#endif
	return;
}

String::String(const char c) :
	_len(1), _allocator(new char[2])
{
	_allocator[0] = c;
	_allocator[1] = '\0';
#ifndef NDEBUG
	cout << "One symbol string created: " << *this <<endl;
#endif
	return;
}

String::String(const char* ps)
{
	if (ps == 0)
		throw BadString("Attempt to use null pointer");
	_len = strlen(ps);
	_allocator = new char[_len + 1];
	copyon(_allocator, ps, _len);
#ifndef NDEBUG
	cout << "String from char* created: "<< *this << endl;
#endif
	return;
}

String::String(const string& s) :
	_len(s.length()), _allocator(new char[s.length() + 1])
{
	copyon(_allocator, s.c_str(), s.length());
#ifndef NDEBUG
	cout << "String from stl string created: " << *this << endl;
#endif
	return;
}

String::String(const String& s, const unsigned int multiplayer) :
	_len(multiplayer > 0 ? s._len*multiplayer : s._len),
	_allocator(new char[_len + 1])
{
	char* target = _allocator;
	for (unsigned int i = 0; i < multiplayer; i++) {
		copyon(target, s._allocator, s._len);
		target += s._len;
	}
#ifndef NDEBUG
	cout << "String copied "<<multiplayer<<" times: " << *this << endl;
#endif
	return;
}

String::~String()
{
//We won't be using cout in destructors for shorter console
//#ifndef NDEBUG
//	cout << "String deleted: " << *this << endl;
//#endif
	delete[] _allocator;
}

String& String::operator=(const String& s)
{
	if (this == &s)
	{
		return *this;
	}
	delete[] _allocator;
	_len = s.length();
	_allocator = new char[_len + 1];
	copyon(_allocator, s.c_str(),_len);
#ifndef NDEBUG
	cout << "String copy-assigned: " << *this << endl;
#endif
	return *this;
}

String& String::operator=(const string& s)
{
	if (*this == s)
	{
		return *this;
	}
	delete[] _allocator;
	_len = s.length();
	_allocator = new char[_len + 1];
	copyon(_allocator, s.c_str(), _len);
#ifndef NDEBUG
	cout << "String assigned from stl string: " << *this << endl;
#endif
	return *this;
}


String& String::operator=(const char* ps)
{
	if (ps == 0)
		throw BadString("Attempt to use null pointer");
	delete[] _allocator;
	for (_len = 0; ps[_len]; _len++); 
	_allocator = new char[_len + 1];
	copyon(_allocator, ps, _len);
#ifndef NDEBUG
	cout << "String assigned from char array: " << *this << endl;
#endif
	return *this;
}

String& String::operator=(const char c)
{
	delete[] _allocator;
	_len = 1;
	_allocator = new char[2];
	_allocator[0] = c;
	_allocator[1] = '\0';
#ifndef NDEBUG
	cout << "String assigned from single character: " << *this << endl;
#endif
	return *this;
}

const string String::STL_string() const
{
	return string(_allocator);
}

const char * String::c_str() const
{
	return _allocator;
}

void String::clear()
{
	delete[] _allocator;
	_len = 0;
	_allocator = new char[1];
	_allocator[0] = '\0';
	return;
}

char& String::operator[](size_t i) {
	if ((i < 0) || (_len <= i))
		throw BadString("Index out of range: ", i);
	return _allocator[i];
};

const char String::operator[](const size_t i) const {
	if (_len <= i) 
		throw BadString("Index out of range: ", i);
	return _allocator[i];
}

bool String::operator==(const String& s) const
{
	bool eq = _len == s._len;
	for (unsigned int i = 0; (i < _len) && eq; i++)
		eq = *(_allocator+i) == s[i];
	return eq;
}

bool String::operator==(const string& s) const
{
	bool eq = _len == s.length();
	for (unsigned int i = 0; (i < _len) && eq; i++)
		eq = *(_allocator + i) == s[i];
	return eq;
}

bool String::operator!=(const String& s) const
{
	return !(*this == s);
}

bool String::operator!=(const string& s) const
{
	return !(*this == s);
}

bool String::operator<(const String& s) const {
		bool res = true; 
		size_t i = 0;
		while (res && (i < _len) && (i < s._len)) {
			res = res && (*(_allocator + i) == *(s._allocator + i)); 
			i++;
		}
		if (res) 
			return _len < s._len;
		i--;
		return *(_allocator + i) < *(s._allocator + i);
}

bool String::operator<=(const String& s) const {
	if (*this == s) 
		return true;
	return *this < s;
}

bool String::operator>(const String& s) const
{
	return !(*this <= s);
}

bool String::operator>=(const String & s) const
{
	if (*this == s) {
		return true;
	}
	return *this > s;
}

String& String::operator+=(const String& s) {
	size_t len = _len + s._len;
	char* tempAllocator = new char[len + 1];
	copyon(tempAllocator, _allocator,_len);
	delete[] _allocator;
	_allocator = tempAllocator;
	copyon(_allocator + _len, s._allocator,s._len);
	_len = len;
	return *this;
}

String String::operator+(const String &s) const
{
	String res(*this);
	return res += s;
}

String& String::operator+=(const char* ps) {
	if (ps == 0) 
		throw BadString("Attempt to use null pointer");
	size_t len = strlen(ps);
	char* tempAllocator = new char[len + _len + 1];
	copyon(tempAllocator, _allocator,_len);
	delete[] _allocator;
	_allocator = tempAllocator;
	copyon(_allocator + _len, ps, len);
	_len += len;
	return *this;
}

String& String::operator+=(const string& s)
{
	size_t len = _len + s.length();
	char* tempAllocator = new char[len + 1];
	copyon(tempAllocator, _allocator,_len);
	delete[] _allocator;
	_allocator = tempAllocator;
	copyon(_allocator + _len, s.c_str(), s.length());
	_len = len;
	return *this;
}

ostream& operator<<(ostream& os, const String& s)
{
	for (size_t i = 0; i < s.length(); i++)
		os << s[i];
	return os;
}