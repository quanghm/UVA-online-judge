/*
 * uva10006.cpp
 *
 *  Created on: May 9, 2015
 *      Author: quang
 */
#include<iostream>
using namespace std;

const int n = 65001;

bool a[n] = { 0 }; // if i is check
bool isCarmichael(int m) {
	if (!a[m]) {
		return false;
	}
	int p = 2, t = 0, q = m;
	while (p < q) {
		while ((q % p) || a[p]) {
			p++;
		}
		t = 1;
		while (q % p == 0) {
			if (t == 2 || (m - 1) % (p - 1)) {
				return false;
			}
			q /= p;
			t++;
		}
	}
	return true;
}
int main() {
	int i = 1, m;
	while (i++ < n) {
		while (a[i] && (i < n)) {
			i++;
		}
		for (int j = 2 * i; j < n; j += i) { // kill multiple of i
			a[j] = true;
		}
	}
	while ((cin >> m) && m) {
		if (isCarmichael(m)) {
			cout << "The number " << m << " is a Carmichael number.\n";
		} else {
			cout << m << " is normal.\n";
		}
	}

}
