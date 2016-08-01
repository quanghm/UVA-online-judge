/*
 * uva583.cpp
 *
 *  Created on: May 9, 2015
 *      Author: quang
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int m = 46341;
int main() {
	vector<int> primes;
	long n = 256;
	bool a[m] = { }; // if i is check
	for (int i = 2; i < n; i++) {
		if (!a[i])
			for (int j = i * i; j < m; j += i) { // kill multiple of i
				a[j] = true;
			}
	}
	primes.push_back(2);
	for (int j = 3; j < m; j += 2) {
		if (!a[j]) {
			primes.push_back(j);
		}
	}

	while ((cin >> n) && n) {
		cout << n << " = ";
		if (n < 0) {
			cout << "-1 x ";
			n = -n;
		}

		for (vector<int>::iterator it=primes.begin();it!=primes.end()&&*it<=n;it++){
			while (n % *it == 0) {
				n /= *it;
				cout << *it;
				if (n > 1) {
					cout << " x ";
				}
			}
		}
		if (n > 1) {
			cout << n;
		}
		cout << "\n";
	}
}
