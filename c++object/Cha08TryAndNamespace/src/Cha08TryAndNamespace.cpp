//============================================================================
// Name        : Cha05TryAndNamespace.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Student.h"

int main() {
	void test02();
	test02();
	return 0;
}

/**
 *异常处理课后练习
 */
void test02() {
	void fun();
	cout << "test begin" << endl;
	fun();
	cout << "test end" << endl;
}

void fun() {
	Student stu1(1001, "tan");
	stu1.get_data();
	try {
		Student stu2(0, "tan");
		stu2.get_data();
	} catch (int) {
		cout << "num is 0" << endl;
	}
}
/**
 * 异常处理
 */
void test01() {
	void f1();
	try {
		f1();
	} catch (double) {
		cout << "ERROR0!" << endl;
	}
	cout << "end0";
}

void f1() {
	void f2();
	try {
		f2();
	} catch (char) {
		cout << "ERROR1!" << endl;
	}
	cout << "end1";
}

void f2() {
	void f3();
	try {
		f3();
	} catch (int) {
		cout << "ERROR2!" << endl;
	}
	cout << "end02";
}

void f3() {
	double a = 0;
	try {
		throw a;
	} catch (double) {
		cout << "ERROR3!" << endl;
		throw a;
	}
	cout << "end3";
}
