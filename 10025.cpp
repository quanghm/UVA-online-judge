/*
 * 10025.cpp
 *
 *  Created on: May 15, 2015
 *      Author: quang
 */
#include<iostream>
#include<math.h>
using namespace std;

int main() {
	long n, s, k, c;
	bool first = true;
	cin >> c;
	while (c--) {
		cin >> k;
		if (first) {
			first = false;
		} else {
			cout << "\n";
		}
		if (k == 0) {
			cout << "3\n";
		} else {
			if (k < 0) {
				k *= -1;
			}
			n = floor(sqrt(8 * k + 1) - 1) / 2;
			s = (n * n + n) / 2;
			while ((k - s) % 2 || s < k) {
				n++;
				s += n;
			}
			cout << n << "\n";
		}
	}
}

