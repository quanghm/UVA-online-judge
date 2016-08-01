/*
 * 10323.cpp
 *
 *  Created on: May 20, 2015
 *      Author: quang
 */
#include<iostream>
using namespace std;
int main() {
	long long n;
	long long s;
	long long fact[6];
	fact[0] = 5040;
	for (int i = 0; i < 6; i++) {
		fact[i + 1] = fact[i] * (i + 8);
	}
	while (cin >> n) {
		if (n < 0) {
			if (n % 2) {
				cout << "Overflow!\n";
			} else {
				cout << "Underflow!\n";
			}
		} else if (n < 8) {
			cout << "Underflow!\n";
		} else if (n > 13) {
			cout << "Overflow!\n";
		} else {
			cout << fact[n - 7] << "\n";
		}
	}

}

