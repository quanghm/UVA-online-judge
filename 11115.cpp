/*
 * 11115.cpp
 *
 *  Created on: May 25, 2015
 *      Author: quang
 */
#include<cstdio>
#include<math.h>
#include<string>
using namespace std;

const int N = 4;
const int base = 10000000;
const int logN = 7;	// log_10(base);
class BigInt {
public:
	long long val[N];
	BigInt(string v) {
		int l = v.length() - 1;
		int c = 0;
		while (c <= l) {
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

	void print() {
		int j = N - 1;
		while (!val[j]) {
			j--;
		}
		if (j < 0) {
			printf("0\n");
			return;
		}
		printf("%lld", val[j]); //print first digit;

		while (j--) {	//print remaining digits;
			printf("%0*lld", logN, val[j]);
		}
		printf("\n");
	}
};

int main() {
	BigInt a[11][26];

	for (int i = 0; i < 11; i++) {
		a[i][0] = BigInt("1");
		for (int j = 1; j < 26; j++) {
			a[i][j] = a[i][j - 1].mul(i);
		}
	}

	int n, d;
	double s;
	while (scanf("%d%d", &n, &d) && n) {
		a[n][d].print();
	}
}
