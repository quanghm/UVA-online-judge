/*
 * 116.cpp
 *
 *  Created on: Jun 9, 2015
 *      Author: quang
 */
#include<cstdio>
#include<stack>
using namespace std;

int main() {
	int n, m;
	while (scanf("%d%d", &m, &n) != EOF) {
		int a[12][101] = { };
		int s[12][101] = { };
		int p[12][101] = { };
		int min = 0, r;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &a[i][j]);
//				printf("%3d",a[i][j]);
			}
//			printf("\n");
			s[i][n] = a[i][n];
		}
//		printf("***\n");
//		for (int j = 1; j <= n; j++) {
//			a[0][j] = a[m][j];
//			a[m + 1][j] = a[1][j];
//		}
		for (int j = n-1; j>=1; j--) {
			for (int i = 1; i <= m; i++) {

				min = s[i][j + 1];
				p[i][j] = i;
				r = (i - 1) ? i - 1 : m;
				if (min > s[r][j + 1]) {
					min = s[r][j + 1];
					p[i][j] = r;
				} else if (min == s[r][j + 1]) {
					p[i][j] = (r < p[i][j]) ? r : p[i][j];
				}
				r = (i == m) ? 1 : i + 1;
				if (min > s[r][j + 1]) {
					min = s[r][j + 1];
					p[i][j] = r;
				} else if (min == s[r][j + 1]) {
					p[i][j] = (r < p[i][j]) ? r : p[i][j];
				}
				s[i][j] = min + a[i][j];
			}
		}
//		for (int i = 1; i <= m; i++) {
//			for (int j = 1; j <= n; j++) {
//				printf("%3d", s[i][j]);
//			}
//			printf("\n");
//		}
		min = s[1][1];
		r = 1;
		for (int i = 2; i <= m; i++) {
			if (min > s[i][1]) {
				min = s[i][1];
				r = i;
			}
		}
		printf("%d",r);
		r=p[r][1];
		for (int j=2;j<=n;j++){
			printf(" %d",r);
			r=p[r][j];
		}
		printf("\n%d\n",min);
//		stack<int> path;
//		for (int j = n; j; j--) {
//			path.push(r);
//			r = p[r][j];
//		}
//		while (1) {
//			printf("%d", path.top());
//			path.pop();
//			if (path.empty()) {
//				printf("\n");
//				break;
//			} else {
//				printf(" ");
//			}
//		}
//		printf("%d\n", min);
	}
}

