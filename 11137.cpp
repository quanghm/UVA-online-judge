/*
 * 11137.cpp
 *
 *  Created on: Jun 10, 2015
 *      Author: quanghoang
 */
#include<cstdio>
using namespace std;
const int N = 10000;
int main() {
	int n, c, d;
	int cube[22];
	for (int i = 0; i < 22; i++) {
		cube[i] = i * i * i;
	}
	long long f[N] = { };
	f[0] = 1;
	for (int i = 1; i < 22; i++) {
		for (int j = cube[i]; j < N; j++) {
			f[j] += f[j - cube[i]];
		}
	}
	while (scanf("%d", &n) != EOF) {
		printf("%lld\n", f[n]);
	}
}

