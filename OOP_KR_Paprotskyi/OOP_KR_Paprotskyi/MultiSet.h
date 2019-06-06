//Made by Ihor Paprotskyi, SE, 2nd year
#pragma once
#include "ASet.h"
/*
* I chose this hierarchy instead of ASet <- Set(with protected field of Sequence* ) <- MultiSet
* in order to get rid of the possibility to create the cheater class 
* which can open the way to our sequence by writing, for example, public selector-modificator of the sequence, or operator[].
* Yes, this hierarchy has a lot of code being copied. However, it has private sequence field.
*/
template <class T>
class MultiSet : public ASet<T> 
{
private:
	MultiSet(const MultiSet&);
	MultiSet& operator=(const MultiSet&);
	Sequence<T>* _seq;
public:
	MultiSet();
	MultiSet(size_t capacity);
	MultiSet<T>& add(const T& el) override;
	const size_t size() const { return _seq->size(); }
	const size_t capacity() const { return _seq->capacity(); }

	const bool contains(const T& t) { return _seq->contains(t); }
	const size_t quantity_of(const T&) const;

	const T& operator[](const size_t i) const
	{
		return _seq->operator[](i);
	}
	~MultiSet();
};

template <class T>
MultiSet<T>::MultiSet() :
	_seq(new Sequence<T>)
{
#ifndef NDEBUG
	cout << "MultiSet was created" << endl;
#endif // NDEBUG
}

template <class T>
MultiSet<T>::MultiSet(size_t capacity) :
	_seq(new Sequence<T>(capacity))
{
#ifndef NDEBUG
	cout << "MultiSet was created" << endl;
#endif // NDEBUG
}

template <class T>
MultiSet<T>::~MultiSet()
{
	delete _seq;
#ifndef NDEBUG
	cout << "MultiSet was destroyed" << endl;
#endif
}

template <class T>
MultiSet<T>& MultiSet<T>::add(const T& el)
{
	_seq->add(el);
//#ifndef NDEBUG //A lot of text in main :(
//	cout << "Element was added to the set" << endl;
//#endif
	return *this;
}

//quantity of element
template<class T>
const size_t MultiSet<T>::quantity_of(const T& el) const
{
	size_t res = 0;
	for (size_t i = 0; i < size(); ++i)
	{
		if ((*_seq)[i] == el)
			++res;
	}
	return res;
}