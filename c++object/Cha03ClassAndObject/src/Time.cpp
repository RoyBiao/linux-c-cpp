/*
 * Time.cpp
 *
 *  Created on: 2015-11-22
 *      Author: ruibiao
 */
#include "Time.h"


Time::~Time() {
}


void Time::get_time() {
	cout << hour << ":" << minute << ":" << sec << endl;
}

void display(Time &t){
	cout << t.hour << ":" << t.minute << ":" << t.sec << endl;
}

void Time::display2(Date &d){
	cout <<d.month << "/" << d.day<< "/" << d.year << endl;
	cout << hour << ":" << minute << ":" << sec << endl;
}

void dislpay3(const Time &t, const Date &d) {
	//cout << d.month << "/" << d.day << "/" << d.year << endl;
	//cout << t.hour << ":" << t.minute << ":" << t.sec << endl;
}
