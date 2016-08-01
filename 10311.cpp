/*
 * 10311.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: quanghoang
 */
/*
 * main.cpp
 *
 *  Created on: Apr 28, 2015
 *      Author: Quang Hoang
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int m = 10000;
vector<int> primes;
bool isPrime(int p) {
	for (vector<int>::iterator it = primes.begin(); it < primes.end(); it++) {
		if (p == *it) {
			return true;
		} else if (p % *it == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	int n = 101;
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

	while ((cin >> n) && (n)) {
		if (n < 5) {
			cout << n << " is not the sum of two primes!\n";
		} else if (n % 2) {
			if (isPrime(n - 2)) {
				cout << n << " is the sum of 2 and " << n - 2 << ".\n";
			} else {
				cout << n << " is not the sum of two primes!\n";
			}
		} else {
//			if (n > 6) {
			int i = n / 2;
			while (--i > 1) {
				if (isPrime(i) && isPrime(n - i)) {
					cout << n << " is the sum of " << i << " and " << n - i
							<< ".\n";
					break;
				}
			}
			if (i == 1) {
				cout << n << " is not the sum of two primes!\n";
			}
//			} else {
//				cout << n << " is not the sum of two primes!\n";
//			}
		}
	}
}

