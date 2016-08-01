/*
 * 374.cpp
 *
 *  Created on: May 21, 2015
 *      Author: quanghoang
 */
#include<iostream>
using namespace std;

int main() {
	int b, p, n, m, phi;
	int primes[55] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
			53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
			127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191,
			193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257 };
	while (cin >> b >> p >> m) {
		n = m;
		phi = 1;
		b %= m;

		if (b > 1) {
			for (int i = 0; i < 55 && primes[i] <= n; i++) {
				if (n % primes[i] == 0) {
					n /= primes[i];
					phi *= primes[i] - 1;
					while (n % primes[i] == 0) {
						n /= primes[i];
						phi *= primes[i];
					}
				}
			}
			if (n > 1) {
				phi *= n - 1;
			}

			p %= phi;
			phi = 1;
			while (p--) {
				phi *= b;
				phi %= m;
			}
			cout << phi << "\n";

		} else {
			cout << b << "\n";
		}
	}
}
