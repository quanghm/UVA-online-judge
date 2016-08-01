/*
 * 10229.cpp
 *
 *  Created on: May 18, 2015
 *      Author: quanghoang
 */
#include<cstdio>

using namespace std;
const int power = 524288;
int main() {
	int n, m;
	int f[1000000];
	int p[20] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192,
			16384, 32768, 65536, 131072, 262144, 524288 };
	f[0] = 0;
	f[1] = 1;
	f[2] = 1;
	int i = 1;
	while ((f[i] != 0 || f[i + 1] != 1) && i < 1000000 - 2) {
		f[i + 2] = (f[i + 1] + f[i]) % power;
		i++;
	}

	while (scanf("%d%d", &n, &m) != EOF) {
		printf("%d\n", f[n % i] % p[m]);
	}
}

