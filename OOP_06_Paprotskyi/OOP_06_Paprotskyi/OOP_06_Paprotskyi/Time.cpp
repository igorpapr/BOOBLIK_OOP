//Made by Ihor Paprotskyi, SE, 2 year
#include "Time.h"

void Time::normalizeTime()
{
	_hours += ((_minutes + (_seconds / 60)) / 60);
	_minutes = (_minutes + (_seconds / 60)) % 60; 
	_seconds %= 60;
	if (_seconds < 0)
	{
		--_minutes;
		_seconds = 59;
		if (_minutes < 0)
		{
			--_hours;
			_minutes = 59;
		}
	}
}

Time::Time(int h, int m, int s) :
	_hours(h), _minutes(m), _seconds(s)
{
	normalizeTime();
}

Time::Time(const Time & t) :
	_seconds(t.seconds()), _minutes(t.minutes()), _hours(t.hours())
{
}

Time::~Time()
{
}

Time& Time::operator= (const Time & t)
{
	_seconds = t.seconds();
	_minutes = t.minutes();
	_hours = t.hours();
	return *this;
}

Time::operator int() const
{
	return _hours * 3600 + _minutes * 60 + _seconds;
}

Time::operator double() const
{
	double mins = _minutes + 59. / _seconds;
	double hrs = _hours + 59. / mins;
	return hrs;
}

int& Time::seconds()
{
	normalizeTime();
	return _seconds;
}

int& Time::minutes()
{
	normalizeTime();
	return _minutes;
}

int& Time::hours()
{
	normalizeTime();
	return _hours;
}


const Time& Time::operator++()
{
	++_seconds;
	normalizeTime();
	return *this;
}


const Time Time::operator++(int)
{
	Time prev = *this;
	++*this;
	return prev;
}

const Time& Time::operator--()
{
	--_seconds;
	normalizeTime();
	return *this;
}


const Time Time::operator--(int)
{
	Time prev = *this;
	--*this;
	return prev;
}


double operator+(const Time& t1, const Time& t2)
{
	return static_cast<double> (Time(t1.hours() + t2.hours(), t1.minutes() + t2.minutes(),
		t1.seconds() + t2.seconds()));
}


std::ostream & operator<<(std::ostream& out, const Time& t)
{
	return out << t.hours() << ":" << t.minutes() << ":" << t.seconds();
}

bool operator==(const struct tm * t2, const Time & t1)
{
	return t1.hours() == t2->tm_hour + 2 && t1.minutes() == t2->tm_min && t1.seconds() == t2->tm_sec;
}

bool operator!=(const struct tm * t2, const Time & t1)
{
	return !(t2 == t1);
}