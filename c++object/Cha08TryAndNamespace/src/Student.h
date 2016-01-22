/*
 * Student.h
 *
 *  Created on: 2015-12-13
 *      Author: ruibiao
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
#include <string>
using namespace std;
class Student {
public:
	Student(int num,string name){
		cout << "construtor -"<<endl;
		this->num=num;
		this->name=name;
	}
	~Student(){
		cout << "destructor -"<<endl;
	}
	void get_data();
private:
	int num;
	string name;
};

#endif /* STUDENT_H_ */
