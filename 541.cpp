/*
 * uva541.cpp
 *
 *  Created on: May 5, 2015
 *      Author: quanghoang
 */
#include <iostream>
using namespace std;

int n;
int in;

void check() {
	int re = 0, ce = 0;
	int r[100] = { }, c[100] = { };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> in;
			r[i] += in;
			c[j] += in;
		}
	}
	for (int j = 0; j < n; j++) {
		if (r[j] % 2) {
			if (re) {
				cout << "Corrupt\n";
				return;
			} else {
				re = j + 1;
			}
		}
		if (c[j] % 2) {
			if (ce) {
				cout << "Corrupt\n";
				return;
			} else {
				ce = j + 1;
			}
		}
	}

	if (ce) {
		cout << "Change bit (" << re << "," << ce << ")\n";
		return;
	} else {
		cout << "OK\n";
	}
}

int main() {

	bool flag;
	while ((cin >> n) && (n)) {
		check();
	}
}

