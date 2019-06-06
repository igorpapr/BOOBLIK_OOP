#pragma once
#include <iostream>
#include <string>

using namespace std;
class Date
{
public:
	struct BadDate;
	enum Month
	{
		jan = 1, feb, mar, apr, may, jun,
		jul, aug, sep, oct, nov, dec
	};

	explicit Date(const int d = 0, const Month m = Month(0), const int y = 0);
	explicit Date(const int d, const int m, const int y);
	Date(const Date&);
	~Date();

	int day() const { return _day; };
	int month() const { return _month; };
	int year() const { return _year; };

	const string getMonthName() const;

	void setDay(const int);
	void setMonth(const int);
	void setYear(const int);

	static void setDefault(const int, const Month, const int);
	static void setDefault();

	static void showDefault();

	const Date& operator++();
	const Date  operator++(int);
	const Date& operator--();
	const Date  operator--(int);

private:
	int _day, _month, _year;
	static bool leapYear(int y);
	void fillDate(const int d, const Month m, const int y);
	static string monthNames[12];
	static bool defaultSet;
	static Date defaultDate;
	static void checkDate(const int d, const int m, const int y);
	void normalizeDate();
	static bool thirtyDaysMonth(const int month);
	static bool thirtyOneDaysMonth(const int month);

};
ostream& operator<<(ostream& os, const Date & d);

struct Date::BadDate
{
	int _day, _month, _year;
	BadDate(const int d, const int m, const int y) :
		_day(d), _month(m), _year(y)
	{};
};

ostream& operator<<(ostream& os, const Date::BadDate & bd);

bool operator==(const struct tm * d1, const Date & d2);
bool operator!=(const struct tm * d1, const Date & d2);
