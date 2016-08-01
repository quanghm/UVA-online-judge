/*
 * 713.cpp
 *
 *  Created on: May 13, 2015
 *      Author: quanghoang
 */

#include <iostream>
#include <string>
#include<stdio.h>

using namespace std;
const int N = 202;
const int base = 10;
const int log10 = 1;	// log_10(base);
class BigInt {
public:
	int val[N];
	BigInt() :
			val() {
	}
	BigInt(string v) :
			val() {
		int l = v.length();
		for (int i =0;i<l;i++){
			val[i]=v[i]-48;
		}
//		int j = 0, d = 0;
//		for (int c = 0; c < l; c += log10) {
//			d = 1;
//			for (int i = 0; i < log10 && i < l - c; i++) {// read string from left to right
//				val[j] += d * (v[c + i] - 48);
//				d *= 10;
//			}
//			j++;
//		}
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
		//j : left most non-zero digit
		if (j < 0) {
			cout << "0\n";
			return;
		}
		int i = 0;
		while (!val[i]) {
			i++;
		}// right most non-zero digit
		while (i<=j){
			printf("%d", val[i]);
			i++;
		}
		cout << "\n";
	}
};
int main() {

	int n;
	cin >> n;
	string s1, s2;
	BigInt u, v;
	while (n--) {
		cin >> s1 >> s2;
		v=BigInt(s2);
		u = BigInt(s1);
		u.add(v);
		u.print();
	}
}

