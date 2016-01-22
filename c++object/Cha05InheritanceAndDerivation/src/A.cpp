/*
 * A.cpp
 *
 *  Created on: 2015-12-17
 *      Author: ruibiao
 */

#include "A.h"

A::A() {
	cout << "constructing A()" << endl;
	a = 0;
	b = 0;
}
A::A(int i) {
	cout << "constructing A(int i)" << endl;
	a = i;
	b = 0;
}
A::A(int i, int j) {
	cout << "constructing A(int i, int j)" << endl;
	a = i;
	b = j;
}

A::~A() {
	cout << "destructing A()";
	display();
}

void A::display() {
	cout << "a=" << a << " b=" << b;
}

