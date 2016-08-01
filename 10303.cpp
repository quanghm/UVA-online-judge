/*
 * 10303.cpp
 *
 *  Created on: Jun 3, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<string>
using namespace std;
const int M = 1001;
const int N = 121;
const int base = 100000;
const int logbase = 5;	// log_10(base);
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
	BigInt(int i) :
			val() {
		val[0] = i;
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

	void add(BigInt t) {
		int c = 0;

		for (int j = 0; j < N; j++) {
			c += val[j] + t.val[j];
			val[j] = c % base;
			c /= base;
		}
	}
	void div(int i) {
		int c = 0, j = N;
		while (j--) {
			c = c * base + val[j];
			val[j] = c / i;
			c %= i;
		}
	}

	void mul(int i) {
//		BigInt s;
		long long c = 0;

		for (int j = 0; j < N; j++) {
			c = c + val[j] * i;
			val[j] = c % base;
			c /= base;
		}
//		return s;
	}
//	BigInt mul(BigInt v) {
//		BigInt s, t;
//		int c = N - 1;
//		while (!v.val[c]) {
//			c--;
//		}	//first non-zero digit.
//		if (c < 0) {
//			return s;
//		}
//		s = mul(v.val[c--]); //multiplied first digit
//		while (c >= 0) {
//			s.mulBase();
//			t = mul(v.val[c--]);
//			s.add(t);
//		}
//		return s;
//	}

	void mulBase() { //multiply by base - shift
		int c = N - 1;
		while (c) {
			val[c] = val[c - 1];
			c--;
		}
		val[0] = 0;
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
	BigInt h[M];
	int n;
	h[0] = BigInt(1);
	for (int i = 1; i < M; i++) {
		h[i].add(h[i - 1]);
		h[i].mul(4 * i - 2);
		h[i].div(i + 1);
//		for (int j = 0; j < i; j++) {
//			h[i].add(h[j].mul(h[i - j - 1]));
//		}
//		printf("%d:", i);
//		h[i].print();
//		if (h[i] > 0) {
//		} else {
//			break;
//		}
	}
	while (scanf("%d",&n)!=EOF){
		h[n].print();
	}

}

