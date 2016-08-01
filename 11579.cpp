/*
 * 11579.cpp
 *
 *  Created on: Jun 12, 2015
 *      Author: quang
 */
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);

		vector<double> e(n);

		for (int i = 0; i < n; i++) {
			scanf("%lf", &(e[i]));
		}
		sort(e.begin(), e.end());
		double max = 0, p, s;
		for (int i = 0; i < n - 2; i++) {
			p = (e[i] + e[i + 1] + e[i + 2]) / 2;
			if (p > e[i] && p > e[i + 1] && p > e[i + 2]) {
				s = sqrt(p * (p - e[i]) * (p - e[i + 1]) * (p - e[i + 2]));
				if (max < s) {
					max = s;
				}
			}
		}
		printf("%.2lf\n",max);
	}
}
