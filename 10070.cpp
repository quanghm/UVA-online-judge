/*
 * 10070.cpp
 *
 *  Created on: May 18, 2015
 *      Author: quanghoang
 */
#include<iostream>
//#include<cstdio>
//#include<queue>
#include<string>
using namespace std;

int main() {

	int c, s = 0, a = 0, n = 0, l;
	string str;
	bool o, leap, first = true;
	while (getline(cin, str)) {
		if (first) {
			first = false;
		} else {
			printf("\n");
		}
		s = 0, a = 0, n = 0;
//		l = str.length();
		o = true, leap = false;
		l = str.length();
		for (int i = 0; i < l; i++) {
			c = str[i] - 48;
			s = (s + c) % 3;
			a = (c - a) % 11;
		}

		for (int i = l - 4; i < l; i++) {
			n = 10 * n + str[i] - 48;
		}
		if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) {
			cout << "This is leap year.\n";
			o = false;
			leap = true;
		}
		if (n % 5 == 0) {
			if (s == 0) {
				cout << "This is huluculu festival year.\n";
				o = false;
			}
			if (a % 11 == 0 && leap) {
				cout << "This is bulukulu festival year.\n";
				o = false;
			}
		}
		if (o) {
			cout << "This is an ordinary year.\n";
		}
	}
}
