//============================================================================
// Name        : Cha05InheritanceAndDerivation.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "B.h"
#include "D.h"
using namespace std;

int main() {
	void test02();
	test02();
	return 0;
}

/**
 * 虚基类
 */
void test02(){
	D d(2,3);
	d.display();
}

/**
 * 继承方式 、构造函数、析构函数
 */
void test01() {
	B b1;
	B b2(1);
	B b3(1, 3);
	B b4(1, 3, 5);
	b1.display1();
	b2.display1();
	b3.display1();
	b4.display1();
}
