/*
 * 10424.cpp
 *
 *  Created on: May 26, 2015
 *      Author: quang
 */
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main() {
	string line;
	int s1, s2;
	double p;

	while (getline(cin, line)) {
		s1 = 0;
		for (string::iterator it = line.begin(); it != line.end(); it++) {

			if (isalpha(*it)) {
				s1 += tolower(*it) - 96;
			}
		}
		if (s1) {
			s1 = (s1 % 9);
			s1 = (s1) ? s1 : 9;
		} else {
			s1 = 0;
		}
		getline(cin, line);
		s2 = 0;
		for (string::iterator it = line.begin(); it != line.end(); it++) {
			if (isalpha(*it)) {
				s2 += tolower(*it) - 96;
			}
		}
		if (s2) {
			s2 %= 9;
			s2 = (s2) ? s2 : 9;
		} else {
			s2 = 0;
		}
		if (s1 || s2) {
			if (s1 < s2) {
				p = (100.0 * s1) / (s2 * 1.0);
			} else {
				p = (100.0 * s2) / (s1 * 1.0);
			}
			printf("%.2f %%\n", p);
		} else {
			printf("\n");
		}
	}
}

