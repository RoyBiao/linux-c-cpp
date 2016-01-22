/*
 * Cylinder.h
 *
 *  Created on: 2015-12-27
 *      Author: ruibiao
 */

#ifndef CYLINDER_H_
#define CYLINDER_H_
#include "Circle.h"
#include <iostream>
using namespace std;
class Cylinder: public Circle {
public:
	Cylinder(int a, int b, int c, int d) :
			Circle(a, b, c), height(d) {
	}
	virtual ~Cylinder();
	void setHeight(float);
	float getHeight() const;
	virtual float area() const;
	virtual float volume() const;
	virtual void shapeName() const;
	friend ostream & operator <<(ostream &, const Cylinder &);
protected:
	float height;
};

#endif /* CYLINDER_H_ */
