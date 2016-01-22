/*
 * A.h
 *
 *  Created on: 2015-12-17
 *      Author: ruibiao
 */

#ifndef A_H_
#define A_H_
#include <iostream>
using namespace std;
class A {
public:
	A();
	A(int i);
	A(int i,int j);
	virtual ~A();
	void display();
private:
	int a;
	int b;
};

#endif /* A_H_ */
