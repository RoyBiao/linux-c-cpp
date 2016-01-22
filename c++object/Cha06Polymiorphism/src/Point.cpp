/*
 * Point.cpp
 *
 *  Created on: 2015-12-27
 *      Author: ruibiao
 */

#include "Point.h"

Point::~Point() {
}

void Point::setPoint(float a, float b) {
	x = a;
	y = b;
}

void Point::shapeName() const {
	cout << "Point:";
}

ostream & operator <<(ostream & output, const Point & p) {
	output << "[" << p.x << "," << p.y << "]" << endl;
	return output;
}
