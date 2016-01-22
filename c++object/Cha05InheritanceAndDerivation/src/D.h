/*
 * D.h
 *
 *  Created on: 2015-12-17
 *      Author: ruibiao
 */

#ifndef D_H_
#define D_H_
#include "C.h"
#include "B.h"
class D : public C,public B{
public:
	D(int i, int j);
	virtual ~D();

};

#endif /* D_H_ */
