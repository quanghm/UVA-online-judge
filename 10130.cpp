/*
 * 10130.cpp
 *
 *  Created on: Jun 15, 2015
 *      Author: qhoang
 */
#include<cstdio>
using namespace std;

int main() {
	int t, n, g, temp;
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		int s = 0;
		int w[1001] = { };
		int v[1001] = { };
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &v[i], &w[i]);
		}
		int a[1001][31] = { };
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 31; j++) {
				if (j >= w[i]) {
					a[i][j] =
							(a[i - 1][j] > a[i - 1][j - w[i]] + v[i]) ?
									a[i - 1][j] : a[i - 1][j - w[i]]+ v[i];
				} else {
					a[i][j] = a[i - 1][j];
				}
			}
		}
		scanf("%d", &g);
		while (g--){
			scanf("%d",&temp);
			s+=a[n][temp];
		}
		printf("%d\n",s);
	}
}

