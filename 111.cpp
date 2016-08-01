/*
 * uva111.cpp
 *
 *  Created on: May 1, 2015
 *      Author: quanghoang
 */
#include <iostream>

using namespace std;
int main() {
	int n, t;
	int c[20]; // orders;
	int x[20]; // values;

	int L, lo, hi, mid;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> t;
		c[t] = i;
	}
	while (!cin.eof()) {
		for (int i = 0; i<n; i++) {
			cin >> x[i];
			cout<< x[i];
		}
		cout<< endl;
		int m[21] = { }; // indexes
		L=0;

		for (int i = 0; i < n; i++) {
			//binary search for largest j<L: cx[m[j]]<cx[i]
			lo = 1;
			hi = L;
			while (lo <= hi) {
				mid = lo + hi;
				mid = (mid % 2) ? (mid / 2 + 1) : (mid / 2);
				if (c[x[m[i]]] < c[x[i]]) {
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}

			// lo = length x[i]
			if (lo>L) L=lo;
		}
		cout<< L << endl;
		if (cin.eof()){break;}
	}

}
