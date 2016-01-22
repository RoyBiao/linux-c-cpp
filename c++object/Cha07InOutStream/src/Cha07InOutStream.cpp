//============================================================================
// Name        : Cha07InOutStream.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main() {
	void test02();
	test02();
	return 0;
}

struct student {
	int num;
	char name[20];
	float score;
};
/**
 * 对二进制文件的操作
 */
void test02() {
	student stud[5] = { 1001, "Li", 85, 1002, "Li2", 80, 1003, "Li3", 75, 1004,
			"Li4", 70, 1005, "Li5", 65 };
	fstream iofile("stud.bat", ios::in | ios::out | ios::binary);
	if (!iofile) {
		cerr << "open stud.bat error!" << endl;
		return;
	}
	iofile.write((char*) &stud[0], sizeof(stud));
	student stud1[5];
	for (int i = 0; i < 5; i = i + 2) {
		iofile.seekg(i * sizeof(stud[i]), ios::beg);
		iofile.read((char*) &stud1[i / 2], sizeof(stud1[0]));
		cout << stud1[i / 2].num << "" << stud1[i / 2].name << ""
				<< stud1[i / 2].score << endl;
	}
	cout << endl;
	stud[2].num = 1012;
	strcpy(stud[2].name,"Wu");
	stud[2].score = 60;
	iofile.seekp(2 * sizeof(stud[0]), ios::beg);
	iofile.write((char *) &stud[2], sizeof(stud[2]));
	iofile.seekg(0, ios::beg);
	student stud2[5];
	for (int i = 0; i < 5; i ++) {
		iofile.read((char *)&stud2[i],sizeof(stud2[i]));
		cout << stud2[i].num << "" << stud2[i].name << ""
						<< stud2[i].score << endl;
	}
	iofile.close();
}

/**
 * 对ASCII文件的操作
 */
void test01() {
	void save_to_file();
	void get_from_file();
	save_to_file();
	get_from_file();
}

void save_to_file() {
	ofstream outfile("f2.bat", ios::out);
	if (!outfile) {
		cerr << "open f2.bat error!" << endl;
		return;
	}
	char c[80];
	cin.getline(c, 80);
	for (int i = 0; c[i]; i++) {
		if ((c[i] >= 65 && c[i] <= 90) || (c[i] >= 97 && c[i] <= 122)) {
			outfile.put(c[i]);
			cout << c[i];
		}
	}
	cout << endl;
	outfile.close();
}

void get_from_file() {
	char ch;
	ifstream infile("f2.bat", ios::in);
	if (!infile) {
		cerr << "open f2.bat error!" << endl;
		return;
	}
	ofstream outfile("f3.bat");
	if (!outfile) {
		cerr << "open f3.bat error!" << endl;
		return;
	}
	while (infile.get(ch)) {
		if (ch >= 97 && ch <= 122) {
			ch = ch - 32;
			outfile.put(ch);
			cout << ch;
		}
	}
	cout << endl;
	infile.close();
	outfile.close();
}
