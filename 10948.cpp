/*
 * 10948.cpp
 *
 *  Created on: May 22, 2015
 *      Author: quanghoang
 */
#include<cstdio>
using namespace std;
const int M = 1000000;
int main() {
	int N = 1000;
	bool p[M] = { };
	bool flag;

	for (int i = 2; i < N; i++) {
		if (!p[i]) {
			for (int j = i * i; j < M; j += i) {
				p[j] = 1;
			}
		}
	}

	while (scanf("%d", &N) != EOF && N) {
		flag = true;
		printf("%d:\n", N);
		if (N % 2||N==4) {
			if (p[N - 2]) {
				printf("NO WAY!\n");
			} else {
				printf("2+%d\n", N - 2);
			}
		} else {
			for (int i = 3; i <= N / 2; i++) {
				if (!p[i] && !p[N - i]) {
					printf("%d+%d\n", i, N - i);
					break;
				}
			}
		}
	}
}
