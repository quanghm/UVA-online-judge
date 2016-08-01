/*
 * uva324.cpp
 *
 *  Created on: May 12, 2015
 *      Author: qhoang
 */

#include <iostream>
#include <string>
#include<stdio.h>

using namespace std;
const int N = 782;
const int base = 10;
const int log10 = 1;	// log_10(base);
class BigInt {
public:
	int val[N];
	BigInt(string v) {
		int l = v.length() - 1;
		int c = 0;
		while (c <= l) {
			//t = log10;
			val[c] = v[l - c] - 48;
			c++;
		}
		while (c < N) {
			val[c++] = 0;
		}
	}
	BigInt(int v[N]) {
		for (int i = 0; i < N; i++) {
			val[i] = v[i];
		}
	}
	BigInt() :
			val() {
	}

	void add(BigInt t) {
		int c = 0;

		for (int j = 0; j < N; j++) {
			c += val[j] + t.val[j];
			val[j] = c % base;
			c /= base;
		}
	}

	void mulBase() { //multiply by base - shift
		int c = N - 1;
		while (c) {
			val[c] = val[c - 1];
			c--;
		}
		val[0] = 0;
	}
	void divBase() { //multiply by base - shift
		int c = 0;
		while (c < N - 1) {
			val[c++] = val[c];
		}
		val[c] = 0;
	}

	int modBase() {
		return val[0];
	}

	void clone(BigInt v) {
		for (int i = 0; i < N; i++) {
			val[i] = v.val[i];
		}
	}

	BigInt mul(int i) {
		BigInt r;
		int s = 0;
		for (int j = 0; j < N; j++) {
			s += val[j] * i;
			r.val[j] = s % base;
			s /= base;
		}
		return r;
	}

	BigInt mul(BigInt v) {
		BigInt s, t;
		int c = N - 1;
		while (!v.val[c]) {
			c--;
		}	//first non-zero digit.
		if (c < 0) {
			return s;
		}
		s = mul(v.val[c--]); //multiplied first digit
		while (c >= 0) {
			s.mulBase();
			t = mul(v.val[c--]);
			s.add(t);
		}
		return s;
	}

	void print() {
		int j = N - 1;
		while (!val[j]) {
			j--;
		}
		if (j < 0) {
			cout << "0\n";
			return;
		}
		printf("%d", val[j]); //print first digit;
		while (j--) {	//print remaining digits;
			printf("%0*d", log10, val[j]);
		}
		cout << "\n";
	}
};
int main() {
	BigInt f[367];
	f[0] = BigInt("1");


	for (int i = 1; i < 367; i++) {
		f[i] = f[i - 1].mul(i);
	}
	int n, j;
	while ((cin >> n) && n) {
		int j = N - 1;
		while (!f[n].val[j]) {
			j--;
		}	// first non-zero digit;
		int r[10] = { };
		while (j>-1) {
			r[f[n].val[j--]]++;
		}
		cout << n << "! --\n";

		printf("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n", r[0],
				r[1], r[2], r[3], r[4]);
		printf("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n", r[5],
				r[6], r[7], r[8], r[9]);
	}
}

