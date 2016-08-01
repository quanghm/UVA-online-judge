/*
 * 11554.cpp
 *
 *  Created on: May 25, 2015
 *      Author: quang
 */
#include<cstdio>
using namespace std;

int main() {
	unsigned long long a[1000001] = { };
	for (long long k = 1; k < 500000; k++) {
		a[2 * k + 1] = a[2 * k] + k * (k - 1);
		a[2 * k + 2] = a[2 * k + 1] + k * k;
	}
	int n;
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%lld\n", a[n]);
	}
}

