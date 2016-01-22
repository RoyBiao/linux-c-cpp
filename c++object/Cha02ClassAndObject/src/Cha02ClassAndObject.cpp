//============================================================================
// Name        : Cha02ClassAndObject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Time.h"
#include "Arraymax.h"
#include "Rectangular.h"
using namespace std;

int main() {
	void test03();
	test03();
	return 0;
}

/**
 * 长方体体积
 */
void test03(){
	Rectangular rec;
	rec.set_value();
	rec.calculate_volume();
	rec.show_value();
}

/**
 * 数组中的最大值
 */
void test02(){
  Array_max am;
  am.set_value();
  am.max_value();
  am.show_value();
}

/**
 *类和对象的简单使用
 */
void test01(){
	Time t1;
	//t1.set_time();
	t1.show_time();

	Time t2;
	//t1.set_time();
	t2.show_time();
}
