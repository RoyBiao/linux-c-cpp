/*
 * Compare.h
 *
 *  Created on: 2015-12-5
 *      Author: ruibiao
 */

#ifndef COMPARE_H_
#define COMPARE_H_
template <class numtype>
class Compare {
public:
	Compare(numtype a,numtype b){
		x=a,
		y=b;
	}
	numtype max();
//	{
//		return x > y ? x : y;
//	}
	numtype min();
//	{
//		return x < y ? x : y;
//	}
private:
	numtype x;
	numtype y;
};

#endif /* COMPARE_H_ */
