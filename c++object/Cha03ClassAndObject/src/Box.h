/*
 * Box.h
 *
 *  Created on: 2015-11-22
 *      Author: ruibiao
 */

#ifndef BOX_H_
#define BOX_H_

class Box {
public:
	Box(int l = 10, int w = 10, int h = 10) :
			length(l), width(w), height(h) {
	}
	virtual ~Box();
	int volume();
	void setLength(int length);
	int  getLength();
private:
	int length;
	int width;
	int height;
};

#endif /* BOX_H_ */
