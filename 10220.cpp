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
const int N = 430;
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

//	int compare(BigInt t) {
//		int c = N - 1;
//		while (c >= 0 && val[c] == t.val[c]) {
//			c--;
//		}
//		if (c < 0) {	//equal
//			return 0;
//		} else if (val[c] > t.val[c]) {
//			return 1;
//		} else {
//			return -1;
//		}
//	}

//	int isZero() {
//		int c = N - 1;
//		while (c >= 0 && val[c] == 0) {
//			c--;
//		}
//		return (c < 0);
//	}

//	void add(BigInt t) {
//		int c = 0;
//
//		for (int j = 0; j < N; j++) {
//			c += val[j] + t.val[j];
//			val[j] = c % base;
//			c /= base;
//		}
//	}

	BigInt mul(int i) {
		BigInt s;
		int c = 0;

		for (int j = 0; j < N; j++) {
			c = c + val[j] * i;
			s.val[j] = c % base;
			c /= base;
		}
		return s;
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
	BigInt f[1001];
	f[0] = BigInt("1");
	for (int i = 1; i < 1001; i++) {
		f[i] = f[i - 1].mul(i);
	}
	int n, s,d;
	while (scanf("%d", &n) != EOF) {
		s = 0;
		for (int i = 0; i < N; i++) {
			d=f[n].val[i];
			while(d){
				s+=d%10;
				d/=10;
			}
		}
		printf("%d\n", s);
	}
}

