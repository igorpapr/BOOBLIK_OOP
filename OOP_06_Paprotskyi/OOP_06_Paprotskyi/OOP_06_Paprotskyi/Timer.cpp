//Made by Ihor Paprotskyi, SE, 2 year
#include "Timer.h"

Timer::Timer(Date & date, Time & time, Time & interval) :
	_date(date), _time(time), _interval(interval)
{
	checkStart();
}

Timer::~Timer()
{

}

Timer& Timer::operator=(const Timer & tr)
{
	_time = tr.tr_time();
	_date = tr.date();
	_interval = tr.interval();
	return *this;
}

#pragma warning(disable : 4996)
void Timer::checkStart()
{
	auto * today = new tm;
	time_t timer;
	time(&timer);
	today = gmtime(&timer);

	if (badTime(date(), tr_time(), today)) {
		throw "Invalid date or time entered";
	}
}

bool Timer::badTime(Date & d, Time & t, tm * today)
{
	if (d.year() < today->tm_year + 1900) {
		return true;
	}
	else if (d.month() - 1 > today->tm_mon) {
		return true;
	}
	else if (d.day() < today->tm_mday) {
		return true;
	}
	else if (t.hours() >= 24) {
		return true;
	}
	else if (t.hours() - 2 < today->tm_hour) {
		return true;
	}
	else if (t.minutes() < today->tm_min) {
		return true;
	}
	return false;
}

Date Timer::date() const
{
	return _date;
}

Time Timer::tr_time() const
{
	return _time;
}

Time Timer::interval() const
{
	return _interval;
}

Date & Timer::date()
{
	return _date;
}

Time & Timer::tr_time()
{
	return _time;
}

Time & Timer::interval()
{
	return _interval;
}
#pragma warning(disable : 4996)
void Timer::turnOn()
{
	auto * td = new tm;
	time_t timer;
	time(&timer);
	td = gmtime(&timer);
	cout << "waiting: " << date() << " : " << tr_time() << endl;

	while (td != date() || td != tr_time()) {
		time(&timer);
		td = gmtime(&timer);
		Sleep(1000);
		cout << td->tm_mday << "/" << td->tm_mon + 1 << "/" << td->tm_year + 1900 << "\n" << td->tm_hour << ":"
			<< td->tm_min << ":" << td->tm_sec << endl;
	}
	Time interval = _interval;
	cout << "Start of the timer!" << endl;
	do {
		Sleep(1000);
		cout << interval << endl;
		--interval;
	} while (static_cast<int>(interval));
	cout << "ALARM" << endl;
}



