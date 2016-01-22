//============================================================================
// Name        : cha03ClassAndObject2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++,i Ansi-style
//============================================================================

#include <iostream>
#include "Box.h"
#include "Time.h"
#include "Student.h"
#include "Compare.h"
#include "SaleStaff.h"
using namespace std;

/**
 * test09和test10有疑问
 */
int main() {
	void test10();
	test10();
	return 0;
}

/**
 * 课后练习10，友元函数
 */
void test12() {
	Time t(10, 10, 10);
	Date d(10, 10, 2015);
//	dislpay3(t,d);
}

/**
 * 课后练习9,静态变量，静态函数
 */
void test11() {
	SaleStaff sta1(101, 5, 20);
	sta1.average();
	SaleStaff sta2(102, 12, 25);
	sta2.average();
	SaleStaff sta3(101, 5, 10);
	sta3.average();

	SaleStaff::display();
}

/**
 * 课后练习4，5，6，7，8指针和数组
 */
void test10() {
	Student stus[5] = { Student(1001, 18, 70), Student(1002, 18, 73), Student(
			1003, 19, 75), Student(1004, 16, 78), Student(1005, 20, 90) };
	Student *stu = stus;
	(*stu).diaplay();
	(*(stu + 2)).diaplay();
	(*(stu + 4)).diaplay();
	cout << endl;
	//分数最大
	(*stu).max(stu, 5);
	cout << endl;
	//修改
	(*stu).change(1001, 18, 100);
	(*stu).diaplay();
	cout << endl;
	//const对象
	const Student stu1(1006, 20, 93);
	stu1.cdisplay();
	stu1.cchange(95);
	stu1.cdisplay();
	cout << endl;
	//指向常对象的指针变量
	Student stu2(1006, 20, 93);
	const Student *p = &stu2;
	(*p).cdisplay();
	(*p).cchange(95);
	(*p).cdisplay();
	cout << endl;
	//指向对象的常指针
	Student stu3(1006, 20, 93);
	Student * const p2 = &stu3;
	(*p2).cdisplay();
	(*p2).cchange(96);
	(*p2).cdisplay();
	(*p2).change(1001, 18, 100);
	(*p2).diaplay();
	cout << endl;
	//对象引用
	Student stu4(1006, 20, 93);
	stu4.fun(stu4, 1006, 20, 100);
	cout << endl;
}

/**
 * 类模版
 */
void test09() {
	Compare<int> c_int(3, 4);
//	cout << "max:" << c_int.max() << endl;
//	cout << "min:" << c_int.min() << endl;
}

/**
 * 友元成员函数
 */
void test08() {
	Date d(12, 25, 2015);
	Time t(10, 13, 56);
	t.display2(d);
}

/**
 * 将普通函数声明为友元函数
 */
void test07() {
	Time t(10, 13, 56);
	display(t);
}

/**
 * 静态数据成员和静态成员函数
 */
void test06() {
	Student stus[3] = { Student(1001, 16, 70), Student(1002, 17, 80), Student(
			1003, 18, 90) };

	for (int i = 0; i < 3; i++) {
		stus[i].total();
	}

	cout << "average:" << Student::average(stus[3]) << endl;
}

/**
 * 对象的复制和赋值
 */
void test05() {
	Box box1(20, 20, 20), box2;
	cout << "box1:" << box1.volume() << endl;
	box2 = box1;
	cout << "box2:" << box2.volume() << endl;
	Box box3(box1);
	cout << "box3:" << box3.volume() << endl;
	box3.setLength(30);
	cout << "box3:" << box3.volume() << endl;
	cout << "box1:" << box1.volume() << endl;
}

/**
 * 对象指针
 */
void test04() {
	//指向对象数据成员的指针
	Time t1(10, 13, 56);
	int *p1 = &t1.hour;
	cout << "*p1=" << *p1 << endl;
	t1.get_time();
	//指向对象的指针
	Time *p2 = &t1;
	p2->get_time();
	//指向对象成员函数的指针
	void (Time::*p3)();
	p3 = &Time::get_time;
	(t1.*p3)();
}

/**
 * 指向普通函数的指针变量方法
 */
void test03() {
	void test02();
	void (*p)();
	p = test02;
	p();
}
/**
 * 数组对象
 */
void test02() {
	Box boxs[3] = { Box(10, 10, 10), Box(20, 20, 20), Box(30, 30, 30) };
	int i;
	for (i = 0; i < 3; i++) {
		cout << "box[" << i << "]:" << boxs[i].volume() << endl;
	}
}

/**
 *1.构造函数参数初始化
 *2.使用默认参数的构造函数
 */
void test01() {
	Box box1;
	cout << "box1:" << box1.volume() << endl;
	Box box2(15);
	cout << "box2:" << box2.volume() << endl;
	Box box3(15, 20);
	cout << "box3:" << box3.volume() << endl;
	Box box4(15, 20, 30);
	cout << "box4:" << box4.volume() << endl;
}
