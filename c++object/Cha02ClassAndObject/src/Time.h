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
class Time {
public:
	Time();
	virtual ~Time();
	void set_time();
	void show_time();
private:
	int hour;
	int minute;
	int sec;
};

#endif /* TIME_H_ */
