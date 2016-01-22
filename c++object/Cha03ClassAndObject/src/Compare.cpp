/*
 * Compare.cpp
 *
 *  Created on: 2015-12-5
 *      Author: ruibiao
 */

#include "Compare.h"

template<class numtype>
numtype Compare<numtype>::max() {
	return x > y ? x : y;
}

template<class numtype>
numtype Compare<numtype>::min() {
	return x < y ? x : y;
}

