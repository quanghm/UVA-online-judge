/*
 * 10810.cpp
 *
 *  Created on: Aug 7, 2015
 *      Author: quang
 */
#include<cstdio>
using namespace std;

#define N 500000
//long long v[2][N] = { };
long long v[N] = { };
long long u[N] = { };

long long mergeSortCount(long long s, long long e) {

	if (e == s + 1) { //no sorting
		return 0;
	}

	long long m = (s + e) / 2;
	long long re = mergeSortCount(s, m) + mergeSortCount(m, e);	// sort two halves

	// merge to buffer
	long long l = s, r = m, j = s;
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

	for (long long j=s;j<e;j++){
		v[j]=u[j];
	}
	return re;
}

int main() {
	long long n;
	while ((scanf("%lld", &n) != EOF)&&n) {
		for (long long j = 0; j < n; j++) {
			scanf("%lld", v+j);
			//prlong longf("%d ", v[0][j]);
		}
		printf("%lld\n", mergeSortCount(0, n));
	}
}



