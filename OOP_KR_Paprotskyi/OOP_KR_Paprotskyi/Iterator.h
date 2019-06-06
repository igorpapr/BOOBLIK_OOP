//Made by Ihor Paprotskyi, SE, 2nd year
#pragma once

#include "AIterator.h"
#include <iostream>
using namespace std;

template <class T, class Container>
class Iterator: public AIterator<T>
{
private:
	const Container& _container;
	const T* _start;
	mutable const T* _end;
	mutable const T* _current;
public:
	Iterator(const Container&  container)
		: _container(container), _start(&_container[0]),
		_end(_start + _container.size()),
		_current(_start) 
	{}
	
	Iterator(const Iterator& it)
		: _container(it._container), _start(it._start),
		_end(it._end), _current(it._current) 
	{}
	
	~Iterator() {};

	Iterator& clone() {
		return *(new Iterator(*this));
	}

	void start() 
	{
		_current = &_container[0];
		_end = _start + _container.size();
	}

	const Iterator& operator++() const 
	{
		++_current;
		return*this;
	}
	bool stop() const 
	{
		return _current == _end;
	}
	const T& operator*() const {
		return  *_current;
	}
	const T& operator*() {
		return *_current;
	}
};