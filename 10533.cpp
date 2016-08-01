/*
 * 10533.cpp
 *
 *  Created on: May 29, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<cstring>
using namespace std;

const int M= 1000001;
int main() {
	bool p[M];
	memset(p, true, M);
	p[1] = 0;
	for (int i = 2; i < 1000; i++) {
		if (p[i]) {
			for (int j = i * i; j < M; j += i) {
				p[j] = 0;
			}
		}
	}
	int t, n, m;
	int x[M] = { };
//	x[1] = 0;
//	x[2]=1;
	for (int i = 2; i < M; i++) {
		if (p[i]) {
			n = i;
			t = 0;
			while (n) {
				t += n % 10;
				n /= 10;
			}
			if (p[t]) {
				x[i] = x[i - 1] + 1;
			} else {
				x[i] = x[i - 1];
			}
		}else{
			x[i]=x[i-1];
		}
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &m, &n);
		printf("%d\n", x[n] - x[m - 1]);
	}
}
