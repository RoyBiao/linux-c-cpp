/*
 * JsonCppTest.h
 *
 *  Created on: 2015-12-12
 *      Author: ruibiao
 */

#ifndef JSONCPPTEST_H_
#define JSONCPPTEST_H_
#include <iostream>
#include <json/json.h>
class JsonCppTest {
public:
	JsonCppTest();
	virtual ~JsonCppTest();
	void fromJsonString();
	void toJsonString();
	void deleteJsonString();

};

#endif /* JSONCPPTEST_H_ */
