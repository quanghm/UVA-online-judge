/*
 * uva623.cpp
 *
 *  Created on: May 11, 2015
 *      Author: quang
 */
#include <iostream>
#include <string>
#include<stdio.h>

using namespace std;
const int N = 400;
const int base = 10000000;
const int log10 = 7;	// log_10(base);
class BigInt {
public:
	long val[N];
	BigInt(string v){
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
		for (int i =0; i<N; i++) {
			val[i] = v.val[i];
		}
	}

	BigInt mul(int i) {
		BigInt r;
		long s = 0;
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
		printf("%ld", val[j]); //print first digit;
		while (j--) {	//print remaining digits;
			printf("%0*ld", log10, val[j]);
		}
		cout << "\n";
	}
};

int main(){
	BigInt f[1001];
	f[0]=BigInt("1");
	f[1]=BigInt("1");
	for (int i=1;i<1001;i++){
		f[i]=f[i-1].mul(i);
	}
	int n;
	while (cin>>n){
		printf("%d!\n",n);
		f[n].print();
	}
}
