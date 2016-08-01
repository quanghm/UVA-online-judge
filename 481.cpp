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
	return u < v;
}

const int N = 100;
int main() {
	vector<int> x;
	int n, i = -1, l = 0, nl;
	int lo, hi, mid;
	while (scanf("%d", &n) != EOF) {
		i++;
		x.push_back(n);
	}
	vector<int>p(i);
	vector<int>m(i);

	for (int j = 0; j < i; j++) {
		lo = 1;
		hi = l;

		while (lo <= hi) {
			mid = (lo + hi + 1) / 2;
			if (compare(x[m[mid]], x[j])) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		nl = lo;

		p[j] = m[nl - 1];
		m[nl] = j;

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
