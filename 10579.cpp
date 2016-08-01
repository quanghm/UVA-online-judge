/*
 * 10579.cpp
 *
 *  Created on: May 13, 2015
 *      Author: quang
 */

#include <iostream>
#include <string>
#include<stdio.h>

using namespace std;
const int N = 150;
const int base = 10000000;
const int log10 = 7;	// log_10(base);
class BigInt {
public:
	int val[N];
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

	BigInt f[5001];
	f[0]=BigInt("0");
	f[1]=BigInt("1");
	for (int i=2;i<5001;i++){
		f[i].add(f[i-1]);
		f[i].add(f[i-2]);
	}
	int n;
	while (cin>>n){
		f[n].print();
	}
}

