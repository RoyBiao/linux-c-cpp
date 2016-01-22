/*
 * B.h
 *
 *  Created on: 2015-12-17
 *      Author: ruibiao
 */

#ifndef B_H_
#define B_H_
#include "A.h"
using namespace std;
class B:virtual public A {
public:
	B();
	B(int i);
	B(int i, int j);
	B(int i, int j,int k);
	virtual ~B();
	void display1();
private:
	int c;
};

#endif /* B_H_ */
