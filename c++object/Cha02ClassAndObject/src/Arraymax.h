/*
 * Arraymax.h
 *
 *  Created on: 2015-11-22
 *      Author: ruibiao
 */

#ifndef ARRAYMAX_H_
#define ARRAYMAX_H_
#include <iostream>
using namespace std;
class Array_max {
public:
	Array_max();
	virtual ~Array_max();
	void set_value();
	void max_value();
	void show_value();
private:
	int array[5];
	int max;
};

#endif /* ARRAYMAX_H_ */
