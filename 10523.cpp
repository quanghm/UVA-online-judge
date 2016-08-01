/*
 * 10523.cpp
 *
 *  Created on: Jun 3, 2015
 *      Author: qhoang
 */

#include <string>
#include<cstdio>
#include<iostream>

using namespace std;
const int N = 31;
const int base = 1000000;
const int logbase = 6;	// log_10(base);
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

	void mul(int i) {
//		BigInt s;
		long long c = 0;

		for (int j = 0; j < N; j++) {
			c = c  + val[j] * i;
			val[j] = c % base;
			c /= base;
		}
	}

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
			printf("0\n");
			return;
		}
		printf("%d", val[j]); //print first digit;
		while (j--) {	//print remaining digits;
			printf("%0*d", logbase, val[j]);
		}
		printf("\n");
	}
};
int main() {
	int n, a;
	string line;
	while (scanf("%d%d", &n, &a) != EOF) {
		if (a == 0) {
			printf("0\n");
		} else if (a == 1) {
			printf("%d\n", n * (n + 1) / 2);
		} else {
			BigInt u("1");

			// a^{n+1}
			for (int i = 0; i <= n; i++) {
				u.mul(a);
			}

			u.mul(a * n - n - 1);

			// add a;
			int c = a;
			for (int i = 0; i < N; i++) {
				c += u.val[i];
				u.val[i] = c % base;
				c /= base;
			}
			// divide (a-1)^2
			u.div((a-1)*(a-1));

			//print;
			u.print();
		}
	}
}

