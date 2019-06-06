//Made by Ihor Paprotskyi, SE, 2nd year
#pragma once
#include "Sequence.h"
#include "ASet.h"
#include <iostream>
using namespace std;

template <class T>
class Set: public ASet<T>
{
private:
	Set(const Set&);
	Set& operator=(const Set&);

	Sequence<T>* _seq;
public:
	Set();
	Set(size_t capacity);
	Set<T>& add(const T&) override;

	const size_t size() const { return _seq->size(); }
	const size_t capacity() const { return _seq->capacity(); }

	const bool contains(const T& t) { return _seq->contains(t); }
	const size_t quantity_of(const T&) const;

	const T& operator[](const size_t i) const 
	{
		return _seq->operator[](i);
	}
	
	~Set();
};

//empty parameters constructor
template <class T>
Set<T>::Set() :
	_seq(new Sequence<T>)
{
#ifndef NDEBUG
	cout << "Set was created" << endl;
#endif
}

//constructor of capacity
template <class T>
Set<T>::Set(size_t capacity) :
	_seq(new Sequence<T>(capacity))
{
#ifndef NDEBUG
	cout << "Set was created" << endl;
#endif
}

//destructor
template <class T>
Set<T>::~Set()
{
	delete _seq;
#ifndef NDEBUG
	cout << "Set was destroyed" << endl;
#endif
}

//add element
template <class T>
Set<T>& Set<T>::add(const T& el)
{
	if (!contains(el))
	{
		_seq->add(el);
//#ifndef NDEBUG //A lot of text in main :(
//		cout << "Element was added to the set" << endl;
//#endif
	}
	return *this;
}

//quantity of element
template<class T>
const size_t Set<T>::quantity_of(const T& el) const
{
	if (_seq->contains(el))
	{
		return 1;
	}
	return 0;
}