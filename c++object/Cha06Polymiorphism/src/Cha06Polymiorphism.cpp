//============================================================================
// Name        : Cha06Polymiorphism.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Cylinder.h"
#include "Shape.h"
using namespace std;

int main() {
	void test02();
	test02();
	return 0;
}

/**
 * 虚函数和纯虚函数
 */
void test02() {
	Point p(3, 4);
	cout << p << endl;
	Circle c(3, 4, 5);
	cout << c << endl;
	Cylinder cy(3, 4, 5, 5);
	cout << cy << endl;

	Shape * shape;
	shape = &p;
	shape->shapeName();
	cout << "area=" << shape->area() << ",volume=" << shape->volume() << endl;
	shape = &c;
	shape->shapeName();
	cout << "area=" << shape->area() << ",volume=" << shape->volume() << endl;
	shape = &cy;
	shape->shapeName();
	cout << "area=" << shape->area() << ",volume=" << shape->volume() << endl;
}

/**
 * 多态
 */
void test01() {
	Cylinder c(3.5, 6.4, 5.2, 10);
	cout << c << endl;
	Point &p = c;
	cout << p << endl;
	Circle &ci = c;
	cout << ci << endl;

}
