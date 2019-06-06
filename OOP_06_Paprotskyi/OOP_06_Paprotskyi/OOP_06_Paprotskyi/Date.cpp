//Made by Ihor Paprotskyi, SE, 2 year

#include "Date.h"
#include <ctime>

string Date::monthNames[12] = { "January", "February", "March", "April", "May", "June",
								"July", "August", "September", "October", "November", "December" };

bool Date::defaultSet = false;

Date Date::defaultDate = Date();

Date::Date(const int day, const Month month, const int year)
{
	fillDate(day, month, year);
}

Date::Date(const int d, const int m, const int y)
{
	fillDate(d, Month(m), y);
}

Date::Date(const Date& date) {
	fillDate(date.day(), Month(date.month()), date.year());
}

Date::~Date()
{
}

bool Date::leapYear(const int y)
{
	bool res;
	if (y % 4)
	{
		res = false;
	}
	else if (y % 100)
	{
		res = true;
	}
	else if (y % 400)
	{
		res = false;
	}
	else res = true;
	return res;
}


bool Date::thirtyDaysMonth(const int month)
{
	switch (month)
	{
	case apr:
	case jun:
	case sep:
	case nov:
		return true;
	default:
		return false;
	}
}

bool Date::thirtyOneDaysMonth(const int month)
{
	switch (Month(month))
	{
	case jan: case mar: case may:
	case jul: case aug: case oct: case dec:
		return true;
	default:
		return false;
	}
}

void Date::checkDate(const int day, const int month, const int year)
{
	if (day > 0 && month > 0 && month <= 12)
	{
		if (month == 2)
		{
			if ((leapYear(year) && day > 29) || (!leapYear(year) && day > 28))
				throw BadDate(day, month, year);
		}
		else if (((thirtyOneDaysMonth(month)) && day > 31) || ((thirtyDaysMonth(month)) && day > 30))
			throw BadDate(day, month, year);
	}
	else
	{
		throw BadDate(day, month, year);
	}
}

void Date::fillDate(const int d, const Month m, const int y)
{
	if (!defaultSet)
		setDefault();
	_day = d ? d : defaultDate._day;
	_month = m ? m : defaultDate._month;
	_year = y ? y : defaultDate._year;
	checkDate(_day, _month, _year);
#ifndef NDEBUG
	cout << "Filled date: " << *this << endl;
#endif
}

/*
Error C4996	'gmtime': This function or variable may be unsafe.
Consider using gmtime_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.OOP_05_Paprotskyi	d : \visual studio 17 projects\c & c++\oop_05_paprotskyi\oop_05_paprotskyi\oop_05_paprotskyi\date.cpp	117

ERROR SAYS THAT THIS FUNCTION IS TOO OLD (I've read the docs.microsoft.com)

*/
#pragma warning(disable : 4996)
void Date::setDefault()
{
	time_t timer; time(&timer);
	struct tm * today = gmtime(&timer);
	defaultDate._day = today->tm_mday;
	defaultDate._month = today->tm_mon;
	defaultDate._year = today->tm_year += 1900;

	defaultSet = true;
#ifndef NDEBUG
	cout << "Set default date: ";
	showDefault();
#endif
}

void Date::setDefault(const int day, const Month month, const int year)
{
	checkDate(day, month, year);
	defaultDate = Date(day, month, year);
	defaultSet = true;
#ifndef NDEBUG
	cout << "Set default date: ";
	showDefault();
#endif
}

void Date::setDay(const int day)
{
	checkDate(day, _month, _year);
	_day = day;
}

void Date::setMonth(const int month)
{
	checkDate(_day, month, _year);
	_month = month;
}

void Date::setYear(const int year)
{
	checkDate(_day, _month, year);
	_year = year;
}

void Date::showDefault()
{
	cout << defaultDate << endl;
}

const string Date::getMonthName() const
{
	return monthNames[_month - 1];
};

void Date::normalizeDate()
{
	//check the february:
	if (_month == 2)
	{
		//increment
		if (_day > 28 && leapYear(_year))
		{
			_day = 1;
			_month++;
		}
		else if (_day > 28)
		{
			_day = 1;
			_month++;
		}
		//decrement
		else if (_day < 1)
		{
			if (leapYear(_year))
			{
				_day = 29;
			}
			else
			{
				_day = 28;
			}
		}
	}
	//check decrement
	else if (_day < 1)
	{
		_month--;
		if (thirtyDaysMonth(_month))
		{
			_day = 30;
		}
		else
		{
			_day = 31;
		}
	}
	else if ((_day > 30 && thirtyDaysMonth(_month)) || (_day > 31 && thirtyOneDaysMonth(_month)))
	{
		_month++;
		_day = 1;
	}
	//final
	if (_month < 1) {
		_month = 12;
		_year--;
	}
	if (_month > 12) {
		_month = 1;
		_year++;
	}
}

const Date &Date::operator++()
{
	++_day;
	normalizeDate();
	return *this;
}
const Date Date::operator++(int)
{
	Date previous = *this;
	++*this;
	return previous;
}

const Date &Date::operator--()
{
	--_day;
	normalizeDate();
	return *this;
}

const Date Date::operator--(int)
{
	Date previous = *this;
	--*this;
	return previous;
}

ostream& operator<<(ostream& os, const Date& d)
{
	os << d.day() << ' ' << d.getMonthName() << ' ' << d.year();
	return os;
}

ostream& operator<<(ostream& os, const Date::BadDate & bd)
{
	os << "Bad date: " << bd._day << ' ' << bd._month << ' ' << bd._year;
	return os;
}

bool operator==(const struct tm * d1, const Date & d2)
{
	return d1->tm_mday == d2.day() && d1->tm_mon + 1 == d2.month() && (d1->tm_year + 1900 == d2.year());
}
bool operator!=(const struct tm * d1, const Date & d2)
{
	return !(d1 == d2);
}