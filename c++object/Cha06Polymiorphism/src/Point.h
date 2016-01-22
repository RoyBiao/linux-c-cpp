/*
 * Point.h
 *
 *  Created on: 2015-12-27
 *      Author: ruibiao
 */

#ifndef POINT_H_
#define POINT_H_
#include <iostream>
#include "Shape.h"
using namespace std;
class Point: public Shape {
public:
	Point(float a = 0, float b = 0) :
			x(a), y(b) {
	}
	virtual ~Point();
	void setPoint(float a, float b);
	float getX() const;
	float getY() const;
	virtual void shapeName() const;
	friend ostream & operator <<(ostream &, const Point &);
protected:
	float x, y;
};

#endif /* POINT_H_ */
