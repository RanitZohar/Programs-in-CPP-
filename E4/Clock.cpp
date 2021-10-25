//Ranit Zohar 
// שאלה 4
// סדנא ב C
//the program help to mennegment ATMS



#include "Clock.h"
#include <iostream>
Clock::Clock(int myHour, int myMinute, int mySecond)
{
if (myHour > 23)
{
	hour = 0;
	minute = 0;
	second = 0;
	throw "Invalid time - more than 24 hours.";
}
else
if (myHour < 0)
{
	hour = 0;
	minute = 0;
	second = 0;
	throw "Invalid time - negative number of hours.";
}
else
hour = myHour;
if (myMinute > 59)
{
	hour = 0;
	minute = 0;
	second = 0;
	throw "Invalid time - more than 60 seconds.";
}
else
if (myMinute < 0)
{
	hour = 0;
	minute = 0;
	second = 0;
	throw "Invalid time - negative number of minutes.";
}
else
minute = myMinute;

if (mySecond > 59)
{
	hour = 0;
	minute = 0;
	second = 0;
	throw "Invalid time - more than 60 minutes";
}
else
if (mySecond < 0)
{
	hour = 0;
	minute = 0;
	second = 0;
	throw "Invalid time - negative number of seconds.";
}
else
second = mySecond;
}
Clock::Clock(const Clock& myClock)
{
	hour = myClock.getHour();
	minute = myClock.getMinute();
	second = myClock.getSecond();
}
void Clock::setHour(int myHour)
{
	if (myHour > 23)
	{
		hour = 0;
		throw "Invalid time - more than 24 hours.";
	}
	if (myHour < 0)
	{
		hour = 0;
		throw "Invalid time - negative number of hours.";
	}
	hour = myHour;
}
void Clock::setMinute(int myMinute)
{
	if (myMinute > 59)
	{
		minute = 0;
		throw "Invalid time - more than 60 minutes.";
	}
	if (myMinute < 0)
	{
		minute = 0;
		throw "Invalid time - negative number of minutes.";
	}
	minute = myMinute;
}
void Clock::setSecond(int mySecond)
{
	if (mySecond > 59)
	{
		second = 0;
		throw "Invalid time - more than 60 seconds.";
	}
	if (mySecond < 0)
	{
		second = 0;
		throw "Invalid time - negative number of seconds.";
	}
	second = mySecond;
}
int Clock::getHour()const
{
	return hour;
}
int Clock::getMinute()const
{
	return minute;
}
int Clock::getSecond()const
{
	return second;
}
Clock Clock:: operator+=(int number)
{
	second += number;
	if (second > 59)
	{
		minute += (second / 60);
		second = (second % 60);
	}
	if (minute > 59)
	{
		hour += minute / 60;
		minute = minute % 60;
	}
	if (hour > 23)
	{
		hour = hour % 23;
	}
	return *this;
}
ostream& operator<<(ostream& os, const Clock  & num)
{
	if (num.getHour() < 10)
		os << '0';
	os << num.hour;
	os << ':';
	if (num.getMinute() < 10)
		os << '0';
	os << num.minute;
	os << ':';
	if (num.getSecond() < 10)
		os << '0';
	os << num.second;
	return os;
}
istream& operator >> (istream& is, Clock & num)
{
	is >> num.hour;
	char points;
	is >> points;
	is >> num.minute;
	is >> points;
	is >> num.second;
	return is;
}
