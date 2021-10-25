//Ranit Zohar 
// שאלה 4
// סדנא ב C
//the program help to mennegment ATMS

#pragma once
#include <iostream>
using namespace std;

class Clock
{

private:
	int hour;
	int minute;
	int second;


public:
	Clock();  // defult- constructors
	Clock(int myHour = 0, int myMinute = 0, int mySecond = 0); // constructors that get the receives values
	Clock(const Clock& myClock); // copy constructors
	void setHour(int myHour);
	void setMinute(int myMinute);
	void setSecond(int mySecond);
	int getHour()const;
	int getMinute()const;
	int getSecond()const;
	Clock operator+=(int mySecond);
	friend ostream& operator<<(ostream& os, const Clock & num);
	friend istream& operator >> (istream& is, Clock & num);
};
