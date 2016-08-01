/*
 * uva10235.cpp
 *
 *  Created on: May 11, 2015
 *      Author: quang
 */
#include <iostream>

using namespace std;

int main() {
	const int m = 1000000;
	int n = 1001,s;
	bool a[m] = { }; // if i is check
	int i = 1;
	while (i++ < n) {
		while (a[i] && (i < n)) {
			i++;
		}
		for (int j = i * i; j < m; j += i) { // kill multiple of i
			a[j] = true;
		}
	}
	while (cin >> n) {
		if (a[n]) {
			cout << n << " is not prime.\n";
		} else { // n is a prime
			s=n;
			cout<< n;
			i = 0;
			while (n) {
				//reversing;
				i *= 10;
				i += n % 10;
				n /= 10;
			}
			if (a[i]||s==i){
				cout<<" is prime.\n";
			}else{
				cout<<" is emirp.\n";
			}
		}
	}
}
