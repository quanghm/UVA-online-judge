/*
 * uva264.cpp
 *
 *  Created on: May 5, 2015
 *      Author: quanghoang
 */
#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int n;
	int k;
	int x, y;
	while (cin >> n) {
		k = floor(sqrt(2 * n));
		if (k * k + k < 2 * n) {
			k += 1;
		}
		x = (k + 1) * k / 2 - n + 1;
		y = k + 1 - x;

		if (k % 2) {
			cout<<"TERM "<<n<<" IS " << x << "/" << y << endl;
		} else {
			cout << "TERM "<<n<<" IS " << y<< "/" << x << endl;
		}
	}
}

