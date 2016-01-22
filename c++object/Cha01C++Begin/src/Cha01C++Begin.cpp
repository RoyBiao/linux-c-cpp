//============================================================================
// Name        : Cha01C++Begin.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
//	void test04();
//	test04();
	return 0;
}

/**
 *冒泡，函数模版
 */
template<typename T>
void test04() {
	void sort(T t[]);
	int intArray[] = { 3, 71, 16, 8, 38, 68 };
	char chatArray[] = { 'e', 'd', 'c', 'b', 'a' };
	string strArray[] = { "w", "d", "c", "b", "a" };
	sort(intArray);
	sort(chatArray);
	sort(strArray);
}
template<typename T>
void sort(T t[]) {
	int i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5 - 0; j++) {
			if (t[j] > t[j + 1]) {
				T temp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = temp;
			}
		}
	}
	int z;
	for (z = 0; z < 5; z++) {
		cout << t[z] << "\t";
	}
}

/**
 * 五个字符串从大到小(应使用数组)
 */
void test03() {
	void change(string &strX, string &strY);
	string str1, str2, str3, str4, str5;
	cin >> str1 >> str2 >> str3 >> str4 >> str5;
	if (str1 > str2)
		change(str1, str2);
	if (str1 > str3)
		change(str1, str3);
	if (str1 > str4)
		change(str1, str4);
	if (str1 > str5)
		change(str1, str5);
	if (str2 > str3)
		change(str2, str3);
	if (str2 > str4)
		change(str2, str4);
	if (str2 > str5)
		change(str2, str5);
	if (str3 > str4)
		change(str3, str4);
	if (str3 > str5)
		change(str3, str5);
	if (str4 > str5)
		change(str4, str5);
	cout << str1 << str2 << str3 << str4 << str5 << endl;
}

void change(string &strX, string &strY) {
	string temp = strX;
	strX = strY;
	strY = temp;
}

/**
 * 字符串倒着写
 */
void test02(string str) {
	int i, n;
	n = str.size();
	for (i = 0; i < n / 2; i++) {
		int temp = str[i];
		str[i] = str[n - i - 1];
		str[n - i - 1] = temp;
	}
	cout << "str:" << str << endl;
}

/**
 * 三个变量由大到小
 */
void test01() {
	void sort(int &a, int &b, int &c);
	int a, b, c;
	cin >> a >> b >> c;
	sort(a, b, c);
	cout << a << b << c << endl;
}

void sort(int &a, int &b, int &c) {
	void max(int &x, int &y);
	if (a < b)
		max(a, b);
	if (a < c)
		max(a, c);
	if (b < c)
		max(b, c);
}
void max(int &x, int &y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}
