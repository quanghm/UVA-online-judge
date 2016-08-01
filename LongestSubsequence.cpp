/*
 * LongestSubsequence.cpp
 *
 *  Created on: May 29, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<vector>
using namespace std;

bool compare(int u, int v) {
	return u <= v;
}

int main() {
	vector<int> x;
	int p[], m[];
	int n, i = -1, l = 0, nl;
	int lo, hi, mid;
	while (scanf("%d", &n) != EOF) {
		i++;
		x.push_back(n);
		lo = 1;
		hi = l;

		while (lo <= hi) {
			mid = (lo + hi + 1) / 2;
			if (compare(x[m[mid]], x[i])) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		nl = lo;

		p[i] = m[nl - 1];
		m[nl] = i;

		if (nl > l) {
			l = nl;
		}
	}
	int s[l];
	n = m[l];
	for (int i = l - 1; i >= 0; i--) {
		s[i] = x[n];
		n = p[n];
	}
	printf("%d\n-\n", l);
	for (int i = 0; i < l; i++) {
		printf("%d\n", s[i]);
	}
}

