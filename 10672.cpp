/*
 * 10672.cpp
 *
 *  Created on: Jun 15, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<queue>
using namespace std;

const int N = 10001;
int main() {
	int n, v, d, c;
	while (scanf("%d", &n) != EOF && n) {
		int m[N] = { };
		int p[N] = { };
		int nc[N] = { };
		int s = 0;
		queue<int> l;

		for (int i = 1; i <= n; i++) {
			scanf("%d %d %d", &v, m + i, &d);
			nc[i] = d;
			if (d == 0) { // this is a leaf
				l.push(v);
			} else
				for (int j = 0; j < d; j++) {
					scanf("%d", &c);
					p[c] = v;
				}
		}
		v = l.front();
		while (p[v]) {
			c = m[v] - 1;
			if (m[v] > 1) {
				s += c;
				m[p[v]] += c;
			} else {
				s -= c;
				m[p[v]] += c;
			}
			nc[p[v]]--;
			if (nc[p[v]] == 0) {
				l.push(p[v]);
			}
			l.pop();
			v = l.front();
		}
		printf("%d\n", s);
	}
}

