/*
 * Time.h
 *
 *  Created on: 2015-11-22
 *      Author: ruibiao
 */

#ifndef TIME_H_
#define TIME_H_
#include <iostream>
using namespace std;
class Date;
class Time {
public:
	Time(int h = 10, int m = 10, int s = 10) :
			hour(h), minute(m), sec(s) {
	}
	virtual ~Time();
	void get_time();
	friend void display3(const Time &,const Date &);
	friend void display(Time &);
	void display2(Date &);
	int hour;
private:
	int minute;
	int sec;

};

class Date {
public:
	Date(int m=12, int d=6, int y=2015) :
			month(m), day(d), year(y) {
	}

	friend void display3(const Time &, const Date &);
	friend void Time::display2(Date &);
private:
	int month;
	int day;
	int year;
};


#endif /* TIME_H_ */
