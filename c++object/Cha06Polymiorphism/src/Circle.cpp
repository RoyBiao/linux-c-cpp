/*
 * Circle.cpp
 *
 *  Created on: 2015-12-27
 *      Author: ruibiao
 */

#include "Circle.h"

Circle::~Circle() {
}

void Circle::setRadius(float r) {
	radius = r;
}

float Circle::getRadius() const {
	return radius;
}

float Circle::area() const {
	return 3.14159 * radius * radius;
}

void Circle::shapeName() const {
	cout << "Circle:";
}

ostream & operator <<(ostream & output, const Circle & c) {
	output << "[" << c.x << "," << c.y << "],r=" << c.radius << ",area="
			<< c.area() << endl;
	return output;
}
