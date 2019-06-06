#pragma once
#include "Array.h"
#include <cassert>
#include <string>

template<class Elem>
class Sequence {
public:
	class BadSeq;
	
	explicit Sequence(const size_t capacity = _default);
	~Sequence();

	size_t capacity() const { return _allocator->size(); }
	size_t size() const { return _size; }
	bool empty() const { return (size() == 0); }
	bool full() const { return size() == capacity(); }
	const Elem& last() const;

	Sequence& clear() 
	{
#ifndef NDEBUG
		cout <<"The sequence was cleared"<< endl;
#endif // !NDEBUG
		_size = 0;
		return *this; 
	}

	const Elem& operator[](const size_t index) const;
	Elem& operator[](const  size_t index);
	Sequence& add(const Elem& elem);
	Sequence& insert(const Elem& elem, const  size_t index);
	Sequence& cut();
	Sequence& remove(const size_t index);
	bool contains(const Elem & elem);
private:
	size_t _size;
	static const size_t _default = 0;
	Array<Elem> * _allocator;

	void reduce();
	void enlarge(const size_t times = 2);
	
	Sequence& doinsert(const Elem& elem, const size_t index);
	Sequence& doremove(const size_t index);

	Sequence(const Sequence&);
	Sequence& operator=(const Sequence&);
};

template<class Elem>
ostream& operator<<(ostream& os, const Sequence<Elem>& s)
{
	os << "{";
	if (!s.empty())
	{
		for (size_t i = 0; i < s.size(); ++i) 
		{
			os << s[i] << (i != s.size() - 1 ? ", " : "");
		}
	}
	return os << "}";
}

template<class Elem>
class Sequence<Elem>::BadSeq
{
private:
	string _reason;
public:
	BadSeq(const string reason = "Unknown reason") : _reason(reason)
	{}

	~BadSeq() {}

	void diagnose() const
	{
		cerr << _reason << endl;
	}
};


//constructor
template<class Elem>
Sequence<Elem>::Sequence(const size_t capacity) :
	_size(0), _allocator(new Array<Elem>(capacity))
{
#ifndef NDEBUG
	cout << "Sequence of capacity " << capacity << " was created." << endl;
#endif
}

//destructor
template<class Elem>
Sequence<Elem>::~Sequence() 
{
#ifndef NDEBUG
	cout << "Sequence of capacity " << capacity() << " was destroyed." << endl;
#endif
	delete _allocator;
}

//selector
template <class Elem>
const Elem& Sequence<Elem>::operator[](const size_t index) const 
{
	if (empty())
		throw BadSeq("Error! You tried to manipulate the empty sequence");
	if (index > _size)
		throw BadSeq("Try to access a non existing element of the sequence");
	return (*_allocator)[index];
}

//selector-modificator
template <class Elem>
Elem& Sequence<Elem>::operator[](const size_t index)
{
	if (empty())
		throw BadSeq("Error! You tried to manipulate the empty sequence");
	if (index > _size)
		throw BadSeq("Try to access a non existing element of the sequence");
	return (*_allocator)[index];
}

template <class Elem>															//@TODO MB DELETE
const Elem& Sequence<Elem>::last() const
{
	if (empty())
		throw BadSeq("The sequence is empty");
	return (*this)[size()];
}

template<class Elem>
Sequence<Elem>& Sequence<Elem>::add(const Elem& elem)
{
	return doinsert(elem, _size);
}

template<class Elem>
Sequence<Elem>& Sequence<Elem>::insert(const Elem& elem, const size_t index) 
{
	if (size() < index) 
		throw BadSeq("Error! Attempt to access not existing index of the sequence");
	return doinsert(elem, index);
}

template<class Elem>
Sequence<Elem>& Sequence<Elem>::doinsert(const Elem& elem, const size_t index) 
{
	assert(index <= _size);
	if (_size <= capacity() / 4)
		reduce();
	if (_size + 1 > capacity())
		enlarge();
	++_size;
	for (size_t i = _size - 1; i > index; --i)
		operator[](i) = operator[](i - 1);
	operator[](index) = elem;
#ifndef NDEBUG
	cout << "Element " << elem << " with index "<<index<<" was added to the sequence" << endl;
#endif
	return *this;
}

template<class Elem>
Sequence<Elem>& Sequence<Elem>::cut() 
{
	return doremove(_size);
}

template<class Elem>
Sequence<Elem>& Sequence<Elem>::remove(const size_t index) 
{
	if ((_size < index) || (index == 0))
		throw BadSeq("Error! Attempt to delete a non existing element of the sequence");
	return doremove(index);
}


template<class Elem>
Sequence<Elem>& Sequence<Elem>::doremove(const size_t index) 
{
	assert(index <= _size);
	if (empty())
		throw BadSeq("Error! Attempt to manipulate an empty sequence");
	if (_size <= capacity() / 4)
		reduce();
	--_size;
	for (size_t i = index; (i <= _size) && (i > 0); ++i)
		operator[](i - 1) = operator[](i);
#ifndef NDEBUG
	cout << "Element with index " << index << " was removed from the sequence" << endl;
#endif
	return *this;
}

template<class Elem>
void Sequence<Elem>::enlarge(const size_t times)
{
	Array<Elem>* newArray = new Array<Elem>(capacity()*2 + 1);
	for (size_t i = 0; i < _size; ++i)
		(*newArray)[i] = operator[](i);
	delete _allocator;
	_allocator = newArray;
#ifndef NDEBUG
	cout << "Sequence was enlarged to the capacity of "<< capacity() << endl;
#endif
}

template<class Elem>
bool Sequence<Elem>::contains(const Elem& elem)
{
	for (size_t i = 0; i < _size; i++) 
	{
		if (elem == (*_allocator)[i]) 
			return true;
	}
	return false;
}

template<class Elem>
void Sequence<Elem>::reduce()
{
	Array<Elem>* newArray = new Array <Elem> (capacity() / 2 + 1);
	for (size_t i = 0; i < _size; ++i)
		(*newArray)[i] = operator[](i);
	delete _allocator;
	_allocator = newArray;
#ifndef NDEBUG
	cout << "Sequence was reduced to the capacity of " << capacity() << endl;
#endif
}

