#pragma once
#include <iostream>
//---------------------------------------
//1. ���������� ���� Time
//
//2. ���������� ������, ���� ���������
//��������� ��� (���� Date) � ������� ���
//� ���� ������ ����� ������� ��������
//���� ���� ��������
//---------------------------------------

class Time
{
private:
	int _hours;
	int _minutes;
	int _seconds;
	//������� ��������, � ���� �������
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
	
	//���� �������� ������� �� ���� �������
	const Time& operator++ ();
	const Time operator++ (int);
	const Time& operator-- ();
	const Time operator-- (int);
};
//��������� ������� �������
double operator+ (const Time&, const Time&);
std::ostream& operator<<(std::ostream&, const Time &);

bool operator==(const struct tm *, const Time &);
bool operator!=(const struct tm *, const Time &);