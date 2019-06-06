#pragma once
#include <string>
#include <iostream>

using namespace std;
class String
{
private:
	size_t _len;
	char* _allocator;

public:
	class BadString;
	
	String();
	explicit String(const char*);
	String(const char);
	explicit String(const string&);
	String(const String& s, unsigned int multiplayer=1);
	~String();
	
	String& operator=(const String&);
	String& operator=(const string&);
	String& operator=(const char*);
	String& operator=(const char);
	
	const string STL_string() const;
	const char* c_str() const;
	
	size_t length() const { return _len; }
	bool empty() const { return _len == 0; }
	void clear();

	char& operator[](size_t);
	const char operator[](const size_t) const;
	
	bool operator== (const String&) const;
	bool operator!= (const String&) const;
	bool operator== (const string&) const;
	bool operator!= (const string&) const;

	bool operator< (const String&) const;
	bool operator<= (const String&) const;
	bool operator> (const String&) const;
	bool operator>= (const String&) const;

	String operator+(const String&) const;
	String& operator+=(const char*);
	String& operator+=(const String&);
	String& operator+=(const string&);
};

ostream& operator<<(ostream&, const String&);


//No need to have second class BadIndex because it can be realised in one class BadString
class String::BadString
{
private:
	string _reason;
	size_t _index;
public:
	BadString(string reason = "", size_t index = 0) :
		_reason(reason), _index(index)
	{

	};
	~BadString() {};
	void diagnose() const
	{
		cerr << _reason;
		if (_index != 0)
			cerr << ' ' << _index;
		cerr << endl;
	}
};