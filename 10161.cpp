/*
 * uva10161.cpp
 *
 *  Created on: May 11, 2015
 *      Author: quang
 */
#include<iostream>
#include <math.h>
using namespace std;

int main() {
	long n, s, t;
	while ((cin >> n) && n) {
		s = floor(sqrt(n - 1)) + 1;
		t = s * (s - 1) + 1;	// diagonal (s,s);
		if (n > t) {
			if (s % 2) {
				cout << t + s - n << " " << s << "\n";
			} else {
				cout << s << " " << t + s - n << "\n";
			}
		} else {
			if (s % 2) {
				cout << s << " " << s + n - t << "\n";
			} else {
				cout << s + n - t << " " << s << "\n";
			}
		}
	}
}

