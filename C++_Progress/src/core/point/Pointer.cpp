/*
 * Pointer.cpp
 *
 *  Created on: 2015-9-30
 *      Author: ruibiao
 */

#include "Pointer.h"

Pointer::Pointer() {

}

Pointer::~Pointer() {
}

void Pointer::test() {
	//1.引用
	cout << "----------------引用--------------" << endl;
	int a, b;
	int &x = a, &y = b;
	x = 11;
	y = 22;
	cout << "a=" << a << " b=" << b << endl;
	x = y;
	cout << "a=" << a << " b=" << b << endl;

	//2.指针
	cout << endl << "----------------指针--------------" << endl;
	int c = 33;
	int *p = &c;
	cout << "p=" << p;
	cout << " *p=" << *p;
	cout << " c=" << c << endl;
	*p = 3333;
	cout << "c=" << c << endl;

	//3.指向指针的指针
	cout << endl << "----------------指向指针的指针--------------" << endl;
	int d = 44;
	int *p1 = &d;
	int **p2 = &p1;
	cout << **p2 << endl;

	//4.指针和数组
	cout << endl << "----------------指针和数组--------------" << endl;
	int val[10];
	for (int i = 0; i < 10; i++) {
		val[i] = i * i;
	}
	int * p3 = val;
	cout << *p3 << endl;
	int t = 10;
	while (t--) {
		cout << *(p3++) << endl;
	}
	int *p4 = &val[5];
	int *p5 = &val[7];
	cout << "*p5-*p4:" << p5 - p4 << endl;
	int e = p4 < p5 ? p5 - p4 : p4 - p5;
	cout << "e=" << e << endl;

	//5.多维数组(对于多维数组，只要把指向指针的指针理解好了就行)
	cout << endl << "----------------多维数组--------------" << endl;
	int vals[100][100];
	vals[2][1] = 666;
	///如何用指针取出val[2][1]？
	printf("%d", *(*(vals + 2) + 1));
}

