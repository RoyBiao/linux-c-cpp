/*
 * SaleStaff.cpp
 *
 *  Created on: 2015-12-6
 *      Author: ruibiao
 */

#include "SaleStaff.h"
float SaleStaff::discout = 0.98;
float SaleStaff::sum = 0;
float SaleStaff::acount = 0;

SaleStaff::SaleStaff(int n = 0, int q = 0, int p = 0) :
		num(n), quantity(q), price(p) {

}

SaleStaff::~SaleStaff() {
}

float SaleStaff::average() {
	sum += quantity > 10 ? quantity * price * discout : quantity * price;
	acount += quantity;
	return sum / acount;
}

void SaleStaff::display() {
	cout << "sum:" << sum << ",acount:" << acount << ",average:" << sum / acount
			<< endl;
}

