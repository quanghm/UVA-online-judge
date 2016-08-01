/*
 * 562.cpp
 *
 *  Created on: May 20, 2015
 *      Author: quanghoang
 */
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int min(int a, int b) {
	return ((a > b) ? b : a);
}

int main() {
	int n, m, l, s;
	scanf("%d", &n);

	while (n--) {

		s = 0;
		scanf("%d", &m);

		if (m > 1) {
			vector<int> a;
			for (int i = 0; i < m; i++) {
				scanf("%d", &l);
				s += l;
				a.push_back(l);
			}

			l = s / 2;

			//sort(a.begin(),a.end());

			vector<vector<int> > r(s + 1, vector<int>(m)); // r[j][i]=min (j- (sum of subset of a[0],...,a[i]))

			for (int j = 0; j <= l; j++) {
				vector<int> row;
				row.resize(m);
				r.push_back(row);
				r[j][0] = (a[0] > j) ? a[0] : j - a[0];
			}

			for (int i = 1; i < m; i++) {
				for (int j = 0; j <= l; j++) {
					if (a[i] > j) {
						r[j][i] = r[j][i - 1];
					} else {
						r[j][i] = min(min(r[j][i - 1], r[j - a[i]][i - 1]),
								j - a[i]);
					}
				}
			}
//			for (int i = 0; i < m; i++) {
//				for (int j = 0; j <= l; j++) {
//					printf("%d ", r[j][i]);
//				}
//				printf("\n");
//			}
			printf("%d\n", s % 2 + 2 * r[l][m - 1]);
		} else
			if (m == 1) {
				scanf("%d", &l);
				printf("%d\n", l);
			} else {
				printf("0\n");
		}

	}
}

