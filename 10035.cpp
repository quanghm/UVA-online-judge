/*
 * uva10035.cpp
 *
 *  Created on: Apr 30, 2015
 *      Author: quang
 */
#include<iostream>

using namespace std;
long int m = 1, n = 1;
int co, t;
int u1, u2;
int main() {
	while ((cin >> m >> n) && ((m) || (n))) {
		co = 0;
		t = 0;
		while (m > 0 || n > 0) {
			if (m % 10 + n % 10 + t > 9) {
				co++;
				t = 1;
			} else {
				t = 0;
			}
			m /= 10;
			n /= 10;
		}
		switch (co) {
		case 0:
			cout << "No carry operation." << endl;
			break;
		case 1:
			cout << "1 carry operation." << endl;
			break;
		default:
			cout << co << " carry operations." << endl;
		}
	}
	return 0;
}
