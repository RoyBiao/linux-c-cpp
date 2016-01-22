//============================================================================
// Name        : Cha04ClassOperator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Complex.h"
int main() {
	void test01();
	test01();
	return 0;
}

void test02(){
	Complex c1(3,4),c2(5,-10),c3;
	c3 = c1 + 2.5;
	c3.display();
}


/**
 * 成员函数和友元函数重载运算符
 */
void test01() {
	Complex c1, c2;
	cin >> c1 >> c2;
	cout << c1 << endl << c2 << endl;
}
