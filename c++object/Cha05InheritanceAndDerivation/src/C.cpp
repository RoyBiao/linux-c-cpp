/*
 * C.cpp
 *
 *  Created on: 2015-12-17
 *      Author: ruibiao
 */

#include "C.h"

C::C() {
	cout << "constructing C()" << endl;
	c = 0;
}
C::C(int i) :
		A(i) {
	cout << "constructing C(int i)" << endl;
	c = 0;
}
C::C(int i, int j) :
		A(i, j) {
	cout << "constructing C(int i, int j)" << endl;
	c = 0;
}
C::C(int i, int j, int k) :
		A(i, j) {
	cout << "constructing C(int i, int j, int k)" << endl;
	c = k;
}

C::~C() {
	cout << "destructing C()" ;
	display1();
}

void C::display1() {
	display();
	cout << " c=" << c << endl;
}

