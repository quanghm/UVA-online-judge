/*
 * 11173.cpp
 *
 *  Created on: May 27, 2015
 *      Author: qhoang
 */
#include<cstdio>
using namespace std;
int p[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192,
		16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304,
		8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912,
		1073741824};

int greycode(int n, int k) {

	if (k < 2) {
		return k;
	}

	if (k >= p[n - 1]) {
		k = p[n] - k - 1;
		return p[n - 1] + greycode(n - 1, k);
	}else{
		return greycode(n-1,k);
	}
}
int main() {
	int N, n, k;
	scanf("%d", &N);

	while (N--) {
		scanf("%d%d", &n, &k);

		printf("%d\n", greycode(n, k));
	}
}

