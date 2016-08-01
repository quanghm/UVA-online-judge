/*
 * uva160.cpp
 *
 *  Created on: May 4, 2015
 *      Author: quanghoang
 */

#include<iostream>

using namespace std;

int factor(int n, int p) {
	int s = 0, pow = p;
	while (pow <= n) {
		s += n / pow;
		pow *= p;
	}
	return s;
}

void print(int i) {
	//right align
	if (i < 10) {
		cout << "  ";
	} else if (i < 100) {
		cout << " ";
	}
	cout << i;
}

int main() {
	int n, i;
	int primes[26] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53,
			59, 61, 67, 71, 73, 79, 83, 89, 97 ,101};
	while ((cin >> n) && (n)) {
		//print n! =
		print(n);
		cout << "! =";
		i = 0;
		while (primes[i] <= n) {
			if (i == 15) {
				cout << endl << "      ";
			}
			print(factor(n, primes[i++]));
		}
		cout << endl;
	}

}

