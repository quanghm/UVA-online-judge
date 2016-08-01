/*
 * 10810.cpp
 *
 *  Created on: Aug 7, 2015
 *      Author: quang
 */
#include<cstdio>
using namespace std;

#define N 500000
//int v[2][N] = { };
int v[N] = { };
int u[N] = { };

int mergeSortCount(int s, int e) {

	if (e == s + 1) { //no sorting
		return 0;
	}

	int m = (s + e) / 2;
	int re = mergeSortCount(s, m) + mergeSortCount(m, e);	// sort two halves

	// merge to buffer
	int l = s, r = m, j = s;
	for (j = s; l < m && r < e; j++) {// while there are numbers on left and right
		if (v[r] < v[l]) {
			u[j] = v[r];
			re += m - l;
			r++;
		} else {
			u[j] = v[l];
			l++;
		}
	}

	while (r < e) {	//put the rest of right numbers
		u[j++] = v[r++];
	}
	while (l < m) {
		u[j++] = v[l++];
	}

	for (int j=s;j<e;j++){
		v[j]=u[j];
	}
	return re;
}

int main() {
	int n;
	while ((scanf("%d", &n) != EOF)&&n) {
		for (int j = 0; j < n; j++) {
			scanf("%d", v+j);
			//printf("%d ", v[0][j]);
		}
		printf("%d\n", mergeSortCount(0, n));
	}
}



