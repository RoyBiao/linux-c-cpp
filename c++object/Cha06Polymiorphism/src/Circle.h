/*
 * Circle.h
 *
 *  Created on: 2015-12-27
 *      Author: ruibiao
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_
#include "Point.h"
#include <iostream>
using namespace std;
class Circle: public Point {
public:
	Circle(int a = 0, int b = 0, int c = 0) :
			Point(a, b), radius(c) {
	}
	virtual ~Circle();
	void setRadius(float);
	float getRadius() const;
	virtual float area() const;
	virtual void shapeName() const;
	friend ostream & operator <<(ostream &, const Circle &);
private:
	float radius;
};

#endif /* CIRCLE_H_ */
