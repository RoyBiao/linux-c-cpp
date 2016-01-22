/*
 * B.cpp
 *
 *  Created on: 2015-12-17
 *      Author: ruibiao
 */

#include "B.h"

B::B() {
	cout << "constructing B()" << endl;
	c = 0;
}
B::B(int i) :
		A(i) {
	cout << "constructing B(int i)" << endl;
	c = 0;
}
B::B(int i, int j) :
		A(i, j) {
	cout << "constructing B(int i, int j)" << endl;
	c = 0;
}
B::B(int i, int j, int k) :
		A(i, j) {
	cout << "constructing B(int i, int j, int k)" << endl;
	c = k;
}

B::~B() {
	cout << "destructing B()" ;
	display1();
}

void B::display1() {
	display();
	cout << " c=" << c << endl;
}

