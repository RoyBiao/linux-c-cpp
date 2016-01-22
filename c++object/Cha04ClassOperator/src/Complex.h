/*
 * Complex.h
 *
 *  Created on: 2015-12-11
 *      Author: ruibiao
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>
using namespace std;
/**
 * 复数
 */
class Complex {
public:
	Complex() {
		real = 0;
		imag = 0;
	}
	Complex(double r, double i) {
		real = r;
		imag = i;
	}
	Complex(double r) { //转换构造函数
		real = r;
		imag = 0;
	}
//	operator double(){  //类型转换函数
//		return real;
//	}
	virtual ~Complex();
//	Complex operator +(Complex &); //重载成员函数
	friend Complex operator+(Complex , Complex ); //重载友元函数
	friend ostream & operator <<(ostream &, Complex &); //重载友元函数
	friend istream & operator >>(istream &, Complex &); //重再友元函数
	void display();

private:
	double real; //实数
	double imag; //虚数
};

#endif /* COMPLEX_H_ */
