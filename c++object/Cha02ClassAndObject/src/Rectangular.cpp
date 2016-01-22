/*
 * Rectangular.cpp
 *
 *  Created on: 2015-11-22
 *      Author: ruibiao
 */

#include "Rectangular.h"

Rectangular::Rectangular() {
}

Rectangular::~Rectangular() {
}
void Rectangular::set_value() {
	cin >> length;
	cin >> width;
	cin >> length;
}

void Rectangular::calculate_volume() {
	volume = length * width * length;
}

void Rectangular::show_value() {
	cout << "volume:" << volume << endl;
}

