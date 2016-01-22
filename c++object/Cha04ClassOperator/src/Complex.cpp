/*
 * Complex.cpp
 *
 *  Created on: 2015-12-11
 *      Author: ruibiao
 */

#include "Complex.h"


Complex::~Complex() {
}

//Complex Complex::operator +(Complex & complex) {
//	Complex temp;
//	temp.real = this->real + complex.real;
//	temp.imag = this->imag + complex.imag;
//	return temp;
////	return Complex(this->real + complex.real, this->imag + complex.imag);
//}

Complex operator +(Complex complex1,Complex complex2){
	return Complex(complex1.real + complex2.real,complex1.imag + complex2.imag);
}

ostream& operator <<(ostream & output, Complex & complex) {
	output << "(" << complex.real << "+" << complex.imag << "i"<<")";
	return output;
}

istream& operator >>(istream & input, Complex & complex) {
	cout << "please input:";
	input >> complex.real >> complex.imag;
	return input;
}

void Complex::display(){
	cout << "(" << real << "+" << imag << "i"<<")";
}
