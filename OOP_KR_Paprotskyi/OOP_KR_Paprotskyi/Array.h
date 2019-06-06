//Made by Ihor Paprotskyi, SE, 2nd year
#pragma once

#include <iostream>
#include <string>
using namespace std;

template <class Elem>
class Array
{
private:
	const size_t _size;
	Elem * _allocator;

	//restricted in the arrays
	Array(const Array&);
	Array& operator=(const Array&);
public:
	class BadArray;

	explicit Array(size_t size);
	~Array();

	Elem& operator[](const size_t index);
	const Elem& operator[](const size_t index) const;

	const size_t size() const
	{
		return _size;
	}
};

template <class Elem>
ostream& operator<<(ostream& os, const Array<Elem>& a)
{
	os << "Array of size: " << a.size() << ": " << endl;
	os << "[ ";
	for (size_t i = 0; i < a.size(); ++i)
	{
		os << a[i];
		os << (i + 1 != a.size() ? ", " : "");
	}
	os << " ]";
	return os;
}

//*********
//BadArray

template <class Elem>
class Array<Elem>::BadArray
{
private:
	string _reason;
	size_t _index;
public:
	BadArray(const string& reason = "Error: unknown reason", const size_t index = 0) :
		_reason(reason), _index(index)
	{}
	~BadArray() {}
	void diagnose() const
	{
		cerr << _reason;
		if (_index != 0)
		{
			cerr << ' ' << _index;
		}
		cerr << endl;
	}
};
//*********

//******************
//Array implementation
//constructor
template <class Elem>
Array<Elem>::Array(size_t size) :
	_size(size), _allocator(new Elem[size])
{
#ifndef NDEBUG
	cout << "Array of size " << size << " was created." << endl;
#endif
}

//destructor
template <class Elem>
Array<Elem>::~Array()
{

	delete[] _allocator;
#ifndef NDEBUG
	cout << "Array of size " << _size << " was destroyed." << endl;
#endif
}

//getter-setter
template <class Elem>
Elem& Array <Elem>::operator[](const size_t index)
{
	if (index < 0 || index >= _size)
		throw BadArray("Error! Bad index: ", index);
	return _allocator[index];
}

//getter
template <class Elem>
const Elem& Array <Elem>::operator[](const size_t index) const
{
	if (index < 0 || index >= _size)
		throw BadArray("Error! Bad index: ", index);
	return _allocator[index];
}
//*************