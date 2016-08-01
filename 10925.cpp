/*
 * 10183.cpp
 *
 *  Created on: May 26, 2015
 *      Author: quanghoang
 */

#include <string>
#include<cstdio>
#include<iostream>

using namespace std;
const int N = 4;
const int base = 10000000;
const int logbase = 7;	// log_10(base);
class BigInt {
public:
	int val[N];
	BigInt(string v) :
			val() {
		int l = v.length();
		int c = 0, s = 0;
		int u = 1;
		while (l--) {
			//t = log10;
			val[s] += (v[l] - 48) * u;
			c++;
			if (c % logbase) {
				u *= 10;
			} else {
				u = 1;
				s++;
			}
		}
	}

	BigInt() :
			val() {
	}

	int compare(BigInt t) {
		int c = N - 1;
		while (c >= 0 && val[c] == t.val[c]) {
			c--;
		}
		if (c < 0) {	//equal
			return 0;
		} else if (val[c] > t.val[c]) {
			return 1;
		} else {
			return -1;
		}
	}
//	int isZero() {
//		int c = N - 1;
//		while (c >= 0 && val[c] == 0) {
//			c--;
//		}
//		return (c < 0);
//	}

	void add(BigInt t) {
		int c = 0;

		for (int j = 0; j < N; j++) {
			c += val[j] + t.val[j];
			val[j] = c % base;
			c /= base;
		}
	}
	void div(int n) {
		int c = 0;

		for (int j = N - 1; j >= 0; j--) {
			c = c * base + val[j];
			val[j] = c / n;
			c %= n;
		}
	}
//	void substract(BigInt t) {
//		long long c = 0;
//		for (int j = 0; j < N; j++) {
//			c += t.val[j];
//			if (val[j] < c) {
//				val[j] += base - c;
//				c = 1;
//			} else {
//				val[j] = val[j] - c;
//				c = 0;
//			}
//		}
//	}

	void print() {
		int j = N - 1;
		while (!val[j]) {
			j--;
		}
		if (j < 0) {
			printf("0");
			return;
		}
		printf("%d", val[j]); //print first digit;
		while (j--) {	//print remaining digits;
			printf("%0*d", logbase, val[j]);
		}
//		printf("\n");
	}
};
int main() {
	int n, f, c = 1;
	string line;
	while (cin >> n >> f && n) {
		BigInt s=BigInt("0");
		getline(cin, line);
		printf("Bill #%d costs ", c++);
		while (n--) {
			getline(cin, line);
			s.add(BigInt(line));
		}
		s.print();
		printf(": each friend should pay ");
		s.div(f);
		s.print();
		printf("\n\n");
	}
}

