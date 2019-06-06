#pragma once
#include <iostream>
//---------------------------------------
//1. Реалізувати клас Time
//
//2. Реалізувати таймер, який вмикається
//вибраного дня (клас Date) в заданий час
//і подає сигнал через заданий інтервал
//часу після вмикання
//---------------------------------------

class Time
{
private:
	int _hours;
	int _minutes;
	int _seconds;
	//Функція службова, а тому закрита
	void normalizeTime();
public:
	explicit Time(int h = 0, int m = 0, int s = 0);
	Time(const Time&);
	~Time();
	
	Time& operator=(const Time&);
	
	operator int() const;
	operator double() const;

	const int hours() const { return _hours; }
	const int minutes() const { return _minutes; }
	const int seconds() const { return _seconds; }
	int& hours();
	int& minutes();
	int& seconds();
	
	//Зміна часового проміжку на одну секунду
	const Time& operator++ ();
	const Time operator++ (int);
	const Time& operator-- ();
	const Time operator-- (int);
};
//Додавання часових проміжків
double operator+ (const Time&, const Time&);
std::ostream& operator<<(std::ostream&, const Time &);

bool operator==(const struct tm *, const Time &);
bool operator!=(const struct tm *, const Time &);