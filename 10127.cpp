/*
 * uva10127.cpp
 *
 *  Created on: May 8, 2015
 *      Author: qhoang
 */
#include<iostream>
using namespace std;

int main() {
	int n, u, l;
	while (cin >> n) {
		u = 10, l = 1, n *= 9;

		while (u != 1) {
			u *= 10;
			u = u % n;
			l++;
		}
		cout << l << "\n";
	}
}

