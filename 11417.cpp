/*
 * 11417.cpp
 *
 *  Created on: May 27, 2015
 *      Author: quanghoang
 */
#include<cstdio>
using namespace std;
int gcd(int n, int m) {
	if (n) {
		return gcd(m % n, n);
	} else {
		return m;
	}
}
int main() {
	int g[501];
	g[2] = 1;
	for (int i = 3; i < 501; i++) {
		g[i]=g[i-1];
		for (int j=1;j<i;j++){
			g[i]+=gcd(j,i);
		}
	}
	int n;
	while (scanf("%d",&n)&&n){
		printf("%d\n",g[n]);
	}
}

