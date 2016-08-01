/*
 * 11161.cpp
 *
 *  Created on: May 25, 2015
 *      Author: quang
 */
#include <iostream>
#include <string>
#include<stdio.h>

using namespace std;
const int N = 46;
const int base = 10000000;
const int logbase = 7;	// log_10(base);
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
//	BigInt(int v[N]) {
//		for (int i = 0; i < N; i++) {
//			val[i] = v[i];
//		}
//	}
	BigInt():val(){
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
			printf("%0*d", logbase, val[j]);
		}
		cout << "\n";
	}
};
int main() {

	BigInt f[1505];
	f[1]=BigInt("1");
//	f[2]=BigInt("1");
	for (int i=2;i<1505;i++){
		f[i].add(f[i-1]);
		f[i].add(f[i-2]);
	}
	int n;
	int c=0;
	while (cin>>n&&n){
		printf("Set %d:\n",++c);
		BigInt result;


		result.add(f[n+3]);
//		result.print();
		//substract 3
		int carry=3;
		int i=0;
		while (carry&&i<N){
			if (result.val[i]<carry){
				result.val[i]+=base-carry;
				carry=1;
			}else{
				result.val[i]-=carry;
				carry=0;
			}
			i++;
		}

		// divide 2
		carry=0;
		i=N;
		while(i--){
			if (carry){
				result.val[i]+=base;
			}
			carry=result.val[i]%2;
			result.val[i]/=2;
		}
		result.print();
	}
}



