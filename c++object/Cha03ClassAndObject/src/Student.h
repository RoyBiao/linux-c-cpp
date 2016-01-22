/*
 * Student.h
 *
 *  Created on: 2015-12-5
 *      Author: ruibiao
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
using namespace std;
class Student {
public:
	Student(int n, int a, int s) :
			num(n), age(a), score(s) {
	}
	virtual ~Student();
	void total();
	void diaplay();
	void max(Student *stus, int length);
	void change(int, int, int);
	void fun(Student &stu,const int num,const int age,const int score);
public:
	static float average(Student &stu);
	void cdisplay() const;
	void cchange(int) const;
private:
	int num;
	int age;
	mutable float score;
	static float sum;
	static int count;
};

#endif /* STUDENT_H_ */
