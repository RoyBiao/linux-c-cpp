/*
 * Box.cpp
 *
 *  Created on: 2015-11-22
 *      Author: ruibiao
 */

#include "Box.h"

Box::~Box(){

}

int Box::volume() {
	return length * width * height;
}

void Box::setLength(int length){
	this->length=length;
}

int Box::getLength(){
	return this->length;
}

