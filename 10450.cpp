/*
 * 10450.cpp
 *
 *  Created on: May 26, 2015
 *      Author: quanghoang
 */

#include <string>
#include<cstdio>

using namespace std;

int main() {

	long long f[52];
	f[0] = 0;
	f[1] = 2;
	f[2] = 3;
	for (int i = 3; i < 52; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	int n;

	int m;
	scanf("%d", &m);

	for (int c = 1; c <= m; c++) {
		scanf("%d", &n);
		printf("Scenario #%d:\n", c);
		printf("%lld\n\n",f[n]);
//		if(c!=m){printf("\n");}
	}
}

