/*
 * 11830.cpp
 *
 *  Created on: May 16, 2015
 *      Author: quanghoang
 */
#include <iostream>
#include<string>
#include<stdio.h>

using namespace std;

int main() {
	char d;
	string n;
	bool flag;	// first actual digit found
	while (cin >> d >> n) {
		if (d == 48 && n == "0") {
			break;
		}
		flag = false;
		for (string::iterator it = n.begin(); it != n.end(); it++) {
			if (*it != d) {
				if (*it != 48) {
					flag = true;
					putchar(*it);
				} else {
					if (flag) {
						putchar(48);
					}
				}
			}
		}
		if (!flag) {
			putchar(48);
		}
		putchar(10);
	}
}

