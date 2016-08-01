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
const int N = 17;
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
	int isZero() {
		int c = N - 1;
		while (c >= 0 && val[c] == 0) {
			c--;
		}
		return (c < 0);
	}

	void add(BigInt t) {
		int c = 0;

		for (int j = 0; j < N; j++) {
			c += val[j] + t.val[j];
			val[j] = c % base;
			c /= base;
		}
	}

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
	BigInt f[501];
	f[1] = BigInt("1");
	f[2] = BigInt("2");
	for (int i = 3; i < 501; i++) {
		f[i].add(f[i - 1]);
		f[i].add(f[i - 2]);
	}
	string s1, s2;
	while (cin >> s1 >> s2) {
		BigInt u(s2);
		if (u.isZero()) {
			return 0;
		} else {
			BigInt v(s1);
			int i = 1;
			while (f[i].compare(v) < 0) {
				i++;
			}
			int j = i;
			while (f[j].compare(u) <= 0) {
				j++;
			}
			printf("%d\n", j - i);
		}
	}
}

