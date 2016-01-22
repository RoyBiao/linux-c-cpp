/*
 * CurlTest.h
 *
 *  Created on: 2015-12-9
 *      Author: ruibiao
 */

#ifndef CURLTEST_H_
#define CURLTEST_H_
#include <stdio.h>
#include <curl/curl.h>
class CurlTest {
public:
	CurlTest();
	virtual ~CurlTest();
	bool getUrl(char *filename);
	bool postUrl(char *filename);
};

#endif /* CURLTEST_H_ */
