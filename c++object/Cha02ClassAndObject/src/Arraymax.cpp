/*
 * Arraymax.cpp
 *
 *  Created on: 2015-11-22
 *      Author: ruibiao
 */

#include "Arraymax.h"

Array_max::Array_max() {
}

Array_max::~Array_max() {
}

void Array_max::set_value() {
	int i;
	for (i = 0; i < 5; i++) {
		cin >> array[i];
	}
}

void Array_max::max_value() {
	int i;
	max = array[0];
	for (i = 1; i < 10; i++) {
		if (array[i] > max)
			max = array[i];
	}
}

void Array_max::show_value() {
	cout << "max=" << max;
}
