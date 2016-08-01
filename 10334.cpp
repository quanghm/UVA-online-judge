/*
 * 10334.cpp
 *
 *  Created on: May 26, 2015
 *      Author: quanghoang
 */
#include <string>
#include<cstdio>

using namespace std;
const int N = 32;
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

	f[0]=BigInt("1");
	f[1]=BigInt("2");
	for (int i=2;i<1001;i++){
		f[i].add(f[i-1]);
		f[i].add(f[i-2]);
	}
	int n;
	while (scanf("%d",&n)!=EOF){
		//printf("The Fibonacci number for %d is ",n);
		f[n].print();
	}
}



