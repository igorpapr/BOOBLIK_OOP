//Made by Ihor Paprotskyi, SE, 2nd year
#pragma once

#include <iostream>
#include <string>
using namespace std;

template <size_t n, class Elem>
class Array
{
private:
	Elem * _allocator;
public:
	class BadArray;

	explicit Array();
	~Array();
	
	Array(const Array& a);
	Array& operator=(const Array&);

	Array(Array&&);
	Array& operator=(Array&&);


	Elem& operator[](const size_t index);
	const Elem& operator[](const size_t index) const;

	size_t size() const 
	{
		return n; 
	}
};

template <size_t n, class Elem>
ostream& operator<<(ostream& os, const Array<n, Elem>& a)
{
	os << "Array of size: " << n <<": "<< endl;
	os << "[ ";
	for (size_t i = 0; i < a.size(); ++i)
	{
		os << a[i];
		os << ( i + 1 != a.size() ? ", " : "");
	}
	os << " ]";
	return os;
}

//*********
//BadArray

template <size_t n, class Elem>
class Array<n, Elem>::BadArray 
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
template <size_t n, class Elem>
Array<n, Elem>::Array() :
	_allocator(new Elem[n]) 
{
#ifndef NDEBUG
	cout << "Array of size "<<n<<" was created." << endl;
#endif
}

//destructor
template <size_t n, class Elem>
Array<n, Elem>::~Array()
{
	delete[] _allocator;
#ifndef NDEBUG
	cout << "Array of size " << n << " was destroyed." << endl;
#endif
}

//copy constructor
template<size_t n, class Elem>
Array<n, Elem>::Array(const Array<n,Elem> & a)
	:_allocator(new Elem[a.size()])
{
	for (size_t i = 0; i < n; ++i)
	{
		_allocator[i] = a[i];
	}
#ifndef NDEBUG
	cout << *this << " was copied." << endl;
#endif
}

//copy-assignment
template<size_t n, class Elem>
Array<n,Elem>& Array<n, Elem>::operator=(const Array<n, Elem>& a)
{
	if (this == &a)
	{
#ifndef NDEBUG
		cout << "Attempt to assign to itself. Returned the same object."<< endl;
#endif
		return *this;
	}
	delete[] _allocator;
	_allocator = new Elem[a.size()];
	for (size_t i = 0; i < a.size(); i++) 
	{
		_allocator[i] = a[i];
	}
#ifndef NDEBUG
	cout << *this << " was assigned." << endl;
#endif
	return *this;
}

//move constructor
template<size_t n, class Elem>
Array<n, Elem>::Array(Array<n, Elem>&& a):
	_allocator(nullptr)
{
	_allocator = a._allocator;
	a._allocator = nullptr;
#ifndef NDEBUG
	cout << *this << " was moved." << endl;
#endif
}

//move-assignment
template<size_t n, class Elem>
Array<n,Elem>& Array<n, Elem>::operator=(Array<n, Elem>&& a)
{
	if (this == &a)
	{
		return *this;
	}
	delete[] _allocator;
	_allocator = a._allocator;
	a._allocator = nullptr;
#ifndef NDEBUG
	cout << *this << " was move-assigned." << endl;
#endif
	return *this;
}


//getter-setter
template <size_t n, class Elem>
Elem& Array <n, Elem>::operator[](const size_t index) 
{
	if (index < 0 || index >= n)
		throw BadArray("Error! Bad index: ", index);
	return _allocator[index];
}

//getter
template <size_t n, class Elem>
const Elem& Array <n, Elem>::operator[](const size_t index) const 
{
	if (index < 0 || index >= n)
		throw BadArray("Error! Bad index: ", index);
	return _allocator[index];
}
//*************

//JUST FOR TESTING MOVING
template <size_t n, class Elem>
Array<n, Elem> testMove(Array<n, Elem> a)
{
	return a;
}
