/*
 * uva530.cpp
 *
 *  Created on: May 5, 2015
 *      Author: quanghoang
 */
#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, k, d, j, g;

	int a[100] = { };

	while ((cin >> n >> k) && (n)) {
		if (k > n / 2) {
			k = n - k;
		}
		if (k == 0) {
			cout << 1 << endl;
		} else if (k == 1) {
			cout << n << "\n";
		} else {
			for (int i = 0; i < k; i++) {
				a[i] = n - i;
			}
			for (int i = 2; i <= k; i++) { // to be divided
				d = i;
				j = 0;
				while ((j < i) && (d != 1)) {
					g = __gcd(d, a[j]);
					d /= g;
					a[j++] /= g;
				}
				d = 1;	//d now is result;
				for (j = 0; j < k; j++) {
					d *= a[j];
				}
			}
			cout << d << endl;
		}
	}
}
