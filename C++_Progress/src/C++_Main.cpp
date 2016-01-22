//============================================================================
// Name        : C_Pointer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include "core/point/Pointer.h"
#include "core/curl/CurlTest.h"
#include "core/jsoncpp/JsonCppTest.h"
#include "core/crypto/Crypto.h"
using namespace std;

int main() {
//	CurlTest curl;
//	curl.getUrl("/home/ruibiao/桌面/structAndUnion");
//	curl.postUrl("/home/ruibiao/桌面/hello");

//	JsonCppTest jsoncpp;
//	jsoncpp.deleteJsonString();

	Crypto c;
	c.aes();

//	void test01();
//	test01();

	return 0;
}

/**
 * 位域
 */
void test02() {
	struct bs {
		unsigned a :1;
		unsigned b :3;
		unsigned c :4;
	} bit, *pbit;
	bit.a = 1;
	bit.b = 7;
	bit.c = 15;
	printf("%d,%d,%d\n", bit.a, bit.b, bit.c);
	pbit = &bit;
	pbit->a = 0;
	pbit->b &= 3;
	pbit->c |= 1;
	printf("%d,%d,%d\n", pbit->a, pbit->b, pbit->c);
}

/**
 * 位运算符
 */
void test01() {
	int a = 9, b = 5, c;
	c = a & b;
	printf("a=%d\nb=%d\nc=%d\n", a, b, c);
}
