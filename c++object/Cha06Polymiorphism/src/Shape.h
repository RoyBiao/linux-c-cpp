/*
 * Shape.h
 *
 *  Created on: 2015-12-28
 *      Author: ruibiao
 */

#ifndef SHAPE_H_
#define SHAPE_H_

class Shape {
public:
	Shape() {
	}
	virtual ~Shape() {
	}
	virtual float area() const { //虚函数
		return 0.0;
	}
	virtual float volume() const { //虚函数
		return 0.0;
	}
	virtual void shapeName() const = 0; //纯虚函数
};

#endif /* SHAPE_H_ */
