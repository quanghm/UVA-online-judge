/*
 * 10780.cpp
 *
 *  Created on: May 24, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53,
			59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127,
			131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193,
			197, 199, 211, 223 };
	int m, n, c, t, s, r, u;
	bool flag;

	scanf("%d", &c);

	for (int t = 1; t <= c; t++) {
		scanf("%d%d", &m, &n);
		priority_queue<int, vector<int>, greater<int> > power;
		flag = false;
		for (int i = 0; i < 48 && primes[i] <= m; i++) {
			if (m % primes[i] == 0) {
//				printf("%d:::%d\n", i, primes[i]);
				s = 0, r = n, u = 0;
				while (m % primes[i] == 0) {
					s++;
					m /= primes[i];
				}
//				printf(":%d:",s);
				while (r) {
					r /= primes[i];
					u += r;
				}
				if (s > u) {
					flag = true;
					break;
				} else {
					u /= s;
					power.push(u);
				}
			}

		}
		if (m > 1) {
			u = 0;
			while (n) {
				n /= m;
				u += n;
			}
			if (1 > u) {
				flag = true;
			} else {
				power.push(u);
			}
		}
		if (flag) {
			printf("Case %d:\nImpossible to divide\n",t);
		} else {
			printf("Case %d:\n%d\n",t, power.top());
		}
	}
}

