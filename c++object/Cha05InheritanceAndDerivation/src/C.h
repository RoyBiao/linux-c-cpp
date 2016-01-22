/*
 * C.h
 *
 *  Created on: 2015-12-17
 *      Author: ruibiao
 */

#ifndef C_H_
#define C_H_
#include "A.h"
using namespace std;
class C:virtual public A {
public:
	C();
	C(int i);
	C(int i, int j);
	C(int i, int j,int k);
	virtual ~C();
	void display1();
private:
	int c;
};

#endif /* B_H_ */
