/*
 * Rectangular.h
 *
 *  Created on: 2015-11-22
 *      Author: ruibiao
 */

#ifndef RECTANGULAR_H_
#define RECTANGULAR_H_
#include <iostream>
using namespace std;
class Rectangular {
public:
	Rectangular();
	virtual ~Rectangular();
	void set_value(); 		//赋值
	void calculate_volume(); //计算体积
	void show_value();       //打印
private:
	int length;
	int width;
	int height;
	int volume; //体积
};

#endif /* RECTANGULAR_H_ */
