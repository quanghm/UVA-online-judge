/*
 * 10608.cpp
 *
 *  Created on: Aug 7, 2015
 *      Author: quang
 */
#include<cstdio>
#include<cstring>
#define N 30001

int main() {
	int k, m, n, p, q, max, t, r;
	int o[N];
	int s[N];
	scanf("%d", &k);
	while (k--) {
		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++) {
			o[i] = i, s[i] = 1;
		}
		max = 0;

		for (int i = 0; i < m; i++) {
			scanf("%d %d", &p, &q);

			if (o[p] != o[q]) {
				t = o[p], r = s[p] + s[q];
				for (int j = 1; j <= n; j++) {
					if (o[j] == t) {
						o[j] = o[q];
						s[j] = r;
					} else if (o[j] == o[q]) {
						s[j] = r;
					}
				}
			}
			if (r > max) {
				max = r;
			}
		}
		printf("%d\n", max);
	}
}

