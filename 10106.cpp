/*
 * uva10106.cpp
 *
 *  Created on: May 11, 2015
 *      Author: quang
 */
#include <iostream>
#include <string>
#include<cstring>
#include<stdio.h>

using namespace std;

const int N = 75;
const int base = 10000000;
const int logbase = 7;	// log_10(base);
class BigInt {
public:
	long long val[N];
	BigInt(string v) :
			val() {
		memset(val,0,N*sizeof(long long));
		int l = v.length();
		long long c = 0, s = 0;
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
//	BigInt(long v[N]) {
//		for (int i = 0; i < N; i++) {
//			val[i] = v[i];
//		}
//	}
	BigInt() :
			val() {
	}

	void add(BigInt t) {
		long long c = 0;

		for (int j = 0; j < N; j++) {
			c += val[j] + t.val[j];
			val[j] = c % base;
			c /= base;
		}
	}

	void mulBase() { //multiply by base - unshift
		int c = N - 1;
		while (c) {
			val[c] = val[c - 1];
			c--;
		}
		val[0] = 0;
	}

	void divBase() { //divide by base - shift
		int c = 0;
		while (c < N - 1) {
			val[c] = val[c + 1];
			c++;
		}
		val[c] = 0;
	}

//	void clone(BigInt v) {
//		for (int i = 0; i < N; i++) {
//			val[i] = v.val[i];
//		}
//	}

	BigInt mul(int i) {
		BigInt r;
		long long s = 0;
		for (int j = 0; j < N; j++) {
			s += val[j] * i;
			r.val[j] = s % base;
			s /= base;
		}
		return r;
	}

	BigInt mul(BigInt v) {
		BigInt s, t;
		int c = N;
		while (c--) {
			if (v.val[c]) break;
		}	//first non-zero digit.
		if (c < 0) {
//			printf("0000\n");
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
		int j = N;
		while (j--) {
			if (val[j]) break;
		}
		if (j < 0) {
			cout << "0\n";
			return;
		}
		printf("%lld", val[j]); //print first digit;multiply
		while (j--) {	//print remaining digits;
			printf("%0*lld", logbase, val[j]);
		}
		cout << "\n";
	}
};
int main() {
	string s;
	BigInt p;
	while (cin >> s) {
		p = BigInt(s);
		cin >> s;
		p.mul(BigInt(s)).print();
	}
}
