//Made by Ihor Paprotskyi, SE, 2nd year
#pragma once
template <class T>
class ASet
{
public:
	virtual ASet& add(const T&) = 0;
	virtual const size_t size() const = 0;
	virtual const T& operator[](const size_t) const = 0;
	virtual const bool contains(const T&) = 0;
	virtual const size_t quantity_of(const T&) const = 0;

	virtual ~ASet() {};
};

template <class T>
ostream& operator<<(ostream& out, ASet<T>& s)
{
	out << '{';
	for (size_t i = 0; i < s.size(); ++i)
	{
		out << s[i] << (i != s.size() - 1 ? ", " : "");
	}
	out << '}';
	return out;
}