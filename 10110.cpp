/*
 * uva10110.cpp
 *
 *  Created on: May 1, 2015
 *      Author: quanghoang
 */
#include <iostream>
#include<math.h>
#include<vector>

using namespace std;
const unsigned long u = 65536;
int main() {
	unsigned long n = 256, s;
	bool a[u] = { };
	vector<int> primes;
	bool isSquare;
	for (s = 2; s < n; s++) {
		if (!a[s])
			for (int j = s * s; j < u; j += s) {
				a[j] = 1;
			}
	}
	primes.push_back(2);
	for (int i = 3; i < u; i += 2) {
		if (!a[i]) {
			primes.push_back(i);
		}
	}

	while ((cin >> n) && n) {
		isSquare = true;
		for (vector<int>::iterator it = primes.begin();
				it != primes.end() && *it <= n; it++) {
			while (n % *it==0) {
				n /= *it;
				isSquare = !isSquare;
			}
			if (!isSquare) {
				break;
			}
		}
		if (n > 1) {
			isSquare = false;
		}

		if (isSquare) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	}
}

