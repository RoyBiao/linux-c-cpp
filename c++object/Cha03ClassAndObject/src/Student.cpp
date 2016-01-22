/*
 * Student.cpp
 *
 *  Created on: 2015-12-5
 *      Author: ruibiao
 */

#include "Student.h"

int Student::count = 0;
float Student::sum = 0;

Student::~Student() {
	// TODO Auto-generated destructor stub
}

void Student::total() {
	sum += score;
	count++;
}

float Student::average(Student &stu) {
	cout << "stu score:" << stu.score << endl;
	return sum / count;
}

void Student::diaplay() {
	cout << "number:" << num << ",age:" << age << ",score:" << score << endl;
}

void Student::max(Student *stus, int length) {
	int temp = stus->score;
	for (int i = 1; i < length; i++) {
		if (temp < (stus + i)->score) {
			temp = (stus + i)->score;
		}
	}
	cout << "max score is :" << temp << endl;
}

void Student::change(int num, int age, int score) {
	this->num = num;
	this->age = age;
	this->score = score;
}

void Student::fun(Student &stu,const int num,const int age,const int score){
	stu.change(num,age,score);
	stu.diaplay();
}


void Student::cdisplay() const{
	cout << "number:" << num << ",age:" << age << ",score:" << score << endl;
}


void Student::cchange(int score) const{
	this->score = score;
}

