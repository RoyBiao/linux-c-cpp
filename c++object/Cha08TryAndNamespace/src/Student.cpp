/*
 * Student.cpp
 *
 *  Created on: 2015-12-13
 *      Author: ruibiao
 */

#include "Student.h"

void Student::get_data() {
	if (num == 0) {
		throw num;
	} else {
		cout << num << ":" << name << endl;
	}
	cout << "in get_data()" << endl;

}
