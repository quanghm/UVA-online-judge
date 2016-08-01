/*
 * uva369.cpp
 *
 *  Created on: May 2, 2015
 *      Author: quang
 */
#include <iostream>
#include<math.h>
using namespace std;

int gcd(int a, int b) {
	if (!(a % b))
		return b;
	return gcd(b, a % b);
}

int main() {
	int m, n;
	while ((cin >> n >> m) && (n)) {
		cout << n << " things taken " << m << " at a time is ";
		if (m > n / 2) {
			m = n - m;
		}
		if (m == 0) {
			cout << "1 exactly." << endl;
		} else {
			long c = 1, l;
			int a[m]={};
			for (l = 0; l < m; l++) {
				a[l] = n - l;
			}
			for (int j = m; j; j--) {
				c = j;	// try to divide by j
				l = 0;
				do {
					n = gcd(a[l], c);
					c /= n;
					a[l++] /= n;
				}while (c!=1);
			}
			c=1;
			for (l = 0; l < m; l++) {
				c *= a[l];
			}
			cout << c << " exactly.\n";
		}
	}
}
