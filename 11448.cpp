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
const int N = 1430;
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

//	void add(BigInt t) {
//		int c = 0;
//
//		for (int j = 0; j < N; j++) {
//			c += val[j] + t.val[j];
//			val[j] = c % base;
//			c /= base;
//		}
//	}
	void substract(BigInt t){
		long long c=0;
		for (int j=0;j<N;j++){
			c+=t.val[j];
			if (val[j]<c){
				val[j]+=base-c;
				c=1;
			}else{
				val[j]=val[j]-c;
				c=0;
			}
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
	int n;
	cin>>n;
	while (n--){
		string l1,l2;
		cin>>l1>>l2;
		BigInt u(l1);
		BigInt v(l2);
		int c=u.compare(v);
		if (c==-1){
			printf("-");
			v.substract(u);
			v.print();
		}else if(c==0){
			printf("0\n");
		}else {
			u.substract(v);
			u.print();
		}
	}
}

