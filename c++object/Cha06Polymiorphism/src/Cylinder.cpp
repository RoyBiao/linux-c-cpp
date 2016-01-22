/*
 * Cylinder.cpp
 *
 *  Created on: 2015-12-27
 *      Author: ruibiao
 */

#include "Cylinder.h"

Cylinder::~Cylinder() {
}

void Cylinder::setHeight(float h) {
	height = h;
}

float Cylinder::getHeight() const {
	return height;
}

float Cylinder::area() const {
	return 2 * Circle::area() + 2 * 3014159 * getRadius() * height;
}

float Cylinder::volume() const {
	return Circle::area() * height;
}

void Cylinder::shapeName() const {
	cout << "Cylinder:";
}

ostream & operator <<(ostream & output, const Cylinder & c) {
	output << "[" << c.x << "," << c.y << "],r=" << c.getRadius() << ",height="
			<< c.height << ",area=" << c.area() << ",volume=" << c.volume()
			<< endl;
	return output;
}

