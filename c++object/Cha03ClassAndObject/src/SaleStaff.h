/*
 * SaleStaff.h
 *
 *  Created on: 2015-12-6
 *      Author: ruibiao
 */

#ifndef SALESTAFF_H_
#define SALESTAFF_H_
#include <iostream>
using namespace std;
class SaleStaff {
public:
	SaleStaff(int n,int q,int p);
	virtual ~SaleStaff();
	float average(); //平均价格
	static void display();
private:
	int num; //编号
	int quantity; //销售数量
	float price; //销售价格
	static float discout; //折扣
	static float sum; //销售总额
	static float acount; //总数量
};

#endif /* SALESTAFF_H_ */
