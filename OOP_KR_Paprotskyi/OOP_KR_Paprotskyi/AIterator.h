//Made by Ihor Paprotskyi, SE, 2nd year
#pragma once

#include <iostream>
using namespace std;

template <class T>
class AIterator 
{
public:
	virtual AIterator& clone() = 0;
	virtual void start() = 0;
	virtual const AIterator& operator++() const = 0;
	virtual bool stop() const = 0;
	virtual const T& operator*() const = 0;
	virtual ~AIterator() {};
};

template <class T>
ostream& operator<<(ostream& os, AIterator<T>& itor)
{
	while (!itor.stop())
	{
		os << *itor << ' ';
		++itor;
	}
	return os << endl;
}

template <class T>
bool find(const T& elem, AIterator<T>& itor)
{
	while (!itor.stop())
	{
		if (*itor == elem)
			return true;
		++itor;
	}
	return false;
}

template <class T>
const size_t quantity_of(const T& elem, AIterator<T>& itor)
{
	size_t res = 0;
	while (!itor.stop())
	{
		if (*itor == elem)
			++res;
		++itor;
	}
	return res;
}