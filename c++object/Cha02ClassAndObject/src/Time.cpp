/*
 * Time.cpp
 *
 *  Created on: 2015-11-22
 *      Author: ruibiao
 */
#include "Time.h"

Time::Time() {

}

Time::~Time() {
}

void Time::set_time() {
	cin >> hour;
	cin >> minute;
	cin >> sec;
}

void Time::show_time() {
	cout << hour << ":" << minute << ":" << sec << endl;
}

