//Made by Ihor Paprotskyi, SE, 2 year
#pragma once

#pragma once

#include "Date.h"
#include "Time.h"
#include <ctime>
#include <Windows.h>

using namespace std;

class Timer
{
private:
	Date& _date;
	Time& _time;
	Time& _interval;

	void checkStart();
	bool badTime(Date & d, Time & t, tm * today);

public:
	Timer(Date & date, Time & time, Time & interval);
	~Timer();
	Timer & operator=(const Timer &);
	void turnOn();

	Date date() const;
	Time tr_time() const;
	Time interval() const;
	Date& date();
	Time& tr_time();
	Time& interval();
};